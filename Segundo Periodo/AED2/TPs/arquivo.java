import java.io.RandomAccessFile;

public class arquivo {
    public static void printar(String x){
        int len = x.length();
        if(x.charAt(len-2) == '.' && x.charAt(len-1) == '0'){
            len -= 2;
        }
        for(int i = 0; i < len; i++){
            System.out.print(x.charAt(i));
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int n = MyIO.readInt();
        int i = 0;
        float nums = 0;
        String texto = "";
        try {
            RandomAccessFile file = new RandomAccessFile("numbers.txt","rw");
            while(i < n){
                nums = MyIO.readFloat();
                file.writeChars(nums + "\n");
                i++;
            }
            file.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            RandomAccessFile file = new RandomAccessFile("numbers.txt","rw");
            long len = file.length();
            file.seek(file.length());
            char letra;
            texto = "";
            long counter = 1;
            while(counter < len){
                file.seek(len-counter-1);
                letra = (char)file.readByte();    
                if(letra == '\n'){
                    printar(texto);
                    texto = "";
                    counter++;
                }else{
                    texto = (('0' <= letra && letra <= '9') || letra == '.') ? (letra + texto) : texto;
                }
                counter++;
            }
            System.out.println(texto);
            file.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}