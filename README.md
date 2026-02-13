import csv
import numpy as np
import os
from dataclasses import dataclass
from typing import List, Optional
import re

@dataclass
class FrameData:
    """Dados de um único frame"""
    numero_frame: int
    tempo_ms: Optional[float]  # tempo em milissegundos (se disponível)
    matriz_pressao: np.ndarray
    forca_total: float

def parse_tekscan_multiframe(caminho_arquivo, area_sensel_m2=None):
    """
    Parser para arquivos CSV da Tekscan com múltiplos frames
    
    Retorna lista de frames com força total calculada
    """
    frames = []
    frame_atual = []
    numero_frame = 0
    tempo_frame = None
    metadata = {}
    
    with open(caminho_arquivo, 'r') as f:
        linhas = f.readlines()
    
    i = 0
    while i < len(linhas):
        linha = linhas[i].strip()
        
        if not linha:
            i += 1
            continue
        
        # Verifica se é header/metadata
        if ':' in linha and not linha[0].isdigit():
            partes = linha.split(':', 1)
            key = partes[0].strip()
            value = partes[1].strip() if len(partes) > 1 else ''
            metadata[key] = value
            
            # Tenta extrair tempo se disponível
            if 'Time' in key or 'time' in key:
                try:
                    # Extrai números do tempo (ex: "Time: 0.033 s")
                    numeros = re.findall(r"[-+]?\d*\.?\d+", value)
                    if numeros:
                        tempo_frame = float(numeros[0]) * 1000  # converte para ms
                except:
                    pass
            
            i += 1
            continue
        
        # Verifica se é início de novo frame (linha com dados numéricos)
        try:
            primeira_celula = linha.split(',')[0].strip()
            if primeira_celula and primeira_celula[0].isdigit():
                # Começa a ler dados do frame
                dados_frame = []
                
                # Lê todas as linhas deste frame
                while i < len(linhas):
                    linha_atual = linhas[i].strip()
                    if not linha_atual:
                        i += 1
                        break
                    
                    # Processa linha de dados
                    valores = []
                    for valor in linha_atual.split(','):
                        valor = valor.strip()
                        if valor:
                            # Substitui vírgula por ponto se necessário
                            valor = valor.replace(',', '.')
                            try:
                                valores.append(float(valor))
                            except ValueError:
                                pass
                    
                    if valores:
                        dados_frame.append(valores)
                    
                    # Verifica se próxima linha é metadata (tem ':') ou fim do frame
                    if i + 1 < len(linhas):
                        prox_linha = linhas[i + 1].strip()
                        if ':' in prox_linha and not prox_linha[0].isdigit():
                            i += 1
                            break
                    
                    i += 1
                
                if dados_frame:
                    # Processa o frame
                    pressao_array = np.array(dados_frame)
                    
                    # Converte pressão para Pascal
                    pressao_pa = converter_pressao_para_pascal(pressao_array, metadata)
                    
                    # Calcula força
                    if area_sensel_m2 is None:
                        area_sensel_m2 = extrair_area_sensel(metadata)
                    
                    forca_por_sensel = pressao_pa * area_sensel_m2
                    forca_total = np.sum(forca_por_sensel)
                    
                    # Cria objeto do frame
                    frame = FrameData(
                        numero_frame=numero_frame,
                        tempo_ms=tempo_frame,
                        matriz_pressao=pressao_array,
                        forca_total=forca_total
                    )
                    frames.append(frame)
                    
                    numero_frame += 1
                    tempo_frame = None  # reseta tempo para próximo frame
            else:
                i += 1
        except Exception as e:
            print(f"Erro ao processar linha {i}: {e}")
            i += 1
    
    return frames, metadata

def converter_pressao_para_pascal(pressao_array, metadata):
    """Converte matriz de pressão para Pascal"""
    unidade = metadata.get('Units', metadata.get('Unit', 'kPa')).lower()
    
    if 'kpa' in unidade:
        return pressao_array * 1000
    elif 'psi' in unidade:
        return pressao_array * 6894.76
    else:
        return pressao_array  # Assume Pascal

