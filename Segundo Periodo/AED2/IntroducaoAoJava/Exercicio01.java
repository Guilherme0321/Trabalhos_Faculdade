package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio01 {

    public static boolean isEquilatero(int[] lados){
        return (lados[0] == lados[1] && lados[1] == lados[2]) ? true : false;
    }

    public static boolean isIsoceles(int[] lados){
        return (lados[0] == lados[1] || lados[1] == lados[2] || lados[0] == lados[2]) ? true : false;
    }

    public static void main(String[] args) {
        int[] lados = {0,0,0};
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite os valores dos lados dos triangulos: ");
        lados[0] = scanner.nextInt();
        scanner.nextLine();
        lados[1] = scanner.nextInt();
        scanner.nextLine();
        lados[2] = scanner.nextInt();
        scanner.nextLine();
        if(isEquilatero(lados)){
            System.out.println("Equilatero!");
        } else if(isIsoceles(lados)){
            System.out.println("Isoceles!");
        } else{
            System.out.println("Escaleno!");
        }
        scanner.close();
    }
}
