import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Jogador {
    private int color;
    private Jogador esq, dir, parent;
    

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
        this.color = 1;
        this.esq = null;
        this.dir = null;
        this.parent = null;
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
        this.color = 1;
        this.esq = null;
        this.dir = null;
        this.parent = null;
    }

    public void setColor(int i){
        this.color = i;
    }
    public void setEsq(Jogador temp){
        this.esq = temp;
    }
    public void setDir(Jogador temp){
        this.dir = temp;
    }
    public void setParent(Jogador temp){
        this.parent = temp;
    }
    public Jogador getParent(){
        return this.parent;
    }
    public int getColor(){
        return this.color;
    }
    public Jogador getEsq(){
        return this.esq;
    }
    public Jogador getDir(){
        return this.dir;
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

public class RedBlackTree {

    private Jogador raiz;

    public RedBlackTree(){
        raiz = null;
    }

    public void rotacionarDir(Jogador no){
        if(no == null){
            return;
        }

        Jogador temp = no.getEsq();
        no.setEsq(temp.getDir());

        temp.setParent(no.getParent());

        if(temp.getDir() != null){
            temp.getDir().setParent(no);;
        }

        if(no == no.getParent().getDir()){
            no.getParent().setDir(temp);
        }else{
            no.getParent().setEsq(temp);
        }

        no.setParent(temp);
        temp.setDir(no);
    }

    public void rotacionarEsq(Jogador no){
        if(no == null){
            return;
        }

        Jogador temp = no.getDir();
        no.setDir(temp.getEsq());

        temp.setParent(no.getParent());

        if(temp.getEsq() != null){
            temp.getEsq().setParent(no);;
        }

        if(no == no.getParent().getDir()){
            no.getParent().setDir(temp);
        }else{
            no.getParent().setEsq(temp);
        }

        no.setParent(temp);
        temp.setEsq(no);
    }

    public void fixInsetion(Jogador no) {
        Jogador temp;
        while (no.getParent().getColor() == 1) {
            if (no.getParent() == no.getParent().getParent().getEsq()) {
                temp = no.getParent().getParent().getDir();
                if (temp.getColor() == 1) {
                    temp.setColor(0);
                    no.getParent().setColor(0);
                    no.getParent().getParent().setColor(1);
                    no = no.getParent().getParent();
                } else {
                    if (no == no.getParent().getDir()) {
                        no = no.getParent();
                        rotacionarEsq(no);
                    }
                    no.getParent().setColor(0);
                    no.getParent().getParent().setColor(1);
                    rotacionarDir(no.getParent().getParent());
                }
            } else {
                temp = no.getParent().getParent().getEsq();
                if (temp.getColor() == 1) {
                    temp.setColor(0);
                    no.getParent().setColor(0);
                    no.getParent().getParent().setColor(1);
                    no = no.getParent().getParent();
                } else {
                    if (no == no.getParent().getEsq()) {
                        no = no.getParent();
                        rotacionarDir(no);
                    }
                    no.getParent().setColor(0);
                    no.getParent().getParent().setColor(1);
                    rotacionarEsq(no.getParent().getParent());
                }
            }
            if (no == raiz) {
                break;
            }
        }
        raiz.setColor(0);
    }

    public  void add(Jogador element){
        Jogador temp = raiz;
        Jogador tempParent = null;

        while(temp != null){
            tempParent = temp;
            if(element.getNome().compareTo(temp.getNome()) < 0){
                temp = temp.getEsq();
            }else if(element.getNome().compareTo(temp.getNome()) > 0){
                temp = temp.getDir();
            }
        }

        element.setParent(tempParent);

        if(tempParent == null){
            raiz = element;
        }else if(element.getNome().compareTo(tempParent.getNome()) < 0){
            tempParent.setEsq(element.clone());
        }else if(element.getNome().compareTo(tempParent.getNome()) > 0){
            tempParent.setDir(element.clone());
        }

        if(element.getParent() == null){
            element.setColor(0);
            return;
        }

        if(element.getParent().getParent() == null){
            return;
        }
        fixInsetion(element);
    }

    private void show(Jogador temp){
        if(temp == null){
            return;
        }
        show(temp.getEsq());
        System.out.println(temp.getNome());
        show(temp.getDir());
    }

    public void show(){
        show(raiz);
    }

    public void search(String element, Jogador i){
        if(i == null){
            System.out.print(" NAO\n");
        }else if(element.equals(i.getNome())){
            System.out.print(" SIM\n");
        }else if(element.compareTo(i.getNome()) < 0){
            System.out.print(" esq");
            search(element, i.getEsq());
        }else if(element.compareTo(i.getNome()) > 0){
            System.out.print(" dir");
            search(element, i.getDir());
        }
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        RedBlackTree tree = new RedBlackTree();
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
                continue;
            }
            System.out.print(entrada + " raiz");
            tree.search(entrada, tree.raiz);
        }
    }
}
