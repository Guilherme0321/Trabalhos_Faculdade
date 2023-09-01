public class PalindromoRecursivo {

    public static boolean isEquals(String x, String y, int i){
        if(i == x.length()){
            return true;
        }
        if(x.charAt(i) != y.charAt(i)){
            return false;
        }
        return isEquals(x, y,i+1);
    }
    public static boolean isEquals(String x, String y){
        if(x.length() == y.length()){
            return isEquals(x, y,0);
        }else{
            return false;
        }
    }
    
    public static boolean isPalindromo(String x,int i){
        if(i == (int)(x.length())/2){
            return true;
        }
        if(x.charAt(i) != x.charAt(x.length()-1-i)){
            return false;
        }
        return isPalindromo(x, i+1);
    }
    
    public static void startLoop(){
        String x = "";
        if(!isEquals(x, "FIM")){
            x = MyIO.readLine();
            if(isEquals(x, "FIM")){
                return;
            }
            if(isPalindromo(x, 0)){
                System.out.println("SIM");
            }else{
                System.out.println("NAO");
            }
            startLoop();
        }
    }

    public static void main(String[] args) {
        startLoop();
    }
}
