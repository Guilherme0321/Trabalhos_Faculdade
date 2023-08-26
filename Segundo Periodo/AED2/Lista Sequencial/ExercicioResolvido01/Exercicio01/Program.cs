class Programa{
    public static void Main(string[] args){
        /* Lista x = new Lista();
        x.InserirInicio(5);
        x.InserirInicio(4);
        x.InserirInicio(3);
        x.InserirInicio(50);
        Console.WriteLine("Inserir inicio: ");
        x.InserirInicio(1);
        x.Mostrar();
        Console.WriteLine("Inserir fim: ");
        x.InserirFim(10);
        x.Mostrar();
        Console.WriteLine("Inserir: ");
        x.Inserir(5,-4);
        x.Mostrar();
        Console.WriteLine("Remover inicio: ");
        x.RemoverInicio();
        x.Mostrar();
        Console.WriteLine("Remover fim: ");
        x.RemoverFim();
        x.Mostrar();
        Console.WriteLine("Remover: ");
        x.Remover(1);
        x.Mostrar();
        Console.WriteLine(x.somar());
        Console.WriteLine(x.maior());
        x.inverter();
        x.Mostrar();
        Console.WriteLine(x.paresMult5()); */


        /* Fila fila = new Fila(5);
        fila.enfileirar(5); 
        fila.enfileirar(3); 
        fila.enfileirar(6); 
        fila.enfileirar(4); 
        fila.enfileirar(10);
        fila.Mostrar();
        fila.desenfileirar();
        fila.Mostrar();
        fila.desenfileirar();
        fila.Mostrar();
        fila.enfileirar(10);
        fila.Mostrar(); */

        /* Pilha pilha = new Pilha(5);
        pilha.empilhar(5);
        pilha.empilhar(-7);
        pilha.empilhar(3);
        pilha.Mostrar();
        pilha.desempilhar();
        pilha.Mostrar(); */

        /* SortedList list = new SortedList();
        list.add(3);
        list.add(2);
        list.add(1);
        list.add(3);
        list.add(7);
        list.add(9);
        list.Mostrar();
        list.pop();
        list.pop_back();
        list.pop(3);
        list.Mostrar(); */

        Deque deque = new Deque(5);
        deque.InserirInicio(7);
        deque.InserirInicio(3);
        deque.InserirInicio(4);
        deque.InserirInicio(9);
        deque.InserirInicio(1);
        deque.Mostrar();
    }

}