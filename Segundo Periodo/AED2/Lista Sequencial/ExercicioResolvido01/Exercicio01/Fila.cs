public class Fila{
    private int[] arr;
    private int frente;
    private int tras;
    private int maxLength;
    private int quantidade;
    
    public Fila(int n){
        this.arr = new int[n];
        this.maxLength = n;
        this.frente = 0;
        this.tras = -1;
        this.quantidade = 0;
    }

    public void enfileirar(int x){
        if(quantidade < maxLength){
            this.tras = (tras+1) % maxLength;
            quantidade++;
            arr[tras] = x;
        }else{
            Console.WriteLine("Fila Cheia!");
        }
    }

    public void desenfileirar(){
        if(quantidade <= maxLength){
            this.frente = (frente+1) % maxLength;
            quantidade--;
        }else{
            Console.WriteLine("Fila vazia!");
        }
    }

    public void Mostrar(){
        for(int i = 0; i < quantidade; i++){
            Console.Write(arr[(frente+i)%maxLength]);
        }
        Console.WriteLine();
    }

}