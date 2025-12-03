#!/bin/bash
# Script de instalação rápida / Quick installation script

echo "======================================"
echo "Setup - Treinamento GPU"
echo "Setup - GPU Training"
echo "======================================"
echo ""

# Verificar Python
if ! command -v python3 &> /dev/null; then
    echo "❌ Python 3 não encontrado / Python 3 not found"
    exit 1
fi

echo "✓ Python 3 encontrado / Python 3 found"
PYTHON_VERSION=$(python3 --version)
echo "  $PYTHON_VERSION"
echo ""

# Criar ambiente virtual
echo "📦 Criando ambiente virtual / Creating virtual environment..."
python3 -m venv venv

echo "✓ Ambiente virtual criado / Virtual environment created"
echo ""

# Ativar ambiente virtual
echo "🔧 Ativando ambiente virtual / Activating virtual environment..."
source venv/bin/activate

echo "✓ Ambiente ativado / Environment activated"
echo ""

# Instalar dependências
echo "📥 Instalando dependências / Installing dependencies..."
pip install --upgrade pip
pip install -r requirements.txt

echo ""
echo "✓ Instalação concluída / Installation complete!"
echo ""

# Verificar GPU
if command -v nvidia-smi &> /dev/null; then
    echo "🎮 GPU disponível / GPU available:"
    nvidia-smi --query-gpu=name --format=csv,noheader
    echo ""
    echo "Para instalar suporte GPU (RAPIDS):"
    echo "Visite: https://rapids.ai/start.html"
    echo ""
else
    echo "⚠️  GPU não detectada / GPU not detected"
    echo "O treinamento usará CPU / Training will use CPU"
    echo ""
fi

echo "======================================"
echo "Próximos passos / Next steps:"
echo "======================================"
echo "1. Coloque bank_customers_train.csv neste diretório"
echo "   Place bank_customers_train.csv in this directory"
echo ""
echo "2. Execute: ./run_training.sh"
echo "   Or: python train_model.py"
echo ""
echo "Para ativar o ambiente no futuro:"
echo "To activate environment in the future:"
echo "   source venv/bin/activate"
echo "======================================"
