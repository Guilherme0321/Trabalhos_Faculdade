#!/usr/bin/env python3
"""
Teste rápido com dataset de exemplo
Quick test with sample dataset
"""

# Este é o mesmo train_model.py mas configurado para usar o dataset de exemplo
# This is the same train_model.py but configured to use the sample dataset

import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier
import time
import warnings
warnings.filterwarnings('ignore')

def main():
    print("\n" + "="*60)
    print("TESTE COM DATASET DE EXEMPLO")
    print("TEST WITH SAMPLE DATASET")
    print("="*60)
    
    # Usar dataset de exemplo
    CSV_FILE = "bank_customers_train_sample.csv"
    
    try:
        # Carregar dados
        print(f"\n✓ Carregando: {CSV_FILE}")
        df = pd.read_csv(CSV_FILE)
        print(f"✓ Linhas: {len(df)}")
        print(f"✓ Colunas: {list(df.columns)}")
        
        # Preparar dados
        target_column = 'churn'
        X = df.drop(columns=[target_column])
        y = df[target_column]
        
        # Codificar categóricas
        for column in X.select_dtypes(include=['object']).columns:
            le = LabelEncoder()
            X[column] = le.fit_transform(X[column].astype(str))
        
        # Normalizar
        scaler = StandardScaler()
        X = scaler.fit_transform(X)
        
        # Dividir
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=0.3, random_state=42
        )
        
        print(f"\n✓ Treino: {len(X_train)} amostras")
        print(f"✓ Teste: {len(X_test)} amostras")
        
        # Treinar
        print(f"\n✓ Treinando Random Forest...")
        model = RandomForestClassifier(n_estimators=10, max_depth=5, random_state=42)
        start = time.time()
        model.fit(X_train, y_train)
        train_time = time.time() - start
        
        # Predição
        y_pred = model.predict(X_test)
        
        # Avaliar
        accuracy = accuracy_score(y_test, y_pred)
        
        print(f"\n{'='*60}")
        print("RESULTADOS / RESULTS")
        print(f"{'='*60}")
        print(f"✓ Acurácia: {accuracy:.2%}")
        print(f"✓ Tempo de treino: {train_time:.3f}s")
        print(f"\n✓ Teste concluído com sucesso!")
        print(f"✓ Test completed successfully!")
        print(f"{'='*60}\n")
        
    except Exception as e:
        print(f"\n✗ ERRO: {e}")
        import traceback
        traceback.print_exc()
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())
