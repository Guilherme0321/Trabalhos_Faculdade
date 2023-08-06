package Java;

import java.util.Scanner;

public class Bin2Base{
    private String recive = "";
    private String number = "";
    private int base = 0;
    private int tempNumber = 0;

    public boolean isBinary(String tester){
        for(int i = 0; i < tester.length(); i++){
            if(!('0' <= tester.charAt(i) && tester.charAt(i) <= '9')){
                return false;
            }
        }
        return true;
    }

    public boolean baseisValid(int base){
        if(base == 8 || base == 10 || base == 16){
            return true;
        }else{
            return false;
        }
    }

    public int toInt(String num){
        int temp = 0;
        int len = num.length();
        for(int i = 0; i < len; i++){
            temp += (num.charAt(i) - '0') * Math.pow(10, len - i -1);
        }
        return temp;
    }

    public void convertToDecimal(){
        int len = this.recive.length();
        this.number = "";
        int temp = 0;
        for(int i = 0; i < len; i ++){
            temp += (this.recive.charAt(i) - '0') * Math.pow(2,len -1 - i);
        }
        this.tempNumber = temp;
    }

    public void push_back(int add){
        this.number = add + this.number;
    }

    public void push_back(String add){
        this.number = add + this.number;
    }

    public void toHex(){
        int temp = this.tempNumber;
        int i = 0;
        while(temp > 0){
            i = temp % this.base;
            temp /= this.base;
            switch (i) {
                case 10:
                    push_back("a");
                    break;
                case 11:
                    push_back("b");
                    break;
                case 12:
                    push_back("c");
                    break;
                case 13:
                    push_back("d");
                    break;
                case 14:
                    push_back("e");
                    break;
                case 15:
                    push_back("f");
                    break;
                default:
                    push_back(i);
            }
        }
    }

    public void convertToother(){
        int temp = this.tempNumber;
        while(temp > 0){
            push_back(temp % this.base);
            temp /= this.base;
        }
    }

    public void convertTobase(){
        if(this.base == 16){
            toHex();
        }else{
            convertToother();
        }
    }

    public void setNumber(String num, int base){
        if(baseisValid(base) && isBinary(num)){
            this.recive = num;
            this.base = base;
            this.number = "";
            if(this.base == 10){
                convertToDecimal();
                this.number = this.tempNumber + "";
            }else{
                convertToDecimal();
                convertTobase();
            }
        }
    }

    public boolean compString(String one, String two){
        int len1 = one.length(), len2 = two.length();
        if(len1 == len2){
            for(int i = 0; i < len1; i++){
                if(one.charAt(i) != two.charAt(i)){
                    return false;
                }
            }
        }else{
            return false;
        }
        return true;
    }

    public String getNumber(){
        return this.number;
    }

    public void executeLoop(){
        Scanner scanner = new Scanner(System.in);
        String test = "";
        while(!compString(test, "end")){
            System.out.println("DIGITE end para sair do loop!");
            System.out.print("Dite o numero em binario: ");
            test = scanner.nextLine();
            if(compString(test, "end")){
                continue;
            }
            System.out.print("Digite enter!");
            scanner.nextLine();
            System.out.print("Digite a base que queira converter: ");
            int base = scanner.nextInt();
            if(isBinary(test) && baseisValid(base)){
                setNumber(test, base);
                System.out.println("\n\nResultado: " + getNumber() + "\n\n");
            }else{
                if(!isBinary(test)){
                    System.out.print("\n\n Numero invalido\n\n\n");
                }else if(!baseisValid(base)){
                    System.out.print("\n\n Base invalida\n\n\n");
                }
            }
            System.out.print("Digite enter!");
            scanner.nextLine();
        }
    }
}