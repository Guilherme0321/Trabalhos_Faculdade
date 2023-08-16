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

    public static int[][] somarMatariz(int[][] matriz01, int[][] matriz02){
        int[][] x = new int[matriz01.length+matriz02.length][matriz01[0].length];
        for(int i = 0; i < matriz01.length+matriz02.length;i++){
            if(i < matriz01.length){
                for(int j = 0; j < matriz01[i].length; j++){
                    x[i][j] = matriz01[i][j];
                }
            }else{
                for(int j = 0; j < matriz02[i-matriz01.length].length; j++){
                    x[i][j] = matriz02[i-matriz01.length][j];
                }
            }
        }
        return x;
    }

    public static void diagonais(int[][] matriz){
        for(int i = 0; i < matriz.length; i++){
            System.out.printf("%d ", matriz[i][i]);
        }
        System.out.println();
        for(int i = 0; i < matriz.length; i++){
            System.out.printf("%d ", matriz[matriz.length-i-1][matriz[i].length-1-i]);
        }
    }

    public static float mediaCalc(int[][] matriz){
        float media = 0;
        int q = 0;
        for(int x[] : matriz){
            for(int i : x){
                media += i;
                q++;
            }
        }
        return media / q;
    }

    public static float[] mediaLinha(int[][] matriz){
        float[] medias = new float[matriz.length];
        for(int i = 0; i < matriz.length; i++) {
            for(int j = 0; j < matriz[i].length; j++){
                medias[i] += matriz[i][j];
            }
            medias[i] /= matriz[i].length;
        }
        return medias;
    }

    public static float[] mediaColuna(int[][] matriz){
        float[] medias = new float[matriz.length];
        for(int i = 0; i < matriz.length; i++){
            for(int j = 0; j < matriz[i].length; j++){
                medias[i] += matriz[j][i];
            }
            medias[i] /= matriz[i].length;
        }
        return medias;
    }
}
