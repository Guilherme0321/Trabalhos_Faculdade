package Recursividade;

public class Exercicio06 {

    public static int particao(int[] array, int ini, int fim){
        int j = ini -1;
        for(int i = ini; i < fim; i++){
            if(array[i] < array[fim]){
                j++;
                int x = array[i];
                array[i] = array[j];
                array[j] = x;
            }
        }
        int x = array[j+1];
        array[j+1] = array[fim];
        array[fim] = x;
        return j + 1;
    }

    public static void quickSort(int[] array, int ini, int fim){
        if(ini < fim){
            int pivo = particao(array, ini, fim);
            quickSort(array, pivo + 1, fim);
            quickSort(array, ini, pivo - 1);
        }
    }
    public static void main(String[] args) {
        int[] x = {2,1,3,9,8,6,5,4,7};
        quickSort(x, 0, x.length-1);
        for (int i : x) {
            System.out.printf("%d ", i);
        }
    }
}