def extrair_area_sensel(metadata):
    """Extrai área do sensel do metadata"""
    if 'Sensel Area' in metadata:
        area_str = metadata['Sensel Area']
        numeros = re.findall(r"[-+]?\d*\.?\d+", area_str)
        if numeros:
            area_val = float(numeros[0])
            if 'mm²' in area_str or 'mm2' in area_str:
                return area_val * 1e-6
            elif 'cm²' in area_str or 'cm2' in area_str:
                return area_val * 1e-4
            return area_val
    
    # Valor padrão para sensores Tekscan comuns (1.61mm²)
    print("Área do sensel não encontrada, usando valor padrão: 1.61e-6 m²")
    return 1.61e-6

def frames_para_csv(frames, caminho_saida, incluir_tempo=False):
    """
    Converte lista de frames para CSV no formato:
    frame, forca_total (N) [, tempo_ms]
    """
    with open(caminho_saida, 'w', newline='') as f:
        writer = csv.writer(f)
        
        # Header
        if incluir_tempo and any(f.tempo_ms is not None for f in frames):
            writer.writerow(['frame', 'forca_total_N', 'tempo_ms'])
        else:
            writer.writerow(['frame', 'forca_total_N'])
        
        # Dados
        for frame in frames:
            if incluir_tempo and frame.tempo_ms is not None:
                writer.writerow([
                    frame.numero_frame,
                    f'{frame.forca_total:.6f}',
                    f'{frame.tempo_ms:.3f}'
                ])
            else:
                writer.writerow([
                    frame.numero_frame,
                    f'{frame.forca_total:.6f}'
                ])

def processar_arquivo_tekscan(caminho_entrada, caminho_saida, area_sensel_m2=None):
    """
    Função principal para processar arquivo Tekscan e gerar CSV frame a frame
    """
    print(f"Processando arquivo: {caminho_entrada}")
    
    # Parse dos frames
    frames, metadata = parse_tekscan_multiframe(caminho_entrada, area_sensel_m2)
    
    if not frames:
        print("Nenhum frame encontrado!")
        return
    
    print(f"Encontrados {len(frames)} frames")
    print(f"Metadata: {metadata}")
    
    # Estatísticas
    forcas = [f.forca_total for f in frames]
    print(f"\nForça total:")
    print(f"  Mínima: {min(forcas):.3f} N")
    print(f"  Máxima: {max(forcas):.3f} N")
    print(f"  Média: {np.mean(forcas):.3f} N")
    print(f"  Desvio padrão: {np.std(forcas):.3f} N")
    
    # Salva CSV
    frames_para_csv(frames, caminho_saida, incluir_tempo=True)
    print(f"\nArquivo salvo: {caminho_saida}")
    
    return frames

# Exemplo de uso com visualização simples
if __name__ == "__main__":
    # Processa arquivo
    frames = processar_arquivo_tekscan(
        caminho_entrada='dados_tekscan.csv',
        caminho_saida='forca_por_frame.csv',
        area_sensel_m2=1.61e-6  # Área típica em m²
    )
    
    # Opcional: análise adicional
    if frames:
        # Encontra frame com maior força
        frame_max = max(frames, key=lambda f: f.forca_total)
        print(f"\nFrame com maior força:")
        print(f"  Frame {frame_max.numero_frame}: {frame_max.forca_total:.3f} N")
        
        # Se tiver informação de tempo
        if frame_max.tempo_ms is not None:
            print(f"  Tempo: {frame_max.tempo_ms:.3f} ms")
        
        # Exemplo: primeiras 5 linhas do CSV gerado
        print("\nPrimeiras linhas do arquivo gerado:")
        with open('forca_por_frame.csv', 'r') as f:
            for i, linha in enumerate(f):
                if i < 6:  # header + 5 linhas
                    print(linha.strip())
                else:
                    break
