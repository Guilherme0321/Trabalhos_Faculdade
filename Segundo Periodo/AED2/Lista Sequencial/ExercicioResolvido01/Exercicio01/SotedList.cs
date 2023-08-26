using System.Runtime;

class SortedList{
    private int[] lista;
    private int quantidade;

    public SortedList(){
        lista = new int[6];
        quantidade = 0;
    }
    
    public SortedList(int n){
        lista = new int[n];
        quantidade = 0;
    }
    
    public int search(int value){
        int meio = 0, start = 0, end = quantidade-1;
        while(start <= end){
            meio = (end+start)/2;
            if(value == lista[meio]){
                return meio;
            }
            else if(value < lista[meio]){
                end = meio-1;
            }else if(value > lista[meio]){
                start = meio+1;
            }
        }
        return start;
    }
    
    public void add(int value){
        if(quantidade < lista.Length){
            int pos = (quantidade > 0) ? search(value) : 0;
            for(int i = quantidade; i > pos; i--){
                lista[i] = lista[i-1];
            }
            lista[pos] = value;
            quantidade++;
        }else{
            int[] y = new int[lista.Length+6];
            for(int i = 0; i < lista.Length; i++){
                y[i] = lista[i];
            }
            lista = y;
            add(value);
        }
    }

    public void pop(){
        int[] arr = new int[lista.Length-1];
        for (int i = 0; i < lista.Length-1; i++){
            arr[i] = lista[i];
        }
        lista = arr;
    }

    public void pop_back(){
        int[] arr = new int[lista.Length-1];
        for(int i = 1; i < lista.Length; i++){
            arr[i-1] = lista[i];
        }
        lista = arr;
    }

    public void pop(int position){
        int[] arr = new int[lista.Length-1];
        for(int i = 0; i < position-1; i++){
            arr[i] = lista[i];
        }
        for(int i = position; i < lista.Length; i++){
            arr[i-1] = lista[i];
        }
        lista = arr;
    }

    public void Mostrar(){
        foreach(int x in lista){
            Console.Write($"{x} ");
        }
        Console.WriteLine();
    }
}