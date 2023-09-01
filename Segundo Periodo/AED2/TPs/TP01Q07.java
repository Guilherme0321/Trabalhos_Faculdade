import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.UnsupportedEncodingException;
import java.net.URL;


public class TP01Q07 {
    public static int[] info = new int[25];
    
    public static boolean isLetter(char x){
        return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
    }
    
    public static boolean isVogal(char x){
        return x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U';
    }

    public static boolean isEquals(String x, String y){
        boolean isequal = true;
        if(x.length() == y.length()){
            for(int i = 0; i < x.length(); i++){
                if(x.charAt(i) != y.charAt(i)){
                    isequal = false;
                    i = y.length();
                }
            }
        }else{
            isequal = false;
        }
        return isequal;
    }

    public static void includes(String frase,String palavra,int pos){
        int fraseLen = frase.length(), palavraLen = palavra.length();
        if(fraseLen < palavraLen){
            return;
        }
        for(int i = 0; i <= fraseLen-palavraLen;i++){
            boolean isTrue = true;
            for(int j = 0; j < palavraLen; j++){
                if(frase.charAt(i+j) != palavra.charAt(j)){
                    isTrue = false;
                    j = palavraLen;
                }
            }
            if(isTrue){
                info[pos]++;
            }
        }
    }

    public static void counter(String x){
        int i = 0, len = x.length();
        
        for(int j = 0; j < info.length; j++){
            info[j] = 0;
        }
        while(i < len){
            if(x.charAt(i) != ' '){
                switch(x.charAt(i)){
                    case 'a':
                        info[0]++;
                        break;
                    case 'e':
                        info[1]++;
                        break;
                    case 'i':
                        info[2]++;
                        break;
                    case 'o':
                        info[3]++;
                        break;
                    case 'u':
                        info[4]++;
                        break;
                    case '\u00E1':
                        info[5]++;
                        break;
                    case '\u00E9':
                        info[6]++;
                        break;
                    case '\u00ED':
                        info[7]++;
                        break;
                    case '\u00F3':
                        info[8]++;
                        break;
                    case '\u00FA':
                        info[9]++;
                        break;
                    case '\u00E0':
                        info[10]++;
                        break;
                    case '\u00E8':
                        info[11]++;
                        break;
                    case '\u00EC':
                        info[12]++;
                        break;
                    case '\u00F2':
                        info[13]++;
                        break;
                    case '\u00F9':
                        info[14]++;
                        break;
                    case '\u00E3':
                        info[15]++;
                        break;
                    case '\u00F5':
                        info[16]++;
                        break;
                    case '\u00E2':
                        info[17]++;
                        break;
                    case '\u00EA':
                        info[18]++;
                        break;
                    case '\u00EE':
                        info[19]++;
                        break;
                    case '\u00F4':
                        info[20]++;
                        break;
                    case '\u00FB':
                        info[21]++;
                        break;
                }
            }
            i++;
        }
    }

    public static void consoante(String x){
        for(int i = 0; i < x.length(); i++){
            if(isLetter(x.charAt(i)) && !isVogal(x.charAt(i))){
                info[22]++;
            }
        }
    }

    public static void main(String[] args) {
        String name = "", link = "", conteudo = "";
        try {
            System.setOut(new PrintStream(System.out, true, "UTF-8"));
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        while(!isEquals(name, "FIM")){
            name = MyIO.readLine();
            if(isEquals(name, "FIM")){
                continue;
            }
            link = MyIO.readLine();
            try {
                URL url = new URL(link);
                BufferedReader reader = new BufferedReader(new InputStreamReader(url.openStream()));
                String line = "";
                while((line = reader.readLine()) != null){
                    conteudo += line;
                }
                
                counter(conteudo);
                includes(conteudo, "<table>",24);
                includes(conteudo, "<br>", 23);
                consoante(conteudo);
                System.out.println("a(" + info[0] + ") " +"e(" + info[1] + ") " +"i(" + info[2] + ") " +"o(" + info[3] + ") " +"u(" + info[4] + ") " +"\u00E1(" + info[5] + ") " +"\u00E9(" + info[6] + ") " +"\u00ED(" + info[7] + ") " +"\u00F3(" + info[8] + ") " +"\u00FA(" + info[9] + ") " +"\u00E0(" + info[10] + ") " +"\u00E8(" + info[11] + ") " +"\u00EC(" + info[12] + ") " +"\u00F2(" + info[13] + ") " +"\u00F9(" + info[14] + ") " +"\u00E3(" + info[15] + ") " +"\u00F5(" + info[16] + ") " +"\u00E2(" + info[17] + ") " +"\u00EA(" + info[18] + ") " +"\u00EE(" + info[19] + ") " +"\u00F4(" + info[20] + ") " +"\u00FB(" + info[21] + ") " +"consoante(" + info[22] + ") " +"<br>(" + info[23] + ") " +"<table>(" + info[24] + ") " + name);
                reader.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
            conteudo = "";

        }
    }
}