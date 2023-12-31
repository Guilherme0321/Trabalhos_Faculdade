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

class No2{
    private String key;
    private No2 esq, dir;

    public No2(){
        key = null;
        esq = null;
        dir = null;
    }

    public No2(Jogador x){
        key = x.getNome();
        esq = null;
        dir = null;
    }

    public void setKey(String key){
        this.key = key;
    }

    public void setEsq(No2 temp){
        this.esq = temp;
    }

    public void setDir(No2 temp){
        this.dir = temp;
    }

    public String getKey(){
        return this.key;
    }

    public No2 getEsq(){
        return this.esq;
    }

    public No2 getDir(){
        return this.dir;
    }
}

class No{
    private Integer key;
    private No esq, dir;
    private No2 root;

    public No(){
        key = null;
        esq = null;
        dir = null;
        root = null;
    }

    public No(Jogador key){
        this.key = key.getAltura();
        esq = null;
        dir = null;
        root = null;
    }

    public int getKey(){
        return key;
    }

    public void setKey(int key){
        this.key = key;
    }
    
    public No getDir(){
        return this.dir;
    }

    public void setDir(No x){
        this.dir = x;
    }

    public No getEsq(){
        return this.esq;
    }

    public void setEsq(No x){
        this.esq = x;
    }

    public void setRoot(No2 root){
        this.root = root;
    }

    public No2 getRoot(){
        return this.root;
    }
}

public class BinarySearchTreeTree {
    private No raiz;

    public BinarySearchTreeTree(){
        raiz = null;
    }

    private No2 add(Jogador element, No2 j){
        if(j == null){
            j = new No2(element);
        }else if(element.getNome().compareTo(j.getKey()) < 0){
            j.setEsq(add(element, j.getEsq()));
        }else if(element.getNome().compareTo(j.getKey()) > 0){
            j.setDir(add(element, j.getDir()));
        }
        return j;
    }


/*     private No add2(Jogador element, No i){
        if(i == null){
            return i;
        }else if(element.getAltura() < i.getKey()){
            i.setEsq(add2(element, i.getEsq()));
        }else if(element.getAltura() > i .getKey()){
            i.setDir(add2(element, i.getDir()));
        }else{
            i.setRoot(add(element, i.getRoot()));
        }
        return i;
    } */

    private No add(Jogador element, No i){
        if(i == null){
            i = new No(element);
            //i.setRoot(new No2(element));
        }else if(element.getAltura() < i.getKey()){
            i.setEsq(add(element, i.getEsq()));
        }else if(element.getAltura() > i.getKey()){
            i.setDir(add(element, i.getDir()));
        }else if(element.getAltura() == i.getKey()){
            i.setRoot(add(element, i.getRoot()));
        }
        return i;
    }

/*     public void addSecond(Jogador element){
        this.raiz = add2(element, raiz);
    } */

    public void add(Jogador element){
        this.raiz = add(element, raiz);
    }

    public void searchSecondTree(Jogador temp, No2 i){
        if(i == null){
            System.out.println(" NAO");
        }else if(temp.getNome().equals(i.getKey())){
            System.out.println(" SIM");
        }else if(temp.getNome().compareTo(i.getKey()) < 0){
            System.out.print(" ESQ");
            searchSecondTree(temp, i.getEsq());
        }else if(temp.getNome().compareTo(i.getKey()) > 0){
            System.out.print(" DIR");
            searchSecondTree(temp, i.getDir());
        }
    }

    public void search(Jogador temp, No i){
        if(i == null){
            System.out.println(" NAO");
        }else if(i.getKey() == temp.getAltura()){
            searchSecondTree(temp, i.getRoot());
        }else if(temp.getAltura() < i.getKey()){
            System.out.print(" ESQ");
            search(temp, i.getEsq());
        }else if(temp.getAltura() > i.getKey()){
            System.out.print(" DIR");
            search(temp, i.getDir());
        }
    }

    private boolean mostrarSecondTree(No2 i, String x, boolean found){
        if(i == null){
            return found;
        }

        //System.out.printf(" %s\n", i.getKey());
        if(!found){
            if(!found){
                System.out.printf(" ESQ");
            }
            found = mostrarSecondTree(i.getEsq(), x, found);
            if(x.equals(i.getKey())){
                System.out.printf(" SIM");
                return true;
            }
            if(!found){
                System.out.printf(" DIR");
            }
            found = mostrarSecondTree(i.getDir(), x, found);
        }  

        return found;
    }

    private boolean mostrarFirstTree(No i, String x, boolean found){
        if(i == null){
            return found;
        }
        if(!found){
            if(!found){
                System.out.printf(" esq");
            }
            found = mostrarFirstTree(i.getEsq(), x, found);
            found = mostrarSecondTree(i.getRoot(), x, false);
            if(!found){
                System.out.printf(" dir");
            }
            found = mostrarFirstTree(i.getDir(), x, found);
        }

        return found;
    }

    public void mostrar(String x){
        if(!mostrarFirstTree(raiz, x, false)){
            System.out.printf(" NAO");
        }
        System.out.println();
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
    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        BinarySearchTreeTree tree = new BinarySearchTreeTree();

        tree.add(play[7]);
        tree.add(play[3]);
        tree.add(play[11]);
        tree.add(play[1]);
        tree.add(play[5]);
        tree.add(play[9]);
        tree.add(play[13]);
        tree.add(play[0]);
        tree.add(play[2]);
        tree.add(play[4]);
        tree.add(play[6]);
        tree.add(play[8]);
        tree.add(play[10]);
        tree.add(play[12]);
        tree.add(play[14]);

        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            int index = Integer.parseInt(entrada);
            tree.add(play[index]);
        }
        entrada = "";
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                break;
            }
            Jogador temp = search(play, entrada);
            System.out.printf("%s raiz", entrada);
            tree.mostrar(entrada);
            //tree.search(temp, tree.raiz);
        }
    }  
}
