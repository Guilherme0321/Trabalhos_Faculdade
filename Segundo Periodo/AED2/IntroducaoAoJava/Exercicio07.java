package IntroducaoAoJava;

public class Exercicio07 {
    public static void main(String[] args) {
        float x = 8, y = 512;
        if( x < y){
            System.out.println(Math.cbrt(x) + " " + Math.log(x) / Math.log(y));
        }else{
            System.out.println(Math.cbrt(y) + " " + Math.log(y) / Math.log(x));
        }
    }
}
