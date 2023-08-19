package IntroducaoAoJava;

public class Exercicio28 {
    public static void main(String[] args) {
        int[][] x = new int[4][4];
        gerarMatriz.preencherMatriz(x);
        float[] y = gerarMatriz.mediaColuna(x);
        for (float f : y) {
            System.out.printf("%.2f ", f);
        }
    }
}
