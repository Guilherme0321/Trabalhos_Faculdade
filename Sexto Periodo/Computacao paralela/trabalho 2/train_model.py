#!/usr/bin/env python3
"""
GPU-Accelerated Model Training for Bank Customers Dataset
Treinamento acelerado por GPU para o dataset de clientes bancários

Este script treina um modelo de machine learning usando GPU para melhor performance.
Não realiza análise exploratória completa, focando apenas no treinamento eficiente.
"""

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import time
import warnings
warnings.filterwarnings('ignore')

# Tentar importar bibliotecas GPU
try:
    import cudf
    import cuml
    from cuml.ensemble import RandomForestClassifier as cuRF
    from cuml.tree import DecisionTreeClassifier as cuDT
    GPU_AVAILABLE = True
    print("✓ GPU libraries (RAPIDS cuML) available - using GPU acceleration")
except ImportError:
    from sklearn.ensemble import RandomForestClassifier
    from sklearn.tree import DecisionTreeClassifier
    GPU_AVAILABLE = False
    print("⚠ GPU libraries not available - falling back to CPU (sklearn)")

def load_and_prepare_data(file_path, sample_size=None):
    """
    Carrega e prepara os dados sem análise exploratória extensa
    Load and prepare data without extensive exploratory analysis
    """
    print(f"\n{'='*60}")
    print("CARREGANDO DADOS / LOADING DATA")
    print(f"{'='*60}")
    
    # Carregar dados
    if GPU_AVAILABLE:
        df = cudf.read_csv(file_path)
        print(f"✓ Dataset loaded on GPU: {len(df)} rows")
    else:
        df = pd.read_csv(file_path)
        print(f"✓ Dataset loaded on CPU: {len(df)} rows")
    
    # Se sample_size especificado, usar apenas uma amostra (para treino rápido)
    if sample_size and sample_size < len(df):
        if GPU_AVAILABLE:
            df = df.sample(n=sample_size, random_state=42)
        else:
            df = df.sample(n=sample_size, random_state=42)
        print(f"✓ Using sample of {sample_size} rows for efficient training")
    
    print(f"✓ Columns: {list(df.columns)}")
    print(f"✓ Shape: {df.shape}")
    
    return df

def preprocess_data(df, target_column=None):
    """
    Preprocessa os dados de forma eficiente
    Efficiently preprocess the data
    """
    print(f"\n{'='*60}")
    print("PREPROCESSANDO DADOS / PREPROCESSING DATA")
    print(f"{'='*60}")
    
    # Converter para pandas se estiver em cuDF
    if GPU_AVAILABLE and isinstance(df, cudf.DataFrame):
        df_pandas = df.to_pandas()
    else:
        df_pandas = df.copy()
    
    # Identificar coluna target (última coluna ou especificada)
    if target_column is None:
        target_column = df_pandas.columns[-1]
    
    print(f"✓ Target column: {target_column}")
    
    # Separar features e target
    X = df_pandas.drop(columns=[target_column])
    y = df_pandas[target_column]
    
    # Codificar variáveis categóricas
    label_encoders = {}
    for column in X.select_dtypes(include=['object']).columns:
        le = LabelEncoder()
        X[column] = le.fit_transform(X[column].astype(str))
        label_encoders[column] = le
        print(f"✓ Encoded categorical column: {column}")
    
    # Codificar target se for categórico
    if y.dtype == 'object':
        le_target = LabelEncoder()
        y = le_target.fit_transform(y.astype(str))
        print(f"✓ Encoded target column: {target_column}")
    
    # Normalizar features
    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)
    X_scaled = pd.DataFrame(X_scaled, columns=X.columns)
    
    print(f"✓ Features normalized")
    print(f"✓ Final feature shape: {X_scaled.shape}")
    
    return X_scaled, y, label_encoders, scaler

def train_model_gpu(X_train, X_test, y_train, y_test, model_type='random_forest'):
    """
    Treina modelo usando GPU (RAPIDS cuML)
    Train model using GPU (RAPIDS cuML)
    """
    print(f"\n{'='*60}")
    print("TREINANDO MODELO NA GPU / TRAINING MODEL ON GPU")
    print(f"{'='*60}")
    
    # Converter para cuDF
    X_train_gpu = cudf.DataFrame.from_pandas(X_train)
    X_test_gpu = cudf.DataFrame.from_pandas(X_test)
    y_train_gpu = cudf.Series(y_train)
    y_test_gpu = cudf.Series(y_test)
    
    # Criar e treinar modelo
    start_time = time.time()
    
    if model_type == 'decision_tree':
        model = cuDT(max_depth=10, random_state=42)
        print("✓ Using GPU-accelerated Decision Tree")
    else:  # random_forest
        model = cuRF(n_estimators=100, max_depth=10, random_state=42)
        print("✓ Using GPU-accelerated Random Forest")
    
    print(f"✓ Training started...")
    model.fit(X_train_gpu, y_train_gpu)
    train_time = time.time() - start_time
    
    print(f"✓ Training completed in {train_time:.2f} seconds")
    
    # Fazer predições
    print(f"✓ Making predictions...")
    y_pred = model.predict(X_test_gpu)
    
    # Converter para numpy para métricas
    y_test_np = y_test_gpu.to_numpy()
    y_pred_np = y_pred.to_numpy()
    
    return model, y_pred_np, y_test_np, train_time

