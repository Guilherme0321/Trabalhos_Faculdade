import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class Jogador {
    private boolean color;
    private Jogador esq, dir;
    
    public String nome;
    private Integer id;
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
        this.color = false;
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
        this.color = false;
        this.esq = null;
        this.dir = null;
    }

    public void setColor(boolean i){
        this.color = i;
    }
    public void setEsq(Jogador temp){
        this.esq = temp;
    }
    public void setDir(Jogador temp){
        this.dir = temp;
    }
    public boolean getColor(){
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

   public void inserir(Jogador elemento) {
      if (raiz == null) {
         raiz = elemento.clone();

      } else if (raiz.getEsq() == null && raiz.getDir() == null) {
         if (elemento.getNome().compareTo(raiz.getNome()) < 0) {
            raiz.setEsq(elemento.clone());
         } else {
            raiz.setDir(elemento.clone());
         }

      } else if (raiz.getEsq() == null) {
         if (elemento.getNome().compareTo(raiz.getNome()) < 0) {
            raiz.setEsq(elemento.clone());

         } else if (elemento.getNome().compareTo(raiz.getDir().getNome()) < 0) {
            raiz.setEsq(raiz.clone());
         } else {
            raiz.setEsq(raiz.clone());;
            raiz.setNome(raiz.getDir().getNome());
         }
        raiz.getEsq().setColor(false);
        raiz.getDir().setColor(false);

      } else if (raiz.getDir() == null) {
         if (elemento.getNome().compareTo(raiz.getNome()) > 0) {
            raiz.setDir(elemento.clone());
         } else if (elemento.getNome().compareTo(raiz.getNome()) > 0) {
            raiz.setDir(raiz.clone());;
         } else {
            raiz.setDir(raiz.clone());
            raiz.setNome(raiz.getEsq().getNome());
         }
         raiz.getEsq().setColor(false);
         raiz.getDir().setColor(false);
      } else {
         inserir(elemento, null, null, null, raiz);
      }
      raiz.setColor(false);
   }

   private void balancear(Jogador bisavo, Jogador avo, Jogador pai, Jogador i) {
      if (pai.getColor() == true) {
         if (pai.getNome().compareTo(avo.getNome()) > 0) {
            if (i.getNome().compareTo(pai.getNome()) > 0) {
               avo = rotacaoEsq(avo);
            } else {
               avo = rotacaoDirEsq(avo);
            }
         } else {
            if (i.getNome().compareTo(pai.getNome()) < 0) {
               avo = rotacaoDir(avo);
            } else {
               avo = rotacaoEsqDir(avo);
            }
         }
         if (bisavo == null) {
            raiz = avo;
         } else if (avo.getNome().compareTo(bisavo.getNome()) < 0) {
            bisavo.setEsq(avo);
         } else {
            bisavo.setDir(avo);
         }
         avo.setColor(false);
         avo.getEsq().setColor(true);
         avo.getDir().setColor(true);
      }
   }

   private void inserir(Jogador elemento, Jogador bisavo, Jogador avo, Jogador pai, Jogador i){
      if (i == null) {
         if (elemento.getNome().compareTo(pai.getNome()) < 0) {
            i = elemento.clone();
            pai.setEsq(elemento.clone());
            i.setColor(true);
         } else {
            i = elemento.clone(); 
            pai.setDir(elemento.clone());
            i.setColor(true);
         }
         if (pai.getColor() == true) {
            balancear(bisavo, avo, pai, i);
         }
      } else {
         if (i.getEsq() != null && i.getDir() != null && i.getEsq().getColor() == true && i.getDir().getColor() == true) {
            i.setColor(true);
            i.getEsq().setColor(false);
            i.getDir().setColor(false);
            if (i == raiz) {
               i.setColor(false);
            } else if (pai.getColor() == true) {
               balancear(bisavo, avo, pai, i);
            }
         }
         if (elemento.getNome().compareTo(i.getNome()) < 0) {
            inserir(elemento, avo, pai, i, i.getEsq());
         } else if (elemento.getNome().compareTo(i.getNome()) > 0) {
            inserir(elemento, avo, pai, i, i.getDir());
         }
      }
   }

   private Jogador rotacaoDir(Jogador no) {
      Jogador noEsq = no.getEsq();
      Jogador noEsqDir = noEsq.getDir();

      noEsq.setDir(no);
      no.setEsq(noEsqDir);

      return noEsq;
   }

   private Jogador rotacaoEsq(Jogador no) {
      Jogador noDir = no.getDir();
      Jogador noDirEsq = noDir.getEsq();

      noDir.setEsq(no);
      no.setDir(noDirEsq);
      return noDir;
   }

   private Jogador rotacaoDirEsq(Jogador no) {
      no.setDir(rotacaoDir(no.getDir()));
      return rotacaoEsq(no);
   }

   private Jogador rotacaoEsqDir(Jogador no) {
      no.setEsq(rotacaoEsq(no.getEsq()));
      return rotacaoDir(no);
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
            tree.inserir(play[Integer.parseInt(entrada)]);
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
