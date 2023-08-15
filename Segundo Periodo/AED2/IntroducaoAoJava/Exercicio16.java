package IntroducaoAoJava;

import java.util.Random;
import java.util.Scanner;

public class Exercicio16 {
    public static int smaller(int[] array){
        int p = 0;
        for(int i = 0; i < array.length; i++){
            if(array[p] > array[i]){
                p = i;
            }
        }
        return p;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Quantidades de valores que deseja no array: ");
        int q = scanner.nextInt();             
        int[] x = new int[q];
        Random random = new Random();
        for(int i = 0; i < q; i++){
            x[i] = random.nextInt(101);
        }
        System.out.println("Posicao do menor: " + smaller(x));
        scanner.close();
    }
}
