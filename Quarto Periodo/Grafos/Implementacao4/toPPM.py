from PIL import Image

def converter_para_ppm(caminho_imagem_entrada, caminho_imagem_saida):
    # Carregar a imagem
    imagem = Image.open(caminho_imagem_entrada)
    
    # Converter para o modo RGB se necessário
    if imagem.mode != 'RGB':
        imagem = imagem.convert('RGB')
    
    # Salvar como PPM
    imagem.save(caminho_imagem_saida, 'PPM')

    print(f'Imagem salva como PPM em: {caminho_imagem_saida}')

# Caminho da imagem de entrada e saída
caminho_imagem_entrada = 'um.png'  # Pode ser .jpg, .jpeg, etc.
caminho_imagem_saida = 'um.ppm'

# Converter a imagem para PPM
converter_para_ppm(caminho_imagem_entrada, caminho_imagem_saida)
