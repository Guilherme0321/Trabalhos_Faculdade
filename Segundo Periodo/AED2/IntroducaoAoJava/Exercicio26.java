package IntroducaoAoJava;

public class Exercicio26 {
    public static void main(String[] args) {
        int[][] x = new int[4][4];
        gerarMatriz.preencherMatriz(x);
        float media = gerarMatriz.mediaCalc(x);
        System.out.println(media);
    }
}
