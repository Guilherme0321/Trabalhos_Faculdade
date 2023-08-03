import java.util.Scanner;
public class Guia01 {
    
    public boolean isNumber(String test){
        int quantity = 0;
        for(int i = 0; i < test.length(); i++){
            if('0' <= test.charAt(i) && test.charAt(i) <= '9'){
                quantity++;
            }
        }
        if(quantity == test.length()){
            return true;
        }else{
            return false;
        }
    }

    public int toInt(String decimal){
        int dec = 0;
        boolean test = isNumber(decimal);
        if(test){
            for(int i = 0; i < decimal.length(); i++){
                dec = (int) Math.pow(10,decimal.length() - 1 - i) * (decimal.charAt(i) - 48);
            }
            return dec;
        }else{
            System.out.println("Ha uma letra que nao eh um numeral!");
            return 0;
        }
    }

    public String toBinario(int num){
        String convertido = "";
        while(num > 0){
            convertido = (num % 2) + convertido;
            num /= 2;
        }
        return convertido;
    }

    public boolean isEquals(String one, String two){
        if(one.length() == two.length()){
            for(int i = 0; i < one.length(); i++){
                if(one.charAt(i) != two.charAt(i)){
                    return false;
                }
            }
        }else{
            return false;
        }
        return true;
    }

    public void conversor() {
        String num = "";
        int number = 0;
        Scanner scanner = new Scanner(System.in);
        while(num != "end"){
            System.out.println("Digite end para sair do loop!");
            System.out.print("Digite o numero que deseja converter para binario: ");
            num = scanner.nextLine();
            if(isEquals(num, "end")){
                break;
            }
            number = toInt(num);
            System.out.println(toBinario(number));
        }
    }
    
}