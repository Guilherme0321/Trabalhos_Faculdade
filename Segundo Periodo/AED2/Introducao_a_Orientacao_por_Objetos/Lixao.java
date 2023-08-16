package Introducao_a_Orientacao_por_Objetos;

public class Lixao {
    public static void main(String[] args) {
        Retangulo retangulo = new Retangulo(5, 10);
        System.out.printf("Area: %f  Perimetro: %f  Diagonal: %f", retangulo.getArea(), retangulo.getPerimetro(), retangulo.getDiagonal());
    }
}
