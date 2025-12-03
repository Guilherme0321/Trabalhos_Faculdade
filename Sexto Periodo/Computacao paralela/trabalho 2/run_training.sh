#!/bin/bash
# Script para executar o treinamento no WSL
# Script to run training on WSL

echo "======================================"
echo "Treinamento - Dataset Clientes Banco"
echo "Training - Bank Customers Dataset"
echo "======================================"
echo ""

# Verificar se o arquivo CSV existe
if [ ! -f "bank_customers_train.csv" ]; then
    echo "❌ ERRO: bank_customers_train.csv não encontrado!"
    echo "❌ ERROR: bank_customers_train.csv not found!"
    echo ""
    echo "Por favor, coloque o arquivo CSV neste diretório."
    echo "Please place the CSV file in this directory."
    exit 1
fi

echo "✓ Dataset encontrado / Dataset found"
echo ""

# Verificar se GPU está disponível
if command -v nvidia-smi &> /dev/null; then
    echo "🚀 GPU detectada / GPU detected:"
    nvidia-smi --query-gpu=name,memory.total --format=csv,noheader
    echo ""
else
    echo "⚠️  GPU não detectada - usando CPU / GPU not detected - using CPU"
    echo ""
fi

# Ativar ambiente virtual se existir
if [ -d "venv" ]; then
    echo "✓ Ativando ambiente virtual / Activating virtual environment"
    source venv/bin/activate
fi

# Executar treinamento
echo "🏃 Iniciando treinamento / Starting training..."
echo ""
python3 train_model.py

echo ""
echo "======================================"
echo "Treinamento concluído / Training completed"
echo "======================================"
