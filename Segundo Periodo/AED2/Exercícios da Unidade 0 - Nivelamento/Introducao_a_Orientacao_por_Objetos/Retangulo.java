package Introducao_a_Orientacao_por_Objetos;

public class Retangulo {
    private double altura;
    private double base;
    private double area;
    private double perimetro;
    private double diagonal;

    public Retangulo(int altura, int base){
        this.altura = altura;
        this.base = base;
        this.area = altura * base;
        this.perimetro = (altura * 2) + (base * 2);
        this.diagonal = Math.sqrt(((altura * altura) + (base * base)));
    }

    public double getArea(){
        return this.area;
    }
    public double getPerimetro(){
        return this.perimetro;
    }
    public double getDiagonal(){
        return this.diagonal;
    }
}
