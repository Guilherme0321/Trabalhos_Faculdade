package IntroducaoAoJava;

import java.util.Random;
import java.util.Scanner;

public class Exercicio14 {
    public static int bigger(int[] array){
        int i = 0;
        for(int j = 0; j < array.length; j++){
            if(array[i] < array[j]){
                i = j;
            }
        }
        return i;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Quantidades de valores que deseja no array: ");
        Random rand = new Random();
        int q = scanner.nextInt();             
        int[] x = new int[q];
        for(int i = 0; i < q; i++){
            x[i] = rand.nextInt();
        }
        float media = 0;
        for (int i : x) {
            media += i;
            System.out.println(i);
        }
        media /= q;
        System.out.printf("Media: %.3f  Maior: %d", media, x[bigger(x)]);
        scanner.close();
    }
}