def train_model_cpu(X_train, X_test, y_train, y_test, model_type='random_forest'):
    """
    Treina modelo usando CPU (sklearn) - fallback
    Train model using CPU (sklearn) - fallback
    """
    print(f"\n{'='*60}")
    print("TREINANDO MODELO NA CPU / TRAINING MODEL ON CPU")
    print(f"{'='*60}")
    
    start_time = time.time()
    
    if model_type == 'decision_tree':
        model = DecisionTreeClassifier(max_depth=10, random_state=42)
        print("✓ Using CPU Decision Tree")
    else:  # random_forest
        model = RandomForestClassifier(n_estimators=100, max_depth=10, random_state=42, n_jobs=-1)
        print("✓ Using CPU Random Forest (using all cores)")
    
    print(f"✓ Training started...")
    model.fit(X_train, y_train)
    train_time = time.time() - start_time
    
    print(f"✓ Training completed in {train_time:.2f} seconds")
    
    # Fazer predições
    print(f"✓ Making predictions...")
    y_pred = model.predict(X_test)
    
    return model, y_pred, y_test, train_time

def evaluate_model(y_test, y_pred):
    """
    Avalia o modelo treinado
    Evaluate the trained model
    """
    print(f"\n{'='*60}")
    print("AVALIAÇÃO DO MODELO / MODEL EVALUATION")
    print(f"{'='*60}")
    
    # Calcular métricas
    accuracy = accuracy_score(y_test, y_pred)
    
    print(f"\n✓ Accuracy: {accuracy:.4f} ({accuracy*100:.2f}%)")
    print(f"\nClassification Report:")
    print(classification_report(y_test, y_pred))
    print(f"\nConfusion Matrix:")
    print(confusion_matrix(y_test, y_pred))

def main():
    """
    Função principal / Main function
    """
    print("\n" + "="*60)
    print("TREINAMENTO DE MODELO - BANCO DE CLIENTES")
    print("MODEL TRAINING - BANK CUSTOMERS")
    print("="*60)
    
    # Configurações
    CSV_FILE = "bank_customers_train.csv"
    SAMPLE_SIZE = None  # None para usar todo o dataset, ou número para amostra
    MODEL_TYPE = 'random_forest'  # 'random_forest' ou 'decision_tree'
    TEST_SIZE = 0.2
    
    try:
        # 1. Carregar dados
        df = load_and_prepare_data(CSV_FILE, sample_size=SAMPLE_SIZE)
        
        # 2. Preprocessar dados
        X, y, label_encoders, scaler = preprocess_data(df)
        
        # 3. Dividir em treino e teste
        print(f"\n{'='*60}")
        print("DIVIDINDO DADOS / SPLITTING DATA")
        print(f"{'='*60}")
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=TEST_SIZE, random_state=42
        )
        print(f"✓ Training set: {len(X_train)} samples")
        print(f"✓ Test set: {len(X_test)} samples")
        
        # 4. Treinar modelo
        if GPU_AVAILABLE:
            model, y_pred, y_test_eval, train_time = train_model_gpu(
                X_train, X_test, y_train, y_test, model_type=MODEL_TYPE
            )
        else:
            model, y_pred, y_test_eval, train_time = train_model_cpu(
                X_train, X_test, y_train, y_test, model_type=MODEL_TYPE
            )
        
        # 5. Avaliar modelo
        evaluate_model(y_test_eval, y_pred)
        
        # Sumário final
        print(f"\n{'='*60}")
        print("SUMÁRIO / SUMMARY")
        print(f"{'='*60}")
        print(f"✓ Model type: {MODEL_TYPE}")
        print(f"✓ Training device: {'GPU (RAPIDS cuML)' if GPU_AVAILABLE else 'CPU (sklearn)'}")
        print(f"✓ Training time: {train_time:.2f} seconds")
        print(f"✓ Dataset size: {len(df)} rows")
        print(f"✓ Training complete!")
        print(f"{'='*60}\n")
        
    except FileNotFoundError:
        print(f"\n✗ ERROR: File '{CSV_FILE}' not found!")
        print(f"✗ Please place the bank_customers_train.csv file in the same directory as this script.")
        return 1
    except Exception as e:
        print(f"\n✗ ERROR: {str(e)}")
        import traceback
        traceback.print_exc()
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())
