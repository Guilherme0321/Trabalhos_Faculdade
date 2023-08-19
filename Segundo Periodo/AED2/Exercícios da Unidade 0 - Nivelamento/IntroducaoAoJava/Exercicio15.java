package IntroducaoAoJava;

import java.util.Random;
import java.util.Scanner;

public class Exercicio15 {
    public static boolean isPar(int x){
        return (x % 2 == 0) ? true: false;
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
        int p1 = 0, p2 = 1;
        int recive = 0;
        for(int i = 0; i < (int)(q/2); i++){
            recive = scanner.nextInt();
            scanner.nextLine();
            if(isPar(recive)){
                System.out.println(x[p1] + x[p2]);
                p1 += 1;
                p2 += 1;
            }
        }
        scanner.close();
    }
}
