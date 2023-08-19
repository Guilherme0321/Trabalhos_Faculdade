package Recursividade;

public class Exercicio09 {
    public static void hanoi(int n, char origem, char destino, char auxiliar) {
        if (n == 1) {
            System.out.println("Mova o disco 1 de " + origem + " para " + destino);
            return;
        }
        
        hanoi(n - 1, origem, auxiliar, destino);
        System.out.println("Mova o disco " + n + " de " + origem + " para " + destino);
        hanoi(n - 1, auxiliar, destino, origem);
    }

    public static void main(String[] args) {
        int numDiscos = 7; 
        hanoi(numDiscos, 'A', 'C', 'B');
    }
}
