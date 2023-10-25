import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

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


public class CountingSort {

    public static Jogador[] players;

    public static void countingSort() {
        int maxAltura = getMaxAltura();
        Jogador[] sortedArr = new Jogador[players.length];
        int[] countArr = new int[maxAltura + 1];

        for (Jogador jogador : players) {
            countArr[jogador.getAltura()]++;
        }

        for (int i = 1; i <= maxAltura; i++) {
            countArr[i] += countArr[i - 1];
        }

        Jogador[] auxArr = new Jogador[players.length];
        for (int i = players.length - 1; i >= 0; i--) {
            auxArr[countArr[players[i].getAltura()] - 1] = players[i];
            countArr[players[i].getAltura()]--;
        }

        countArr = new int[maxAltura + 1];
        for (int i = 0; i < players.length; i++) {
            countArr[auxArr[i].getAltura()]++;
        }

        for (int i = 1; i <= maxAltura; i++) {
            countArr[i] += countArr[i - 1];
        }

        for (int i = players.length - 1; i >= 0; i--) {
            sortedArr[countArr[auxArr[i].getAltura()] - 1] = auxArr[i];
            countArr[auxArr[i].getAltura()]--;
        }

        copyArray(sortedArr, players);
        //ordenar pelo nome quando altura for igual
        int n = players.length / 2;
        while (n > 0){
            for (int i = n; i < players.length; i++){
                Jogador key = players[i];
                int j = i - 1;
                while (j >= 0 && key.getAltura() == players[j].getAltura() && compareString(key.getNome(), players[j].getNome())){
                    players[j + 1] = players[j];
                    j--;
                }
                players[j + 1] = key;
            }
            n /= 2;
        }
    }

    private static int getMaxAltura() {
        int max = players[0].getAltura();
        for (Jogador jogador : players) {
            if (jogador.getAltura() > max) {
                max = jogador.getAltura();
            }
        }
        return max;
    }

    public static boolean compareString(String x, String y) {
        int lenX = x.length();
        int lenY = y.length();
        int minLen = (lenX < lenY) ? lenX : lenY;
        int i = 0;
        
        while (i < minLen && x.charAt(i) == y.charAt(i)) {
            i++;
        }
        
        if (i == minLen) {
            return lenX < lenY;
        } else {
            return x.charAt(i) < y.charAt(i);
        }
    }

    public static void copyArray(Jogador[] source, Jogador[] destination) {
        for (int i = 0; i < source.length; i++) {
            destination[i] = source[i];
        }
    }

    public static void main(String[] args) {
        String entrada = "";
        Jogador[] play = Jogador.ler();
        players = new Jogador[0];
        while (!entrada.equals("FIM")) {
            entrada = MyIO.readLine();
            if (!entrada.equals("FIM")) {
                players = Jogador.add(players, play[Integer.parseInt(entrada)]);
            }
        }
        countingSort();
        for (Jogador x : players) {
            x.imprimir();
        }
    }
}

