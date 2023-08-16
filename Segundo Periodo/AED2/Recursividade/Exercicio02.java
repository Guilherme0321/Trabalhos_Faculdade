package Recursividade;

public class Exercicio02 {
    public static int bigger(int[] array,int tamanho, int i){
        int resul;
        if(i == tamanho -1){
            resul = array[tamanho-1];
        }else{
            resul = bigger(array, tamanho, i+1);
            if(resul < array[i]){
                resul = array[i];
            }
        }
        return resul;
    }
    public static void main(String[] args) {
        int[] x = {4,2,3,1,6,5,7,9,8};
        System.out.print(bigger(x, 9,0));
    }
}
