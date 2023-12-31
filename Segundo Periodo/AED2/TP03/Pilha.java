import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Jogador {
    private Jogador nextPlayer;
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
        return "## " + nome + " ## " + altura + " ## " + peso + " ## " + ano_nasc + " ## " + universidade + " ## " + cidade_nasc + " ## " + estado_nasc + " ## ";
    }

    public void imprimir(){
        System.out.println(" ## " + nome + " ## " + altura + " ## " + peso + " ## " + ano_nasc + " ## " + universidade + " ## " + cidade_nasc + " ## " + estado_nasc + " ## ");
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
        File file = new File("players.csv");
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

public class Pilha {

    Jogador topo;

    public Pilha(){
        topo = null;
    }

    public void add(Jogador player){
        if(topo == null){
            topo = player.clone();
        }else{
            Jogador temp = player.clone();
            temp.setNextPlayer(topo);
            topo = temp;
        }
    }

    public Jogador pop() throws Exception{
        Jogador temp;
        if(topo == null){
            throw new Exception("Pilha vazia!");
        }else{
            temp = topo;
            topo = topo.getNextPlayer();
        }
        return temp;
    }

    public void showJogadores(Jogador temp, int i){
        if(temp == null){
            return;
        }
        showJogadores(temp.getNextPlayer(), i-1);
        System.out.printf("[%d] %s\n", i, temp.toString());
    }

    public void showPilha(){
        int length = countJogadores();
        showJogadores(topo,length-1);
    }

    public int countJogadores(){
        int i = 0;
        for(Jogador temp = topo; temp != null; i++, temp = temp.getNextPlayer());
        return i;
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        Pilha pilha = new Pilha();
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            pilha.add(play[Integer.parseInt(entrada)]);
        }
        int counter = MyIO.readInt(), i = 0;
        while (i < counter) {
            String[] sep;
            if(i == counter-1){
                break;
            }
            entrada = MyIO.readLine();
            if (entrada.charAt(0) == 'R') {
                try {
                    System.out.println("(R) " + pilha.pop().getNome());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            } else {
                sep = entrada.split(" ");
                pilha.add(play[Integer.parseInt(sep[1])]);
            }
            i++;
        }
        pilha.showPilha();
    }
}