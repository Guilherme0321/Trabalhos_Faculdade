package IntroducaoAoJava;

import java.util.Scanner;

public class Exercicio06 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        float valorBruto = 0, prestacao = 0; // prestação não pode ultrapassar valorBruto * 40/100
        System.out.print("Valor Bruto: ");
        valorBruto = scanner.nextFloat();
        scanner.nextLine();
        System.out.print("Valor da prestacao: ");
        prestacao = scanner.nextFloat();
        scanner.nextLine();
        if(valorBruto * 0.4 >= prestacao){
            System.out.println("Concedido");
        }else{
            System.out.println("Negado");
        }
        scanner.close();
    }
}
