package Arquivos.Exercicios_slide_30_ao_33;

import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Scanner;

public class Exercicio01 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite a frase que quer gravar: ");
        String frase = scanner.nextLine();
        try(BufferedWriter arquivo = new BufferedWriter(new FileWriter("Teste.txt"))){
            arquivo.write(frase);
            arquivo.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        scanner.close();
    }
}
