package IntroducaoAoJava;

public class Exercicio10 {

    public static int particao(int[] array, int ini, int fim){
        int pivo = array[fim];
        int j = ini -1;

        for(int i = ini; i < fim; i++){
            if(array[i] < pivo){
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
            int i = particao(array, ini, fim);
            quickSort(array, ini, i - 1);
            quickSort(array, i + 1, fim);
        }
    }
    public static void main(String[] args) {
        int[] array = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
        quickSort(array, 0, array.length-1);
        for(int i : array){
            System.out.print(i + " ");
        }
    }
}

