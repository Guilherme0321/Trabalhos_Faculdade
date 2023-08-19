package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Exercicio05 {

    public static void WriteToupper(String conteudo){
        try(BufferedWriter arquivo = new BufferedWriter(new FileWriter("Saida.txt",true))){
            String newConteudo = "";
            for(int i = 0; i < conteudo.length(); i++){
                newConteudo += toUpper(conteudo.charAt(i));
            }
            arquivo.write(newConteudo);
            arquivo.newLine();
            arquivo.close();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }

    public static boolean isLower(char x){
        return ('a' <= x && x <= 'z');
    }

    public static char toUpper(char x){
        return isLower(x) ? (char) ( x - 32 ) : x;
    }

    public static void main(String[] args) {
        String conteudo = "";
        try(BufferedReader arquivo = new BufferedReader(new FileReader("Teste.txt"))){
            while((conteudo = arquivo.readLine()) != null){
                WriteToupper(conteudo);
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}