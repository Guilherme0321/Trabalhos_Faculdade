import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;


public class TP01Q07 {
    public static int[] info = new int[25];

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

    public static void includes(String frase,String palavra){
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
                info[22]++;
            }
        }
    }

//a e i o u á é í ó ú à è ì ò ù ã õ â ê î ô û 
    public static void counter(String x){
        int i = 0, len = x.length();
        for(int j = 0; i < info.length; i++){
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
                    case 'á':
                        info[5]++;
                        break;
                    case 'é':
                        info[6]++;
                        break;
                    case 'í':
                        info[7]++;
                        break;
                    case 'ó':
                        info[8]++;
                        break;
                    case 'ú':
                        info[9]++;
                        break;
                    case 'à':
                        info[10]++;
                        break;
                    case 'è':
                        info[11]++;
                        break;
                    case 'ì':
                        info[12]++;
                        break;
                    case 'ò':
                        info[13]++;
                        break;
                    case 'ù':
                        info[14]++;
                        break;
                    case 'ã':
                        info[15]++;
                        break;
                    case 'õ':
                        info[16]++;
                        break;
                    case 'â':
                        info[17]++;
                        break;
                    case 'ê':
                        info[18]++;
                        break;
                    case 'î':
                        info[19]++;
                        break;
                    case 'ô':
                        info[20]++;
                        break;
                    case 'û':
                        info[21]++;
                        break;
                }
            }
            i++;
        }
    }


    public static void main(String[] args) {
        String name = "", link = "", conteudo = "";
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
                includes(conteudo, "<table>");
                System.out.println(info[22]+ " " + name);
                reader.close();
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }
}