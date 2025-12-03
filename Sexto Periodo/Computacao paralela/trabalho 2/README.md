# Treinamento de Modelo - Dataset de Clientes Bancários
# Model Training - Bank Customers Dataset

Este projeto implementa treinamento acelerado por GPU de modelos de machine learning usando o dataset de clientes bancários.

## 📋 Requisitos / Requirements

### Windows WSL com GPU / Windows WSL with GPU

1. **WSL 2** instalado no Windows
2. **NVIDIA GPU** com drivers atualizados
3. **CUDA Toolkit** (11.x ou 12.x)
4. **Python 3.8+**

### Verificar GPU no WSL / Check GPU in WSL

```bash
nvidia-smi
```

Se o comando acima funcionar, sua GPU está acessível no WSL.

## 🚀 Instalação / Installation

### 1. Clonar o repositório / Clone the repository

```bash
cd "Sexto Periodo/Computacao paralela/trabalho 2"
```

### 2. Colocar o dataset / Place the dataset

Certifique-se de que o arquivo `bank_customers_train.csv` está neste diretório.

### 3. Criar ambiente virtual (recomendado) / Create virtual environment (recommended)

```bash
python3 -m venv venv
source venv/bin/activate  # No Linux/WSL
```

### 4. Instalar dependências / Install dependencies

#### Opção A: CPU apenas (mais simples) / CPU only (simpler)

```bash
pip install -r requirements.txt
```

#### Opção B: GPU com RAPIDS (melhor performance) / GPU with RAPIDS (best performance)

Visite https://rapids.ai/start.html e siga as instruções para sua versão CUDA.

Exemplo para CUDA 11.x:
```bash
pip install cudf-cu11 cuml-cu11 -f https://rapids.ai/wheels.html
pip install -r requirements.txt
```

## 🏃 Execução / Execution

### Executar treinamento / Run training

```bash
python train_model.py
```

### O script automaticamente:
- ✓ Detecta se GPU está disponível (RAPIDS cuML)
- ✓ Carrega e preprocessa os dados eficientemente
- ✓ Treina o modelo (Random Forest ou Decision Tree)
- ✓ Avalia a performance
- ✓ Exibe métricas e tempo de treinamento

### Se GPU não estiver disponível:
O script automaticamente usa CPU (sklearn) como fallback.

## ⚙️ Configurações / Settings

Edite o arquivo `train_model.py` para ajustar:

```python
# Linha ~250 na função main()
CSV_FILE = "bank_customers_train.csv"  # Nome do arquivo
SAMPLE_SIZE = None  # None = todo dataset, ou número para amostra
MODEL_TYPE = 'random_forest'  # 'random_forest' ou 'decision_tree'
TEST_SIZE = 0.2  # 20% para teste
```

## 📊 Saída / Output

O script exibe:
- ✓ Informações sobre o dataset carregado
- ✓ Processo de preprocessamento
- ✓ Tempo de treinamento
- ✓ Acurácia do modelo
- ✓ Relatório de classificação
- ✓ Matriz de confusão

## 🎯 Características / Features

- **GPU-Accelerated**: Usa RAPIDS cuML quando disponível
- **Fallback CPU**: Funciona mesmo sem GPU
- **Eficiente**: Não faz análise exploratória completa, foca no treinamento
- **Flexível**: Suporta Decision Tree e Random Forest
- **Bilíngue**: Mensagens em português e inglês

## 🐛 Troubleshooting

### Erro: "File 'bank_customers_train.csv' not found"
- Certifique-se de que o arquivo CSV está no mesmo diretório que `train_model.py`

### GPU não detectada
- Verifique se `nvidia-smi` funciona no WSL
- Certifique-se de que os drivers NVIDIA estão atualizados no Windows
- Verifique se WSL 2 está instalado (não WSL 1)

### Erro de importação RAPIDS
- O script automaticamente usa CPU se RAPIDS não estiver instalado
- Para instalar RAPIDS, siga: https://rapids.ai/start.html

## 📝 Notas / Notes

- **Não analisa toda a base**: O script é otimizado para treinamento direto, sem análise exploratória extensa
- **GPU mandatório**: O código mantém suporte a GPU como requisito, com fallback para CPU
- **WSL friendly**: Otimizado para execução no Windows Subsystem for Linux

## 🔧 Dependências principais / Main Dependencies

- pandas: Manipulação de dados
- scikit-learn: Machine learning (CPU)
- RAPIDS cuML: Machine learning (GPU) - opcional
- numpy: Operações numéricas

## 📄 Licença / License

Este é um trabalho acadêmico.
