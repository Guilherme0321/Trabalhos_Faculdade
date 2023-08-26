public class Lista{
    private int[] arr;
    public int n;
    public Lista(){
        this.arr = new int[0];
        this.n = 0;
    }
    public Lista(int n){
        this.arr = new int[n];
        this.n = 0;
    }

    public void InserirInicio(int x){
        int[] y = new int[arr.Length+1];
        for(int i = 1; i <= arr.Length; i++){
            y[i] = arr[i - 1];
        }
        y[0] = x;
        arr = y;
        n++;
    }

    public void InserirFim(int x){
        int[] y = new int[arr.Length+1];
        for(int i = 0; i < arr.Length;i++){
            y[i] = arr[i];
        }
        y[arr.Length] = x;
        arr = y;
        n++;
    }

    public void RemoverInicio(){
        int[] y = new int[arr.Length-1];
        for(int i = 1; i < arr.Length;i++){
            y[i-1] = arr[i];
        }
        arr = y;
        n--;
    }
    
    public void RemoverFim(){
        int[] y = new int[arr.Length-1];
        for(int i = 0; i < arr.Length-1;i++){
            y[i] = arr[i];
        }
        arr = y;
        n--;
    }

    public void Inserir(int x, int pos){
        if(x < 0 || x >= arr.Length){
            Console.WriteLine("Indice fora da range");
            return;
        }
        int[] y = new int[arr.Length+1];
        y[x] = pos;
        for(int i = 0; i < x; i++){
            y[i] = arr[i]; 
        }
        for(int i = x; i < arr.Length; i++){
            y[i+1] = arr[i];
        }
        arr = y;
        n++;
    }

    public void Remover(int x){
        if(x < 0 || x >= arr.Length){
            Console.WriteLine("Indice fora da range");
            return;
        }
        int[] y = new int[arr.Length-1];
        for(int i = 0; i < x; i++){
            y[i] = arr[i];
        }
        for(int i = x; i < arr.Length-1;i++){
            y[i] = arr[i+1];
        }
        arr = y;
        n--;
    }

    public void Mostrar(){
        foreach (int item in arr){
            Console.Write($"{item} ");
        }
        Console.WriteLine();
    }

    public int somar(){
        int soma = 0;
        foreach (int item in arr)
        {
            soma += item;
        }
        return soma;
    }

    public int maior(){
        int maior = arr[0];
        for (int i = 1; i < arr.Length; i++)
        {
            if(maior < arr[i]){
                maior = arr[i];
            }        
        }
        return maior;
    }

    public void inverter(){
        int[] y = new int[arr.Length];
        for(int i = arr.Length; i > 0; i--){
            y[i-1] = arr[arr.Length-i];
        }
        arr = y;
    }

    public int paresMult5(){
        int count = 0;
        foreach (int item in arr)
        {
            count = (item % 2 == 0 && item % 5 == 0) ? count + 1: count;
        }
        return count;
    }
}