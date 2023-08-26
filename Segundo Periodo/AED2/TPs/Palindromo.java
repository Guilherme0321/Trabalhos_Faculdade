import java.util.Scanner;
public class Palindromo {
    public static boolean isPalimdromo(String x){
        int i = 0;
        boolean is = true;
        while(i < x.length()){
            if(x.charAt(i)!=x.charAt(x.length()-i-1)){
                is = false;
            }
            i++;
        }
        return is;
    }
    public static void main(String[] args){
        String x = "";
        Scanner scanner = new Scanner(System.in);
        while(!x.equals("FIM") && scanner.hasNextLine()){
             x = scanner.nextLine();
            if(x.equals("FIM")){
                break;
            }
           
            if(isPalimdromo(x)){
                System.out.println("SIM");
            }else{
                System.out.println("NAO");
            }
        }
        scanner.close();
    }
}