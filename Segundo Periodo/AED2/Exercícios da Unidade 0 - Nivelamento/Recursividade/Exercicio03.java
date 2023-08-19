package Recursividade;

public class Exercicio03 {

    public static boolean isLetter(char x){
        return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
    }

    public static boolean isEquals(char i, char j){
        return i == j;
    }

    public static boolean isPalindromo(String x, int i){
        boolean isP = false;
        if(i >= x.length()/2){
            isP = true;
        }else if(!isEquals(x.charAt(i), x.charAt(x.length()-i-1))){
            isP = false;
        }else{
            isP = isPalindromo(x, i+1);
        }
        return isP;
    }
    public static void main(String[] args) {
        System.out.println(isPalindromo("arara",0));
    }
}
