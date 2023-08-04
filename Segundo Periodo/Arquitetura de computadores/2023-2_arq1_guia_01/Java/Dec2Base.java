package Java;

import java.util.Scanner;

public class Dec2Base {
    private String recive = "";
    private String number = "";
    private int base = 0;

    public boolean isNumber(String testar){
        int len = testar.length();
        for(int i = 0; i < len; i++){
            if(!('0' <= testar.charAt(i) && testar.charAt(i) <= '9')){
                return false;
            }
        }
        return true;
    }

    public int toInt(String testar){
        int len = testar.length();
        int temp = 0;
        for(int i = 0; i < len; i++){
            temp += (testar.charAt(i) - '0') * Math.pow(10,len-i-1);
        }
        return temp;
    }

    public void convert(){
        int temp = toInt(this.recive);
        if(this.base == 16){
            while(temp > 0){
                int resto = temp % base;
                temp /= base;
                if(resto > 9){
                    switch(resto){
                        case 10:
                            this.number = 'a' + this.number;
                        case 11:
                            this.number = 'b' + this.number;
                        case 12:
                            this.number = 'c' + this.number;
                        case 13:
                            this.number = 'd' + this.number;
                        case 14:
                            this.number = 'e' + this.number;
                        case 15:
                            this.number = 'f' + this.number;
                    }
                }else{
                    this.number = resto + this.number;
                }
            }
        }else{
            while(temp > 0){
                this.number = (temp % base) + this.number;
                temp /= base;
            }
        }
    }

    public String getNumber(){
        return this.number;
    }

    public void setNumber(String num, int base){
        if ((base != 2 && base != 8 && base != 16) && isNumber(num)){
            System.out.printf("\n\nBase %d invalida!\n\n",base);
        }else{
            this.recive = num;
            this.base = base;
            this.number = "";
            convert();
        }
    }

    public boolean compString(String a,String b){
        int lenA = a.length(), lenB = b.length();
        if(lenA == lenB){
            for(int i = 0; i < lenA; i++){
                if(a.charAt(i) != b.charAt(i)){
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
        while(!compString(option, "end")){
            System.out.print("\nDigite end para sair do loop\nNumero em decimal: ");
            option = scanner.nextLine();
            System.out.println("Precione ENTER!");
            scanner.nextLine();

            if(compString(option, "end")){
                continue;
            }
            System.out.print("Base: ");
            int op = scanner.nextInt();
            scanner.nextLine();
            setNumber(option, op);
            System.out.println(getNumber());
        }
    }

}
