package IntroducaoAoJava;

public class Exercicio22 {
    public static void main(String[] args) {
        
        int[][] x = new int[5][4];
        gerarMatriz.preencherMatriz(x);
        for(int[] i : x){
            for(int j : i){
                System.out.print(j + " ");
            }
            System.out.println("");
        }
    }
}
