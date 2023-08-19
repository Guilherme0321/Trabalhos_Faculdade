package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Exercicio2 {
    public static void main(String[] args) {
        try(BufferedReader arquivo = new BufferedReader(new FileReader("Teste.txt"))){
            String linha = "";
            while((linha = arquivo.readLine()) != null){
                System.out.println(linha);
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
