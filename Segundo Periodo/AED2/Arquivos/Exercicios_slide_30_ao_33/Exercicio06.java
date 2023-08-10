package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Exercicio06 {

    public static void WriteInverso(String nome, String txt){
        int len = txt.length()-1;
        try(BufferedWriter arquivo = new BufferedWriter(new FileWriter(nome))){
            while(len >= 0){
                arquivo.write(txt.charAt(len));
                len--;
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }

    public static String lerArquivo(String url){
        String conteudo = "", temp = "";
        try(BufferedReader arquivo = new BufferedReader(new FileReader(url))){
            while((temp = arquivo.readLine()) != null){
                conteudo += temp + "\n";
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
        return conteudo;
    }
    public static void main(String[] args) {
        WriteInverso("Saida.txt",lerArquivo("Teste.txt"));
    }
}
