package IntroducaoAoJava;

import java.util.Random;
import java.util.Scanner;

public class Exercicio21 {

    public static int particao(int[] array, int ini, int fim){
        int j = ini -1;

        for(int i = ini; i < fim; i++){
            if(array[i] < array[fim]){
                j++;
                int x = array[i];
                array[i] = array[j];
                array[j] = x;
            }
        }

        int x = array[j + 1];
        array[j + 1] = array[fim];
        array[fim] = x;

        return j + 1;
    }

    public static void quickSort(int[] array, int ini, int fim){
        if(ini < fim){
            int pivo = particao(array, ini, fim); 
            quickSort(array, ini, pivo - 1);
            quickSort(array, pivo + 1, fim);
        }
    }

    public static void mostrar(int[] array){
        for(int i : array){
            System.out.print(i + " ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Quantidade do array: ");
        int q = scanner.nextInt();
        Random rand = new Random();
        int[] numbers = new int[q];
        for(int i = 0; i < q; i++){
            numbers[i] = rand.nextInt(101);
        }
        mostrar(numbers);
        quickSort(numbers, 0, numbers.length-1);
        mostrar(numbers);

        scanner.close();
    }
}
