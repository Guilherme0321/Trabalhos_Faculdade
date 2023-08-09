package Arquivos;

import java.io.IOException;
import java.io.RandomAccessFile;

public class ExemploRAF01escrita {
    public static void main(String[] args) {
        try (RandomAccessFile arquivo = new RandomAccessFile("testes.txt", "rw")) {
            arquivo.writeInt(5);
            arquivo.writeBoolean(false);
            arquivo.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }    
    
}