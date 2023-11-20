import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

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


public class ListaSequencial {
    private int quantidade;
    private Jogador[] players;

    public ListaSequencial(){
        this.players = new Jogador[0];
        quantidade = 0;
    }

    public ListaSequencial(int length){
        this.players = new Jogador[length];
        quantidade = 0;
    }

    private void moveElements(int index){
        Jogador[] temp = null;
        if(index < players.length){
            temp = new Jogador[players.length+1];
        }else{
            temp = new Jogador[index+1];
        }
        int j = 0, i = 0;
        while(j < players.length){
            if(i != index){
                temp[i] = players[j++];
            }
            i++;
        }
        players = temp;
    }

    public void resize(int x){
        moveElements(x);
    }

    public void incerirInicio(Jogador x){
        resize(0);
        players[0] = x;
        quantidade++;
    }

    public void incerir(Jogador x, int posicao){
        resize(posicao);
        players[posicao] = x;
        quantidade++;
    }

    public void incerirFinal(Jogador x){
        resize(quantidade);
        players[quantidade] = x;
        quantidade++;
    }

    public Jogador removerInicio(){
        Jogador[] temp = new Jogador[players.length-1];
        Jogador removed = players[0];
        for(int i = 1; i < players.length; i++){
            temp[i-1] = players[i]; 
        }
        players = temp;
        quantidade--;
        return removed;
    }
    public Jogador removerFinal(){
        Jogador[] temp = new Jogador[players.length-1];
        Jogador removed = players[quantidade-1];
        for(int i = 0; i < players.length-1; i++){
            temp[i] = players[i]; 
        }
        quantidade--;
        players = temp;
        return removed;
    }
    public Jogador remover(int index){
        Jogador[] temp = new Jogador[players.length-1];
        int j = 0;
        Jogador removed = players[index];
        for(int i = 0; i < players.length; i++){
            if(i != index){
                temp[j++] = players[i];
            }
        }
        quantidade--;
        players = temp;
        return removed;
    }

    public void printar(){
        int i = 0;
        for (Jogador jogador : players) {
            if(jogador != null){
                System.out.printf("[%d] %s\n", i, jogador.toString());
            }
            i++;
        }
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        ListaSequencial list = new ListaSequencial();
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
        list.printar();
    }
}
