package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio18 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a quantidade: ");
        int N = scanner.nextInt();
        
        int[] array = new int[N];
        
        for (int i = 0; i < N; i++) {
            System.out.print("Digite o numero: " + (i + 1) + ": ");
            array[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < N / 2; i++) {
            int soma = array[i] + array[N - 1 - i];
            System.out.println("Soma " + (i + 1) + ": " + soma);
        }
        scanner.close();
    }
}
