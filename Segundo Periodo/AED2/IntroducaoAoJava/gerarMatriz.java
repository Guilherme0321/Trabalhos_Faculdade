package IntroducaoAoJava;

import java.util.Random;

public class gerarMatriz {
    public static void preencherMatriz(int[][] matriz){
        Random rand = new Random();
        for(int i = 0; i < matriz.length; i++){
            for(int j = 0; j < matriz[i].length; j++){
                matriz[i][j] = rand.nextInt(20);
            }
        }
    }

    public static void mostrar(int[][] matriz){
        for(int[] j : matriz){
            for(int i : j){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public static int[][] transporMatriz(int[][] matriz,int linhas, int colunas){
        int[][] x = new int[colunas][linhas];
        for(int j = 0; j < matriz.length; j++){
            for(int i = 0; i < matriz[j].length; i++){
                x[i][j] = matriz[j][i];
            }
        }
        return x;
    }
}
