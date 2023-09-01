import java.io.PrintStream;
import java.io.UnsupportedEncodingException;

class Main{
  public static boolean isequals(String x, String y){
        int len = x.length(), leny = y.length();
        boolean isTrue = true;
        if(len != leny){
            isTrue = false;
        }else{
            for (int i = 0; i < len; i++) {
                if(x.charAt(i) != y.charAt(i)){
                    isTrue = false;
                  i = len;
                }
            }
        }
        return isTrue;
  }
    public static void main(String[] args){
        try {
            System.setOut(new PrintStream(System.out, true, "UTF-8"));
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        String x = "", y = "";
        
        while(!isequals(x,"FIM")){
            x = MyIO.readLine();
          if(isequals(x,"FIM")){
                continue;
            }
            y = "";
            for (int i = 0; i < x.length(); i++) {
                char currentChar = x.charAt(i);
                if (currentChar != '\u00E0') { // Exemplo: '\u00E0' representa 'à'
                    y += (char)(currentChar + 3);
                } else {
                    y += currentChar; // Mantém o caractere acentuado original
                }
            }
        MyIO.print(y + "\n");
        }
        
        
    }
}