package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio13 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        float[] notas = new float[5];
        int max = 0;
        while(max < 5){
            System.out.print("Nota do aluno " + (max+1) + ": ");
            notas[max] = scanner.nextFloat();
            scanner.nextLine();
            max++;
        }
        float media = 0;
        for(float i : notas){
            media += i;
        }
        media = media / 5;
        System.out.println("Media: " + media);
        scanner.close();
    }
}
