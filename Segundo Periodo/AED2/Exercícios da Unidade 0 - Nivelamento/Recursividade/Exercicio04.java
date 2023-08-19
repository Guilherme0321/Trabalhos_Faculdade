package Recursividade;

public class Exercicio04 {

    public static boolean isVogal(char x){
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
    }

    public static int loop(String x, int i){
        int q = 0;
        
        if(i < x.length()){
            if(isVogal(x.charAt(i))){
                q++;
            }
            q += loop(x, i+1);
        }
        
        return q;
    }

    public static int quantityVogais(String x){
        return loop(x, 0);
    }
    public static void main(String[] args) {
        System.out.println(quantityVogais("teste"));
    }
}
