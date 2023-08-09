package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Exercicio04 {

    public static void Write_aquivo(String conteudo){
        try(BufferedWriter arquivo = new BufferedWriter(new FileWriter("Saida.txt",true))){
            arquivo.append(conteudo);
            arquivo.newLine();
            arquivo.close();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        String conteudo = "";
        try(BufferedReader arquivo = new BufferedReader(new FileReader("Teste.txt"))){
            while((conteudo = arquivo.readLine()) != null){
                Write_aquivo(conteudo);
            }
            arquivo.close();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
