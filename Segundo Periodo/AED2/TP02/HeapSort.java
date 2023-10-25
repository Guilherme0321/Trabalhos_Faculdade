class Jogador {
    private Integer id;
    private String nome;
    private Integer altura;
    private Integer peso;
    private String universidade;
    private Integer ano_nasc;
    private String cidade_nasc;
    private String estado_nasc;

    public Jogador(){
        this.id = null;
        this.nome = null;
        this.altura = null;
        this.peso = null;
        this.universidade = null;
        this.ano_nasc = null;
        this.cidade_nasc = null;
        this.estado_nasc = null;
    }

    public Jogador(int id, String nome, int altura, int peso, String universidade, int ano_nasc, String cidade_nascimento, String estado_nascimento){
        this.id = id;
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
        this.universidade = universidade;
        this.ano_nasc = ano_nasc;
        this.cidade_nasc = cidade_nascimento;
        this.estado_nasc = estado_nascimento;
    }

    public int getId(){
        return this.id;
    }

    public String getNome(){
        return this.nome;
    }

    public int getAltura(){
        return this.altura;
    }

    public int getPeso(){
        return this.peso;
    }

    public String getUniversidade(){
        return this.universidade;
    }

    public int getAno_Nascimento(){
        return this.ano_nasc;
    }

    public String getCidade_Nascimento(){
        return this.cidade_nasc;
    }

    public String getEstado_Nascimento(){
        return this.estado_nasc;
    }

    public void setId(int id){
        this.id = id;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setAltura(int altura){
        this.altura = altura;
    }

    public void setPeso(int peso){
        this.peso = peso;
    }

    public void setUniversidade(String universidade){
        this.universidade = universidade;
    }

    public void setAno_Nascimento(int data_nascimento){
        this.ano_nasc = data_nascimento;
    }

    public void setCidade_Nascimento(String cidade_nascimento){
        this.cidade_nasc = cidade_nascimento;
    }

    public void setEstado_Nascimento(String estado_nascimento){
        this.estado_nasc = estado_nascimento;
    }

    public Jogador clone(){
        return new Jogador(id, nome, altura, peso, universidade, ano_nasc, cidade_nasc, estado_nasc);
    }
    @Override
    public String toString(){
        return "[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + universidade + " ## " + ano_nasc + " ## " + cidade_nasc + " ## " + estado_nasc + "]";
    }

    public void imprimir(){
        System.out.println("[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + ano_nasc + " ## " + universidade + " ## " + cidade_nasc + " ## " + estado_nasc + "]");
    }

    public static Jogador[] add(Jogador[] Player,Jogador player){
        Jogador[] players = new Jogador[Player.length+1];
        for(int i = 0; i < Player.length; i++){
            players[i] = Player[i];
        }
        players[Player.length] = player;
        return players;
    } 

    public static Jogador[] ler(){
        Arq.openRead("/tmp/players.csv");
        String x = Arq.readLine();
        String info = "";
        Jogador[] jogadores = new Jogador[0];
        while (Arq.hasNext()) {
            info = Arq.readLine();
            info = info.replace(",,", ",nao informado,");
            String[] infos = info.split(",");
            if(infos.length != 8){
                String[] newInfos = new String[infos.length+1];
                for(int i = 0; i < infos.length; i++){
                    newInfos[i] = infos[i];
                }
                newInfos[infos.length] = "nao informado";
                infos = newInfos;
            }
            
            jogadores = add(jogadores, new Jogador(
                Integer.parseInt(infos[0]), infos[1], Integer.parseInt(infos[2]),
                Integer.parseInt(infos[3]), infos[4], Integer.parseInt(infos[5]),
                infos[6], infos[7]
            ));
            
        }
        Arq.close();
        return jogadores;
    }
    
}

public class HeapSort {
    public static Jogador[] heap;

    public static void add(Jogador x) {
        if (heap == null) {
            heap = new Jogador[0];
        }
        Jogador[] newHeap = new Jogador[heap.length + 1];
        for (int i = 0; i < heap.length; i++) {
            newHeap[i] = heap[i];
        }
        newHeap[heap.length] = x;
        heap = newHeap;
    }

    public static boolean compararString(String x, String y){
        int lenX = x.length(), lenY = y.length();
        int minLength = (lenX < lenY) ? lenX : lenY;
        int i = 0;
        while(i < minLength && x.charAt(i) == y.charAt(i)){
            i++;
        }
        if(i == minLength){
            return lenX < lenY;
        }else{
            return x.charAt(i) < y.charAt(i);
        }
    }

    public static void heaping(int i, int tam) {
        int j = i, left = 2 * i + 1, right = 2 * i + 2;

        if (left < tam && heap[left].getAltura() < heap[j].getAltura()) {
            j = left;
        }else if(left < tam && heap[left].getAltura() == heap[j].getAltura() && compararString(heap[left].getNome(), heap[j].getNome())){
            j = left;
        }
        if (right < tam && heap[right].getAltura() < heap[j].getAltura()) {
            j = right;
        }else if(right < tam && heap[right].getAltura() == heap[j].getAltura() && compararString(heap[right].getNome(), heap[j].getNome())){
            j = right;
        }

        if (j != i) {
            Jogador temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            heaping(j,tam);
        }
    }

    public static void buildHeap() {
        for (int i = (heap.length / 2) - 1; i >= 0; i--) {
            heaping(i,heap.length);
        }
    }

    public static void sort() {
        Jogador[] sortedArr = new Jogador[heap.length];
        for(int i = heap.length - 1; i >= 0; i--){
            sortedArr[heap.length-i-1] = heap[0];
            heap[0] = heap[i];
            heaping(0, i);
        }
        heap = sortedArr;
    }
    

    public static void main(String[] args) {
        Jogador[] jogadores = Jogador.ler();
        String entrada = "";
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                add(jogadores[Integer.parseInt(entrada)]);
            }
        }

        buildHeap();
        sort();

        for (Jogador jogador : heap) {
            jogador.imprimir();
        }
    }
}