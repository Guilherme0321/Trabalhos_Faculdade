package IntroducaoAoJava;

public class Exercicio08 {

    public static int smaller(int[] x){
        int j = 0;
        for(int i = 0; i < x.length; i++){
            if(x[j] > x[i]){
                j = i;
            }
        }
        return x[j];
    }

    public static int bigger(int[] x){
        int i = 0;
        for(int j = 0; j < x.length; j++){
            if(x[i] < x[j]){
                i = j;
            }
        }
        return x[i];
    }

    public static void main(String[] args) {
        int[] x = {0,1,5,60,2,3,7,34,4,-4};
        System.out.print("Maior: " + bigger(x) + "\nMenor: " + smaller(x));
    }
}
