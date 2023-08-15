package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio19 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a quantidade: ");
        int N = scanner.nextInt();
        
        int[] array1 = new int[N];
        int[] array2 = new int[N];
        
        System.out.println("Digite os numeros do primeiro array: ");
        for (int i = 0; i < N; i++) {
            System.out.print("Numero " + (i + 1) + ": ");
            array1[i] = scanner.nextInt();
        }
        
        System.out.println("Digite os numeros do segundo array: ");
        for (int i = 0; i < N; i++) {
            System.out.print("Numero " + (i + 1) + ": ");
            array2[i] = scanner.nextInt();
        }
        
        System.out.println("");
        for (int i = 0; i < N; i++) {
            System.out.print(array1[i] + " " + array2[i] + " \n");
        }
        scanner.close();
    }
}
