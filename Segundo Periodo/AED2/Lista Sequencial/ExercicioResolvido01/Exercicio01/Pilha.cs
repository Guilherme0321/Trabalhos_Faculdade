class Pilha{
    private int[] pilha;
    private int topo;
    public Pilha(int capacidade){
        pilha = new int[capacidade];
        topo = -1;
    }

    public bool isEmpty(){
        return topo == -1;
    }

    public int length(){
        return topo+1;
    }

    public void empilhar(int x){
        if(topo < pilha.Length-1){
            topo++;
            pilha[topo] = x;
        }else{
            Console.WriteLine("Pilha cheia!");
        }
    }

    public void desempilhar(){
        if(topo > -1){
            topo--;
        }else{
            Console.WriteLine("Pilha vazia!");
        }
    }

    public void Mostrar(){
        for(int i = topo; i >= 0; i--){
            Console.Write($"{pilha[i]} ");
        }
        Console.WriteLine();
    }

}