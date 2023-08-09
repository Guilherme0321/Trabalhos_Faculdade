package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Exercicio3 {

    public static boolean isLower(char x){
        return 'a' <= x && x <= 'z';
    }

    public static char charToUpper(char x){
        return isLower(x) ? (char)(x - 32) : x;
    }

    public static String toUppercase(String lower){
        String newString = "";
        for(int i = 0; i < lower.length(); i++){
            newString += charToUpper(lower.charAt(i));
        }
        return newString;
    }

    public static void main(String[] args) {
        try(BufferedReader arquivo = new BufferedReader(new FileReader("Teste.txt"))){
            String conteudo = "";
            while((conteudo = arquivo.readLine()) != null){
                System.out.println(toUppercase(conteudo));
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
    }
}
