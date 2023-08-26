public class Deque{
    private int[] arr;
    public int n;
    public Deque(){
        this.arr = new int[0];
        this.n = 0;
    }
    public Deque(int n){
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

    public void Mostrar(){
        foreach (int item in arr){
            Console.Write($"{item} ");
        }
        Console.WriteLine();
    }
}