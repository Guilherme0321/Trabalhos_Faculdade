package Recursividade;

public class Exercicio08 {
    public static int elevado(int x){
        return elevado(x-1, 2);
    }
    public static int elevado(int x,int i){;
        if(i == 1){
            return x;
        }
        return x * elevado(x, i-1);
    }
    public static void main(String[] args) {
        System.out.println(elevado(4));
    }
}
