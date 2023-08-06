import java.util.Scanner;

import Java.*;


public class Java_controller {
    public static void chamarExercicio01(){
        toBinary ex01 = new toBinary();
        ex01.conversor();
    }
    public static void chamarExercicio02(){
        toDecimal ex02 = new toDecimal();
        ex02.executeLoop();
    }
    public static void chamarExercicio03(){
        Dec2Base ex03 = new Dec2Base();
        ex03.executeLoop();
    }
    public static void chamarExercicio04(){
        Bin2Base ex04 = new Bin2Base();
        ex04.executeLoop();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choose = 1;
        do{
            System.out.println("\n\nDigite 0 para sair do loop\n\nDigite:\n 1 - exercicio 1\n\n 2 - exercicio 2\n\n 3 - exercicio 3\n\n 4 - exercicio 4");
            choose = scanner.nextInt();
            switch (choose) {
                case 0:
                    break;
                case 1:
                    chamarExercicio01();
                    break;
                case 2:
                    chamarExercicio02();
                    break;
                case 3:
                    chamarExercicio03();
                    break;
                case 4:
                    chamarExercicio04();
                    break;
                default:
                    break;
            }
        }while(choose != 0);
        scanner.close();
    }
}
