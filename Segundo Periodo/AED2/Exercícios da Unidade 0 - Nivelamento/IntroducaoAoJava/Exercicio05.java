package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio05 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        scanner.nextLine();
        int y = scanner.nextInt();
        if(x > y){
            System.out.println("Time 1 vencedor");
        }else{
            System.out.println("Time 2 vencedor");
        }
        scanner.close();
    }
}
