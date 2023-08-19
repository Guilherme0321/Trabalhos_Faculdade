package IntroducaoAoJava;

public class Exercicio11 {

    public static boolean isIn(int x, int[] array){
        boolean ItIs = false;
        for (int i = 0; i < array.length; i++) {
            if(array[i] == x){
                ItIs = true;
                i = array.length;
            }
        }
        return ItIs;
    }

    public static void uniao(int[] array,int [] array1){
        System.out.print("Uniao : { ");

        for(int i = 0; i < array.length + array1.length; i++){
            if(i < array.length){
                System.out.print(array[i] + " ");
            }else{
                System.out.print(array1[i-array.length] + " ");
            }
        }
        System.out.print("}");
        
        System.out.println("");

        System.out.print("Intercesao : { ");

        for(int i = 0; i < array.length; i++){
            if(isIn(array[i], array1)){
                System.out.print(array[i] + " ");
            }
        }
        System.out.print("}");

    }
    public static void main(String[] args) {
        int[] x = {1,2,3,2,2,-5,9,-10};
        int[] y = {-5,8,7,4,2,3,1,2};
        uniao(x, y);
    }
}
