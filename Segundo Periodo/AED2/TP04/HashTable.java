import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Jogador {
    private Jogador esq;
    private Jogador dir;
    private Jogador raiz;

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
        this.raiz = null;
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
        this.raiz = null;
    }

    public Jogador getRaiz(){
        return raiz;
    }

    public void setRaiz(Jogador temp){
        this.raiz = temp;
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


class No{
    private Integer key;
    private Jogador value;

    public No(){
        this.key = null;
        this.value = null;
    }

    public No(Jogador value){
        this.key = value.getAltura();
        this.value = value;
    }

    public int getKey(){
        return key;
    }
    public Jogador getValue(){
        return value;
    }
}

public class HashTable {
    private No[] players;
    private No[] reserva;

    public HashTable(){
        players = new No[21];
        reserva = new No[9];
    }

    private int hashPlayers(int i){
        return i % players.length;
    }

    public void add(Jogador temp){
        int i = hashPlayers(temp.getAltura());
        if(players[i] == null){
            players[i] = new No(temp);
        }else{
            for(int j = 0; j < reserva.length; j++){
                if(reserva[j] == null){
                    reserva[j] = new No(temp);
                    j = reserva.length;
                }
            }
        }
    }

    public static Jogador search(Jogador[] players, String nome){
        Jogador temp = null;
        for(int i = 0; i < players.length; i++){
            String tempName = players[i].getNome();
            boolean isEquals = true;
            for(int j = 0; j < nome.length(); j++){
                if(tempName.charAt(j) != nome.charAt(j)){
                    j = nome.length();
                    isEquals = false;
                }
            }
            if(isEquals){
                temp = players[i];
                i = players.length;
            }
        }
        return temp;
    }

    public boolean search(int height, String name){
        int i = hashPlayers(height);
        if(players[i] == null){
            return false;
        }else if(players[i].getKey() == height){
            return name.equals(players[i].getValue().getNome());
        }else{
            for(int j = 0; j < reserva.length; j++){
                if(reserva[j].getKey() == height){
                    return name.equals(reserva[j].getValue().getNome());
                }
            }

        }
        return false;
    }

    public void show(){
        for(No i : players){
            System.out.println(i.getValue());
        }
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        HashTable hash = new HashTable();

        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            int index = Integer.parseInt(entrada);
            hash.add(play[index]);
        }
        entrada = "";
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }
            Jogador temp = HashTable.search(play, entrada);
            boolean isIN = hash.search(temp.getAltura(), entrada);
            if(isIN){
                System.out.printf("%s SIM\n", entrada);
            }else{
                System.out.printf("%s NAO\n", entrada);
            }
        }
    }  
}
