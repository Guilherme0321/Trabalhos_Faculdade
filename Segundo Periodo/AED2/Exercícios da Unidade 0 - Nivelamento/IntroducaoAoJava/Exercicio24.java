package IntroducaoAoJava;

public class Exercicio24 {
    public static void main(String[] args) {
        int[][] x = {{5,6,1,3,2},{4,2,5,9,10},{7,3,1,-2,-8},{-10,30,41,20,2},{10,30,50,21,32}};
        int[][] y = {{5,6,1,3,2},{4,2,5,9,10},{7,3,1,-2,-8},{-10,30,41,20,2},{10,30,50,21,32}};
        int [][] soma = gerarMatriz.somarMatariz(x, y);
        gerarMatriz.mostrar(soma);
    }
}   
