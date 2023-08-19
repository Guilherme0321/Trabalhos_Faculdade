package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio23 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Numero de linhas: ");
        int l = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Numero de colunas: ");
        int c = scanner.nextInt();
        scanner.nextLine();

        int[][] vector = new int[l][c];
        gerarMatriz.preencherMatriz(vector);
        gerarMatriz.mostrar(vector);
        System.out.println();
        vector = gerarMatriz.transporMatriz(vector, l, c);
        gerarMatriz.mostrar(vector);
        scanner.close();        
    }
}
