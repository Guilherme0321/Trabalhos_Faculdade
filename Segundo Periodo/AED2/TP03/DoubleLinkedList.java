import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Jogador {
    private Jogador nextPlayer;
    private Jogador beforePlayer;
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
        this.nextPlayer = null;
        this.beforePlayer = null;
    }

    public Jogador(Jogador x){
        this.id = x.getId();
        this.nome = x.getNome();
        this.altura = x.getAltura();
        this.peso = x.getPeso();
        this.universidade = x.getUniversidade();
        this.ano_nasc = x.getAno_Nascimento();
        this.cidade_nasc = x.getCidade_Nascimento();
        this.estado_nasc = x.getEstado_Nascimento();
        this.nextPlayer = x.getNextPlayer();
        this.beforePlayer = x.getBeforePlayer();
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
        this.nextPlayer = null;
        this.beforePlayer = null;
    }

    public void setBeforePlayer(Jogador x){
        this.beforePlayer = x;
    }

    public Jogador getBeforePlayer(){
        return this.beforePlayer;
    }

    public void setNextPlayer(Jogador x){
        this.nextPlayer = x;
    }

    public Jogador getNextPlayer(){
        return this.nextPlayer;
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
        return "[" + id + " ## " + nome + " ## " + altura + " ## " + peso + " ## " + ano_nasc + " ## " + universidade + " ## " + cidade_nasc + " ## " + estado_nasc + "]";
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
        File file = new File("/tmp/players.csv");
        Jogador[] jogadores = new Jogador[0];
        try {
            Scanner scanner = new Scanner(file);
            scanner.nextLine();
            String info = "";
            while (scanner.hasNextLine()) {
                info = scanner.nextLine();
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
            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return jogadores;
    }
    
}

public class DoubleLinkedList {
    
    private Jogador first;
    private Jogador last;

    public DoubleLinkedList(){
        first = null;
        last = null;
    }

    public DoubleLinkedList(int length){
        if(length >= 0){
            first = new Jogador();
            Jogador temp = first;
            temp.setBeforePlayer(null);
            for(int i = 0; i < length; i++){
                Jogador beJogador = temp;
                temp.setNextPlayer(new Jogador());
                temp = temp.getNextPlayer();
                temp.setBeforePlayer(beJogador);
            }
            last = temp;
        }else{
            System.out.println("Length menor que 0 é invalida");
        }
    }

    public Jogador getMeio(){
        Jogador ini = first, end = last;
        while (ini != end) {
            ini = ini.getNextPlayer();
            end = end.getBeforePlayer();
        }
        return ini;
    }

    public void add(Jogador next){ // add no final
        if(next == null){
            System.out.println("O jogador que está tentando adicionar é nulo!");
        }else if(first == null){
            first = next.clone();
            last = first;
        }else{
            Jogador temp = next.clone();
            temp.setBeforePlayer(last); // temp coloca o anterior como last
            last.setNextPlayer(temp); // last coloca o sucessor como temp
            last = temp; // muda a referencia do penultimo pro ultimo
        }
    }

    public void add(Jogador next, int pos){ // add into any position
        if(next == null){
            System.out.println("O jogador que está tentando adicionar é nulo!");
        }else if(first == null){
            first = next.clone();
            last = first;
        }else if(pos < 0){
            System.out.println("Posição invalida!");
        }else{
            int i = 0;
            Jogador temp;
            for(temp = first; i < (pos-1) && temp.getNextPlayer() != null; temp = temp.getNextPlayer(), i++);
            if(i != (pos-1)){
                System.out.println("Posição invalida!");
            }else{
                Jogador temp2 = next.clone();
                temp2.setBeforePlayer(temp); // coloca o anterior do temp2 como o temp
                temp2.setNextPlayer(temp.getNextPlayer()); // coloca o prox do temp2 como o proximo do temp, já que temp2 vai entrar no meio do temp e temp.getnext()
                temp.getNextPlayer().setBeforePlayer(temp2); // coloca o anterior do proximo do temp referenciando temp2
                temp.setNextPlayer(temp2); // agr coloca o prox do temp referenciando temp2 pq não vai mais perder a referencia do proximo
                if(temp2.getNextPlayer() == null){ // testa se temp2 for o ultimo, coloca o last referenciando ele
                    last = temp2;
                }
            }
        }
    }

    public void unshift(Jogador next){ // add no inicio
        if(next == null){
            System.out.println("O jogador que está tentando adicionar é nulo!");
        }else if(first == null){
            first = next.clone();
            last = first;
        }else{
            Jogador temp = next.clone();
            temp.setNextPlayer(first);
            temp.setBeforePlayer(null);
            first.setBeforePlayer(temp);
            first = temp;
        }
    }

    public Jogador pop(){ // remover final
        Jogador temp = null;
        if(first == null){
            System.out.println("Lista vazia!");
        }else{
            temp = last;
            last.getBeforePlayer().setNextPlayer(null);
            last = last.getBeforePlayer();
        }
        return temp;
    }

    public Jogador pop(int pos){ // remover em qual posição
        Jogador temp = null;
        if(first == null){
            System.out.println("Lista vazia!");
        }else if(pos < 0){
            System.out.println("Posição invalida!");
        }else{
            int i = 0;
            Jogador j = first;
            while(i < (pos-1) && j.getNextPlayer() != null){
                i++;
                j = j.getNextPlayer();
            }
            if(i != (pos-1)){
                System.out.println("Posição invalida!");
            }else{
                temp = j.getNextPlayer();
                j.setNextPlayer(temp.getNextPlayer());
            }
        }
        return temp;
    }

    public Jogador shift(){ // remover inicio
        Jogador temp = null;
        if(first == null){
            System.out.println("Lista vazia!");
        }else{
            temp = first;
            first = first.getNextPlayer();
        }
        return temp;
    }

    public void showList(){
        for(Jogador i = first; i != null; i = i.getNextPlayer()){
            i.imprimir();
        }
    }

    public boolean compereString(String x, String y){
        int lenX = x.length(), lenY = y.length(), i = 0;
        int minLength = (lenX < lenY) ? lenX : lenY;
        while(i < minLength && x.charAt(i) == y.charAt(i)){
            i++;
        }
        if(i == minLength){
            return lenX < lenY;
        }else{
            return x.charAt(i) < y.charAt(i);
        }
    }

    private void setAllAtibutos(Jogador x, Jogador y){ // coloca os atributos de y em x sem mudar a referencia
        x.setId(y.getId());
        x.setNome(y.getNome());
        x.setAltura(y.getAltura());
        x.setPeso(y.getPeso());
        x.setUniversidade(y.getUniversidade());
        x.setAno_Nascimento(y.getAno_Nascimento());
        x.setCidade_Nascimento(y.getCidade_Nascimento());
        x.setEstado_Nascimento(y.getEstado_Nascimento());
    }

    private void swap(Jogador x, Jogador y){ // troca os atributos de x para y e vice versa
        Jogador temp = new Jogador(x);
        setAllAtibutos(x, y);
        setAllAtibutos(y, temp);
    }

    private Jogador partition(Jogador ini, Jogador fim){
        Jogador pivo = fim, i = ini.getBeforePlayer();
        for(Jogador j = ini; j != fim; j = j.getNextPlayer()){
            if(compereString(j.getEstado_Nascimento(), pivo.getEstado_Nascimento())){
                i = (i == null) ? ini : i.getNextPlayer(); // testar se i == null, se for, quer dizer que está no inicio por causa do ini.getbefore la em cima
                swap(i, j);
            }
        }
        i = (i == null) ? ini : i.getNextPlayer();
        swap(i, pivo);
        return i;
    }

    private void sort(Jogador ini, Jogador end){
        if(ini != null && end != null && ini != end && ini != end.getNextPlayer()){ // testar se ini e end são diferentes de null e se ini for diferente do proximo dps de end, porque porque o ini pode passar pra um jogador depois do end antes de haver a comparação
            Jogador temp = partition(ini, end);
            sort(ini,temp.getBeforePlayer()); // temp.before porque é do lugar onde parou - 1 pra não ordenar repetido
            sort(temp.getNextPlayer(),end); // temp.next porque é do lugar onde parou + 1 pra não ordenar repetido
        }
    }

    private void sortByName() {
        for(Jogador i = first; i != null; i = i.getNextPlayer()){
            for(Jogador j = first; j.getNextPlayer() != null; j = j.getNextPlayer()){
                if(j.getEstado_Nascimento().equals(j.getNextPlayer().getEstado_Nascimento()) && compereString(j.getNextPlayer().getNome(), j.getNome())){
                    swap(j.getNextPlayer(), j);
                }
            }
        }
    }

    public void sort(){
        sort(first,last);
        sortByName();
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        DoubleLinkedList list = new DoubleLinkedList();
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            list.add(play[Integer.parseInt(entrada)]);
        }
        list.sort();
        list.showList();
    }
}
