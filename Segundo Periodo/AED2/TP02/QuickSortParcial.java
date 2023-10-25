import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javax.print.attribute.standard.JobMessageFromOperator;
import javax.swing.JOptionPane;

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
            String x = scanner.nextLine();
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

public class QuickSortParcial {
    public static Jogador[] jogadores;

    public static boolean compereString(String x, String y){
        int lenX = x.length(), lenY = y.length();
        int minLength = (lenX < lenY) ? lenX : lenY;
        int i = 0;
        while(i < minLength && x.charAt(i) == y.charAt(i)){
            i++;
        }
        if(i == minLength){
            return (x.length() < y.length());
        }else{
            return (x.charAt(i) < y.charAt(i));
        }
    }

    public static void quickSort(int left, int right, int k) {
        int i = left, j = right, meio = (left + right) / 2;
        while (i <= j) {
            while (compereString(jogadores[i].getEstado_Nascimento(), jogadores[meio].getEstado_Nascimento())) {
                i++;
            }
            while (compereString(jogadores[meio].getEstado_Nascimento(), jogadores[j].getEstado_Nascimento())) {
                j--;
            }
            if (i <= j) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[i];
                jogadores[i] = temp;
                i++;
                j--;
            }
        }
        if (left < j) {
            quickSort(left, j, k);
        }
        if (i < k && i < right) {
            quickSort(i, right, k);
        }
    }
    
    public static void sortByName(int k){
        for(int i = 0; i < k; i++){
            Jogador key = jogadores[i];
            int j = i - 1;
            while(j >= 0 && jogadores[j].getEstado_Nascimento().equals(key.getEstado_Nascimento()) && compereString(key.getNome(), jogadores[j].getNome())){
                jogadores[j+1] = jogadores[j];
                j--;
            }
            jogadores[j+1] = key;
        }
    }

    public static void main(String[] args) {
        Jogador[] players = Jogador.ler();
        jogadores = new Jogador[0];
        String entrada = "";
        while(!entrada.equals("FIM")){
            entrada = MyIO.readLine();
            if(!entrada.equals("FIM")){
                jogadores = Jogador.add(jogadores, players[Integer.parseInt(entrada)]);
            }
        }
        quickSort(0, jogadores.length-1, 10);
        sortByName(10);
        for(int i = 0; i < 10; i++){
            jogadores[i].imprimir();
        }
    }
}
