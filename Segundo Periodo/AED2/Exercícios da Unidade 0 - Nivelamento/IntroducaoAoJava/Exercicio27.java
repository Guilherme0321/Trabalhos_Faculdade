package IntroducaoAoJava;

public class Exercicio27 {
    public static void main(String[] args) {
        int[][] x = new int[4][4];
        gerarMatriz.preencherMatriz(x);
        float[] media = gerarMatriz.mediaLinha(x);
        for (float f : media) {
            System.out.printf("%.3f ", f);
        }
    }
}
