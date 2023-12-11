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

class No{
    private char key;
    private No[] characteres;
    private boolean isWord;

    public No(char key){
        this.key = key;
        characteres = new No[255];
        this.isWord = false;
    }

    public int hash(char i){
        return (int)(i)%characteres.length;
    }
    public void setNo(No i, char key){
        int index = hash(key);
        characteres[index] = i;
    }
    public No getNo(char key){
        int index = hash(key);
        return characteres[index];
    }
    public void setNo(No i, int pos){
        characteres[pos] = i;
    }
    public No getNo(int pos){
       return characteres[pos];
    }
    public char getKey(){
        return key;
    }
    public void setKey(char i){
        this.key = i;
    }
    public boolean isWord(){
        return this.isWord;
    }
    public void setWordStatus(boolean i){
        this.isWord = i;
    }
    public No[] getNos(){
        return characteres;
    }
}

public class Trie {
    private No raiz;

    public Trie(){
        raiz = new No('\0'); // char qualquer
    }

/*     private void add(String name, No i, int j){
        if(i.getNo(name.charAt(j)) == null){
            No temp = new No(name.charAt(j));
            i.setNo(temp, name.charAt(j));

            if(j == name.length()-1){
                i.getNo(name.charAt(j)).setWordStatus(true);
            }else{
                add(name, i.getNo(name.charAt(j)), j+1);
            }
        }else if(j < name.length()){
            add(name, i.getNo(name.charAt(j)), j+1);
        }
    }

    public void add(String name){
        add(name, raiz, 0);
    } */

    public void add(String name){
        int len = name.length();
        int i = 0;
        No no = raiz;
        while(i < len){
            if(no.getNo(name.charAt(i)) == null){
                No temp = new No(name.charAt(i));
                no.setNo(temp, name.charAt(i));
            }
            no = no.getNo(name.charAt(i));
            i++;
        }
        no.setWordStatus(true);
    }

    private boolean search(String name, No i, int j){
        if(i.getNo(name.charAt(j)) == null){
            System.out.println(" NAO");
            return false;
        }else if(j == name.length()-1 && i.getNo(name.charAt(j)).isWord()){
            System.out.println(" SIM");
            return true;
        }else if(j < name.length() -1){
            return search(name, i.getNo(name.charAt(j)), j+1);
        }else{
            System.out.println(" NAO");
            return false;
        }
    }

    public boolean search(String name){
        return search(name, raiz, 0);
    }

    private void show(No i, String x){
        if(i.isWord()){
            System.out.println(x + i.getKey());
        }
        for(int j = 0; j < i.getNos().length; j++){
            if(i.getNos()[j] != null){
                show(i.getNos()[j], x + i.getKey());
            }
        }
    }

    private static void fundir(No tree1, No tree2){
        if(tree1 == null || tree2 == null){
            return;
        }
        for(int j = 0; j < tree1.getNos().length; j++){
            if(tree1.getNos()[j] == null && tree2.getNos()[j] != null){
                tree1.setNo(tree2.getNos()[j], j);
            }else{
                fundir(tree1.getNos()[j], tree2.getNos()[j]);
            }
        }
    }

    public void fundir(Trie x){
        fundir(this.raiz, x.raiz);
    }

    public void show(){
        show(raiz, "");
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        Trie tree = new Trie();
        Trie tree2 = new Trie();
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            int index = Integer.parseInt(entrada);
            Jogador temp = play[index];
            String nome = temp.getNome();
            System.out.printf("%d %s\n", index, nome);
            tree.add(play[index].getNome());
        }
        entrada = "";
        while (!entrada.equals("FIM")) {
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            int index = Integer.parseInt(entrada);
            Jogador temp = play[index];
            String nome = temp.getNome();
            System.out.printf("%d %s\n", index, nome);
            tree2.add(play[index].getNome());
        }
        tree.fundir(tree2);
        entrada = "";
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            System.out.print(entrada);
            tree.search(entrada);
        }
    }
}
