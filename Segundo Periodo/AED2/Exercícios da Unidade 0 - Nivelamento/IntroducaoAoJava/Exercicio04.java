package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio04 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = 0, y = 0;
        x = scanner.nextInt();
        y = scanner.nextInt();
        if( x > 45 || y > 45){
            System.out.println(x + y);
        }else if( x > 20 && y > 20 ){
            System.out.println(x - y);
        }else if( (x != 0 && y != 0) && ( x < 10 || y < 10) ){
            System.out.println((float)(x / y));
            
        }else{
            System.out.println("Guilherme Otavio de Oliveira");
        }
        scanner.close();
    }
}
