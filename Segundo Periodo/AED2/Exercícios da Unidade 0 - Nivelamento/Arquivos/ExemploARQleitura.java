package Arquivos;

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class ExemploARQleitura {
    private static Scanner scanner = null;
    private static int line = 0;

    public static boolean openRead(String url) throws FileNotFoundException{
        scanner = new Scanner(new File(url));
        if(scanner != null){
            return true;
        }else{
            return false;
        }
    }

    public static String readLine(){
        line++;
        return scanner.nextLine();
    }

    public static void close(){
        scanner.close();
    }

    public static boolean hasNextLine(){
        return scanner.hasNextLine();
    }

    public static int getLine(){
        return line;
    }
}