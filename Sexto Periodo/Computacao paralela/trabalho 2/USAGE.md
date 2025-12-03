# GUIA DE USO RÁPIDO / QUICK USAGE GUIDE
# ========================================

## Para iniciar / To start:

### 1. Setup (primeira vez / first time only)
```bash
./setup.sh
```

### 2. Colocar dataset / Place dataset
- Copie `bank_customers_train.csv` para este diretório
- Copy `bank_customers_train.csv` to this directory

### 3. Executar treinamento / Run training
```bash
./run_training.sh
```

OU / OR

```bash
python train_model.py
```

## Testando com dados de exemplo / Testing with sample data

Se você não tem o dataset completo ainda, teste com o arquivo de exemplo:
If you don't have the full dataset yet, test with the sample file:

```bash
python test_sample.py
```

## Estrutura de arquivos / File structure

```
trabalho 2/
├── train_model.py                    # Script principal (GPU + CPU)
├── test_sample.py                    # Teste com dados de exemplo
├── requirements.txt                  # Dependências Python
├── setup.sh                          # Script de instalação
├── run_training.sh                   # Script de execução
├── README.md                         # Documentação completa
├── .gitignore                        # Arquivos ignorados pelo Git
├── bank_customers_train_sample.csv   # Dataset de exemplo (10 linhas)
├── bank_customers_train.csv          # SEU DATASET AQUI (não incluído)
└── USAGE.md                          # Este arquivo
```

## Comandos úteis WSL / Useful WSL commands

### Verificar GPU
```bash
nvidia-smi
```

### Ativar ambiente virtual
```bash
source venv/bin/activate
```

### Desativar ambiente virtual
```bash
deactivate
```

### Instalar dependências GPU (RAPIDS)
Visite / Visit: https://rapids.ai/start.html

Exemplo para CUDA 11 / Example for CUDA 11:
```bash
pip install cudf-cu11 cuml-cu11 -f https://rapids.ai/wheels.html
```

## Solução de problemas / Troubleshooting

### Erro: "ModuleNotFoundError"
Execute / Run: `./setup.sh` primeiro

### GPU não detectada / GPU not detected
- Verifique / Check: `nvidia-smi`
- Atualize drivers NVIDIA / Update NVIDIA drivers
- Use WSL 2 (não WSL 1) / Use WSL 2 (not WSL 1)

### Dataset não encontrado / Dataset not found
- Coloque o CSV na pasta correta / Place CSV in correct folder
- Nome deve ser exato / Name must be exact: `bank_customers_train.csv`

## Configurações / Settings

Edite `train_model.py` linha ~250 / Edit `train_model.py` line ~250:

```python
CSV_FILE = "bank_customers_train.csv"  # Nome do arquivo / Filename
SAMPLE_SIZE = None                      # None = all, ou número / or number
MODEL_TYPE = 'random_forest'            # ou / or 'decision_tree'
TEST_SIZE = 0.2                        # 20% para teste / for testing
```

## Performance esperada / Expected performance

- **CPU**: ~2-10 segundos para datasets pequenos/médios
- **GPU (RAPIDS)**: ~1-3 segundos (até 10x mais rápido)

## Saída esperada / Expected output

```
============================================================
TREINAMENTO DE MODELO - BANCO DE CLIENTES
MODEL TRAINING - BANK CUSTOMERS
============================================================

============================================================
CARREGANDO DADOS / LOADING DATA
============================================================
✓ Dataset loaded on GPU: 10000 rows
✓ Columns: [...]
✓ Shape: (10000, 10)

============================================================
PREPROCESSANDO DADOS / PREPROCESSING DATA
============================================================
✓ Target column: churn
✓ Encoded categorical column: gender
✓ Features normalized
✓ Final feature shape: (10000, 9)

============================================================
DIVIDINDO DADOS / SPLITTING DATA
============================================================
✓ Training set: 8000 samples
✓ Test set: 2000 samples

============================================================
TREINANDO MODELO NA GPU / TRAINING MODEL ON GPU
============================================================
✓ Using GPU-accelerated Random Forest
✓ Training started...
✓ Training completed in 2.35 seconds
✓ Making predictions...

============================================================
AVALIAÇÃO DO MODELO / MODEL EVALUATION
============================================================

✓ Accuracy: 0.8542 (85.42%)

Classification Report:
...

Confusion Matrix:
...

============================================================
SUMÁRIO / SUMMARY
============================================================
✓ Model type: random_forest
✓ Training device: GPU (RAPIDS cuML)
✓ Training time: 2.35 seconds
✓ Dataset size: 10000 rows
✓ Training complete!
============================================================
```

## Suporte / Support

Para problemas ou dúvidas / For issues or questions:
- Leia o README.md completo
- Verifique os logs de erro
- Teste com `test_sample.py` primeiro
