package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio20 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Quantidade do primerio array: ");

        int N = scanner.nextInt();
        scanner.nextLine();

        int[] array = new int[N];

        for(int i = 0; i < N; i++){
            System.out.print("\nNumero " + (i+1) + ": ");
            array[i] = scanner.nextInt();
            scanner.nextLine();
        }

        System.out.print("Quantidade do segundo array: ");

        int M = scanner.nextInt();
        scanner.nextLine();

        int[] array2 = new int[M];

        for(int i = 0; i < M; i++){
            System.out.print("\nNumero " + (i+1) + ": ");
            array2[i] = scanner.nextInt();
            scanner.nextLine();
        }

        int repetir = (array.length < array2.length) ? array2.length: array.length;

        for(int i = 0; i < repetir; i++){
            if(i < array.length){
                System.out.print(array[i]);
            }
            System.out.print("      ");
            if(i < array2.length){
                System.out.print(array2[i]);
            }
            System.out.println("");
        }

        scanner.close();
    }
}
