package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio17 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite o numero de elementos: ");
        int N = scanner.nextInt();
        
        int[] array = new int[N];
        
        for (int i = 0; i < N; i++) {
            System.out.print("Digite o numero: " + (i + 1) + ": ");
            array[i] = scanner.nextInt();
        }
        
        int pares = 0;
        int divisiveisPorTres = 0;
        
        for (int num : array) {
            if (num % 2 == 0) {
                pares++;
            }
            if (num % 3 == 0) {
                divisiveisPorTres++;
            }
        }
        scanner.close();
        System.out.println("Pares: " + pares);
        System.out.println("Divisiveis por tres: " + divisiveisPorTres);
    }
}
