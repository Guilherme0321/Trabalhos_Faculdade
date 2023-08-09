import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import Arquivos.*;
public class Controller {
    public static void Exercicio01(){
        try{
            ExemploARQescrita.openWrite("Teste.txt");
            ExemploARQescrita.Write("ola mundo");
            ExemploARQescrita.close();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }

    public static void Exercicio02(){
        try{
            ExemploARQleitura.openRead("Teste.txt");
            String recive = "";
            while(ExemploARQleitura.hasNextLine()){
                recive += ExemploARQleitura.readLine() + "\n";
            }
            ExemploARQleitura.close();
            System.out.println(recive + " " + ExemploARQleitura.getLine());
        }catch(FileNotFoundException e){
            System.out.println(e.getMessage());
        }
    }
    
    public static void main(String[] args) {
        int op = -1;
        Scanner scanner = new Scanner(System.in);
        while(op != 0 && scanner.hasNextInt()){
            System.out.println("0 - Sair do loop\n1 - Exercicio 01\n2 - Exercicio 02\n");
            op = scanner.nextInt();
            if(op == 0){
                continue;
            }
            switch (op) {
                case 1:
                    Exercicio01();
                    break;
                case 2:
                    Exercicio02();
                    break;
                default:
                    break;
            }
        }
        scanner.close();
    }
}
