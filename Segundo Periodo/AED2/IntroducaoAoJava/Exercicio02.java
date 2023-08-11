package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio02 {

    public static int bigger(int[] numbers){
        int pivot = numbers[0], len = 1;
        while(len < numbers.length){
            if(pivot < numbers[len]){
                pivot = numbers[len];
            }
            len++;
        }
        return pivot;
    }

    public static int smaller(int[] numbers){
        int pivot = numbers[0];
        int len = 1;
        while(len < numbers.length){
            if(pivot > numbers[len]){
                pivot = numbers[len];
            }
            len++;
        }
        return pivot;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] num = {0,0,0};
        int i = 2;
        while(i >= 0){
            num[i] = scanner.nextInt();
            scanner.nextLine();
            i--;
        }
        System.out.println("Menor: " + smaller(num));
        System.out.println("Maior: " + bigger(num));
        scanner.close();
    }
}
