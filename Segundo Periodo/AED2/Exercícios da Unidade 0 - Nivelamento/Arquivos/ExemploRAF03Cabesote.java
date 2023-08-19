package Arquivos;

import java.io.IOException;
import java.io.RandomAccessFile;

public class ExemploRAF03Cabesote {

    public static void main(String[] args) {
        try(RandomAccessFile arquivo = new RandomAccessFile("Teste.txt", "rw")){
            arquivo.writeBytes("ola mundo!");
            arquivo.seek(3);
            arquivo.writeChar('_');
            arquivo.close();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }

    }
}