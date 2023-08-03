import java.util.Scanner;

public class principal {
    public static void chamarExercicio01(){
        Guia01 ex01 = new Guia01();
        ex01.conversor();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choose = 1;
        do{
            System.out.println("Digite 0 para sair do loop\nDigite:\n 1 - exercicio 1");
            choose = scanner.nextInt();
            switch (choose) {
                case 0:
                    break;
                case 1:
                    chamarExercicio01();
                default:
                    break;
            }
        }while(choose != 0);
        scanner.close();
    }
}
