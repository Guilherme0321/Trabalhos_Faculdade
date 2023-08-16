package Recursividade;

public class Exercicio01 {

    public static int multiplicar(int x, int y){
        if(y == 0){
            return 0;
        }
        return x + multiplicar(x, y-1);
    }
    public static void main(String[] args) {
        System.out.println(multiplicar(3, 10));
    }
}
