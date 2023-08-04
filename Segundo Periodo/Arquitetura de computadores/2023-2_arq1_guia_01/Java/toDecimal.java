package Java;

import java.util.Scanner;

public class toDecimal {
    private String recivedNumber = "";
    private String convertedNumber = "";

    public boolean isBinary(String test){
        int len = test.length();
        for(int i = 0; i < len; i++){
            if(!('0' <= test.charAt(i) && test.charAt(i) <= '1')){
                return false;
            }
        }
        return true;
    }

    public void setB_Number(String num){
        if(isBinary(num)){
            this.convertedNumber = "";
            this.recivedNumber = num;
            convert();
        }else{
            System.out.println("O numero nao eh binario!");
        }
    }

    public String getDecimalNumber(){
        return this.convertedNumber;
    }

    public void convert(){
        int tempNum = 0;
        int len = this.recivedNumber.length();
        for(int i = 0; i < len; i++){
            tempNum += (this.recivedNumber.charAt(i) - '0') * Math.pow(2, len -1 -i);
        }
        this.convertedNumber = "" + tempNum;
    }

    public boolean compareString(String comp, String comp2){
        int len = comp.length();
        int lenEnd = comp2.length();
        if(lenEnd == len){ 
            for(int i = 0; i < len; i++){
                if(comp.charAt(i) != comp2.charAt(i)){
                    return false;
                }
            }
        }else{
            return false;
        }
        return true;
    }

    public void executeLoop(){
        String option = "";
        Scanner scanner = new Scanner(System.in);
        while(!compareString(option, "end")){
            System.out.print("Digite o numero em binario: ");
            option = scanner.nextLine();
            if(compareString(option, "end")){
                continue;
            }
            if(isBinary(option)){
                setB_Number(option);
                System.out.println(getDecimalNumber());
            }else{
                System.out.println("\nEntrada Invalida!\n");
            }
        }
    }
}
