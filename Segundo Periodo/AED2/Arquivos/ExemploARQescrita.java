package Arquivos;

import java.io.FileWriter;
import java.util.Formatter;
import java.io.IOException;

public class ExemploARQescrita {
    private static Formatter arquivo = null;

    public static boolean openWrite(String pasta) throws IOException{
        arquivo = new Formatter(new FileWriter(pasta));
        if(arquivo != null){
            return true;
        }else{
            return false;
        }
    }

    public static void Write(String text){
        arquivo.format("%s", text);
    }
    public static void Write(char text){
        arquivo.format("%c", text);
    }
    public static void Write(int text){
        arquivo.format("%d", text);
    }
    public static void Write(Double text){
        arquivo.format("%lf", text);
    }
    public static void Write(float text){
        arquivo.format("%f", text);
    }

    public static void Writeln(String text){
        arquivo.format("%s\n", text);
    }
    public static void Writeln(int text){
        arquivo.format("%d\n", text);
    }
    public static void Writeln(Double text){
        arquivo.format("%lf\n", text);
    }
    public static void Writeln(float text){
        arquivo.format("%f\n", text);
    }
    public static void Writeln(char text){
        arquivo.format("%c\n", text);
    }

    public static void close(){
        arquivo.close();
    }
}