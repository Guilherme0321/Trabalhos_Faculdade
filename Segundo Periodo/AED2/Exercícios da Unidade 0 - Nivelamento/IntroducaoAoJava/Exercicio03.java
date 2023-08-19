package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio03 {

    public static int bigger(int[] x){
        int i = x[0];
        for(int j = 1; j < x.length; j++){
            if(i < x[j]){
                i = x[j];
            }
        }
        return i;
    }
    public static void main(String[] args) {
        int numbens[] = new int[10];
        int i = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Numeros: ");
        while(i < 10 && scanner.hasNextInt()){
            numbens[i] = scanner.nextInt();
            scanner.nextLine();
            i++;
        }
        System.out.println("\nMaior: " + bigger(numbens));
        scanner.close();
    }
}
