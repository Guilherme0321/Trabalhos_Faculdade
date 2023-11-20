import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Jogador {
    private Jogador esq;
    private Jogador dir;
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
        this.esq = null;
        this.dir = null;
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
        this.esq = null;
        this.dir = null;
    }

    public Jogador getDir(){
        return dir;
    }

    public Jogador getEsq(){
        return esq;
    }

    public void setEsq(Jogador temp){
        this.esq = temp;
    }

    public void setDir(Jogador temp){
        this.dir = temp;
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

public class BinarySearchTree {

    private Jogador raiz;

    private Jogador add(Jogador player, Jogador no){
        if(no == null){
            no = player.clone(); 
        }else if(no.getNome().compareTo(player.getNome()) < 0){
            no.setDir(add(player, no.getDir()));
        }else if(no.getNome().compareTo(player.getNome()) > 0){
            no.setEsq(add(player, no.getEsq()));
        }
        return no;
    }

    public void add(Jogador player){
        raiz = add(player, raiz);
    }

    public String search(String name, Jogador no){
        if(no == null){
            return " NAO";
        }else if(no.getNome().equals(name)){
            return " SIM";
        }else if(no.getNome().compareTo(name) < 0){
            return " dir" + search(name, no.getDir());
        }else if(no.getNome().compareTo(name) > 0){
            return " esq" + search(name, no.getEsq());
        }else{
            System.out.println("ERRO");
            return "";
        }
    }

    public String search(String name){
        return name + " raiz" + search(name, raiz);
    }

    private void showTree(Jogador no){
        if(no == null){
            return;
        }
        showTree(no.getEsq());
        System.out.println(no.getNome());
        showTree(no.getDir());
    }

    public void showTree(){
        showTree(raiz);
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        BinarySearchTree tree = new BinarySearchTree();
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            tree.add(play[Integer.parseInt(entrada)]);
        }
        entrada = "";
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }
            String response = tree.search(entrada);
            System.out.println(response);
        }
    }    
}
