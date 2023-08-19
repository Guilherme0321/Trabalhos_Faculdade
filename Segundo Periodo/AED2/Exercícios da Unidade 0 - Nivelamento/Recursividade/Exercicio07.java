package Recursividade;

public class Exercicio07 {
    
    public static int calcFatorial(int x){
        if(x != 0){
            return fatorial(x);
        }else{
            return 1;
        }
    }

    public static int fatorial(int x){
        int y = x;
        if(x > 1){
            y *= fatorial(x-1);
        }
        return y;
    }
    public static void main(String[] args) {
        System.out.println(calcFatorial(5));
    }  
}
