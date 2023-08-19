package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Exercicio07 {

    public static boolean isLetter(char letra){
        return (('a' <= letra && letra <= 'z') || ('A' <= letra && letra <= 'Z'));
    }

    public static boolean menor_XYZ(char x){
        return (x != 'z' && x != 'Z' && x != 'x' && x != 'X' && x != 'y' && x != 'Y');
    }

    public static boolean is_XYZ(char x){
        return (x == 'z' || x == 'Z' || x == 'y' || x == 'Y' || x == 'x' || x == 'X');
    }

    public static String toCifraCezar(String txt){
        char caractere = ' ';
        String newTxt = "";
        for(int i = 0; i < txt.length(); i++){
            caractere = txt.charAt(i);
            if(isLetter(caractere) && menor_XYZ(caractere)){
                caractere += 3;
            }else if(is_XYZ(caractere)){
                caractere -= 23;
            }
            newTxt += caractere;
        }
        return newTxt;
    }

    public static String LerArquivo(String nome){
        String conteudo = "", temp = "";
        try(BufferedReader arquivo = new BufferedReader(new FileReader(nome))){
            while((temp = arquivo.readLine()) != null){
                conteudo += temp + "\n";
            }
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
        return conteudo;
    }

    public static void main(String[] args) {
        System.out.println(toCifraCezar(LerArquivo("Teste.txt")));
    }
}
