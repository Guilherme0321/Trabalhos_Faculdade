package Arquivos.Exercicios_slide_30_ao_33;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Exercicio08 {

    public static String LerAqruivo(String nome){
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

    public static boolean isLetter(char letra){
        return ('a' <= letra && letra <= 'z') || ('A' <= letra && letra <= 'Z');
    }

    public static boolean is_ABC(char letra){
        return (letra != 'a' && letra != 'A' && letra != 'b' && letra != 'B' && letra != 'c' && letra != 'C');
    }

    public static char convert(char letra){
        return is_ABC(letra) ? (char) (letra - 3) : (char)(letra + 23);
    }

    public static String Descriptografar(String texto){
        String newTexto = "";
        char temp = ' ';
        for(int i = 0; i < texto.length(); i++){
            temp = texto.charAt(i);
            if(isLetter(temp)){
                temp = convert(temp);
            }
            newTexto += temp;
        }
        return newTexto;
    }

    public static void main(String[] args) {
        System.out.println(Descriptografar(LerAqruivo("CifraDeCezar.txt")));
    }
}
