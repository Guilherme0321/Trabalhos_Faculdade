package Recursividade;

public class Exercicio05 {

    public static boolean isVogal(char x){
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
    }

    public static int QnotVogal(String x, int i){
        int q = 0;
        if(i < x.length()){
            if(!isVogal(x.charAt(i))){
                q++;
            }
            q += QnotVogal(x, i+1);
        }
        return q;
    }

    public static int QnotConsoante(String x, int i){
        int q = 0;
        if(i < x.length()){
            if(isVogal(x.charAt(i))){
                q++;
            }
            q += QnotConsoante(x, i+1);
        }
        return q;
    }
    public static void main(String[] args) {
        System.out.println(QnotVogal("arara", 0) + " " + QnotConsoante("arara", 0));
    }
}
