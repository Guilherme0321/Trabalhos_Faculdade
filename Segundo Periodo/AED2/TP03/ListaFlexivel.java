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

public class ListaFlexivel {

    private Jogador head;

    public ListaFlexivel(){
        head = new Jogador();
    }

    public ListaFlexivel(int length){
        if(length <= 0){
            head = null;
        }else{
            head = new Jogador();
            Jogador temp = head.getNextPlayer();
            for(int i = 0; i < length; i++){
                temp.setNextPlayer(new Jogador());;
                temp = temp.getNextPlayer();
            }
        }
    }

    public void incerirInicio(Jogador x){
        if(x == null){
            System.out.println("Não é possivel inserir um jogador null");
        }else if(head.getNextPlayer() == null){
            head.setNextPlayer(x.clone());
        }else{
            Jogador temp = x.clone();
            temp.setNextPlayer(head.getNextPlayer());
            head.setNextPlayer(temp);
        }
    }

    public void incerirFinal(Jogador x) {
        if (x == null) {
            System.out.println("Não é possível inserir um jogador null.");
        } else {
            Jogador temp;
            if (head.getNextPlayer() == null) {
                head.setNextPlayer(x.clone());
            } else {
                for (temp = head.getNextPlayer(); temp.getNextPlayer() != null; temp = temp.getNextPlayer());
                temp.setNextPlayer(x.clone());
            }
        }
    }

    public void incerir(Jogador x,int pos){
        if(pos < 0 || x == null){
            System.out.println("Não é possivel inserir em uma posição menor que 0, ou o jogador é null");
        }else{
            int i = 0;
            Jogador temp;
            for(temp = head.getNextPlayer(); i < pos-1 && temp != null; i++ , temp = temp.getNextPlayer());
            if(i != pos-1){
                System.out.println("Posição invalida!");
            }else{
                Jogador temp2 = x.clone();
                temp2.setNextPlayer(temp.getNextPlayer());
                temp.setNextPlayer(temp2);
            }
        }
    }

    public Jogador removerInicio(){
        Jogador temp = head.getNextPlayer();
        head.setNextPlayer(temp.getNextPlayer());
        return temp;
    }

    public Jogador removerFinal(){
        Jogador temp;
        for(temp = head.getNextPlayer(); temp.getNextPlayer().getNextPlayer() != null; temp = temp.getNextPlayer());
        Jogador removed = temp.getNextPlayer();
        temp.setNextPlayer(removed.getNextPlayer());
        return removed;
    }

    public Jogador remover(int pos){
        Jogador removed = null;
        if(pos < 0){
            System.out.println("Não é possivel inserir em uma posição menor que 0");
        }else{
            Jogador temp;
            int i = 0;
            for(temp = head.getNextPlayer(); i < pos-1 && temp.getNextPlayer() != null; temp = temp.getNextPlayer(), i++);
            if(i != pos-1){
                System.out.println("Posição invalida!");
            }else{
                removed = temp.getNextPlayer();
                temp.setNextPlayer(removed.getNextPlayer());
            }
        }
        return removed;
    }

    public void showLista(){
        int i = 0;
        for(Jogador temp = head.getNextPlayer(); temp != null; temp = temp.getNextPlayer()){
            System.out.printf("[%d] %s\n",i,temp.toString());
            i++;
        }
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        ListaFlexivel list = new ListaFlexivel();
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(entrada.equals("FIM")){
                continue;
            }
            list.incerirFinal(play[Integer.parseInt(entrada)]);
        }
        int count = MyIO.readInt();
        while(count > 0){
            entrada = MyIO.readLine();
            String[] num;

            int pos = 0;
            if(entrada.charAt(0) == 'I'){
                num = entrada.split(" ");
                if(entrada.charAt(1) == '*'){
                    pos = Integer.parseInt(num[1]);
                    list.incerir(play[Integer.parseInt(num[2])], pos);
                }
                else if(entrada.charAt(1) == 'I'){
                    list.incerirInicio(play[Integer.parseInt(num[1])]);
                }else if(entrada.charAt(1) == 'F'){
                    list.incerirFinal(play[Integer.parseInt(num[1])]);
                }
            }else{
                if(entrada.charAt(1) == '*'){
                    num = entrada.split(" ");
                    pos = Integer.parseInt(num[1]);
                    System.out.println("(R) " + list.remover(pos).getNome());
                    
                }
                else if(entrada.charAt(1) == 'I'){
                    System.out.println("(R) " + list.removerInicio().getNome());

                }else if(entrada.charAt(1) == 'F'){
                    System.out.println("(R) " + list.removerFinal().getNome());
                }
            }
            
            count--;
        }
        list.showLista();
    }

}
