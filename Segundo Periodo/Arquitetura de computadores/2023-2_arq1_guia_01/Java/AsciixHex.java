package Java;

import java.util.Scanner;

public class AsciixHex{

    public int toInt(String num){
        int len = num.length();
        int temp = 0;
        for(int i = 0; i < len; i++){
            temp += (num.charAt(i) - '0') * Math.pow(10,len -i -1);
        }
        return temp;
    }

    public String toLowercase(String upper){
        String temp = "";
        for(int i = 0; i < upper.length(); i++){
            char c = upper.charAt(i);
            if('A' <= c && c <= 'Z'){
                c += 32;
            }
            temp += c;
        }
        return temp;
    }


    public String toDecimal(String num){
        num = toLowercase(num);
        int len = num.length();
        int decimal = 0;
        for(int i = 0; i < len; i++){
            char numChar = num.charAt(i);
            if('a' <= numChar && numChar <= 'f'){
                decimal += (numChar - 'a' + 10) * Math.pow(16,len -i -1);
            }else{
                decimal += (numChar - '0') * Math.pow(16,len -1 -i);
            }
        }
        return decimal + "";
    }

    public String toHex(String num) {
        String temp = "";
        int numero = toInt(num);
        int resto = 0;
        while(numero > 0) {
            resto = numero % 16;
            numero /= 16;
            switch(resto){
                case 10:
                    temp = 'a' + temp;
                    break;
                case 11:
                    temp = 'b' + temp;
                    break;
                case 12:
                    temp = 'c' + temp;
                    break;
                case 13:
                    temp = 'd' + temp;
                    break;
                case 14:
                    temp = 'e' + temp;
                    break;
                case 15:
                    temp = 'f' + temp;
                    break;
                default:
                    temp = resto + temp;
                    break;
                }

        }
        return temp;
    }
    

    public String dectoHex(String recive) {
        String temp = "";
        String number = "";
    
        for (int i = 0; i < recive.length(); i++) {
            if (recive.charAt(i) != ' ' && recive.charAt(i) != '\n' && recive.charAt(i) != '\0') {
                temp += recive.charAt(i);
            } else {
                if (!temp.isEmpty()) {
                    number += toHex(temp) + " ";
                    temp = "";
                }
            }
        }
    
        if (!temp.isEmpty()) {
            number += toHex(temp);
        }
    
        return number;
    }
    
    

    public String asciiTodecimal(String ascii){
        String tempnumber = "";
        for(int i = 0; i <= ascii.length(); i++){
            if(i < ascii.length() && ascii.charAt(i) != '\n' && ascii.charAt(i) != '\0'){
                tempnumber += ' ';
                tempnumber += (int) ascii.charAt(i);
            }
        }
        
        return tempnumber;
    }

    public void asciiToHexa(String recive){
        String temp = "";

        temp = asciiTodecimal(recive);
        System.out.println("DECIMAL: " + temp);

        temp = dectoHex(temp);
        System.out.println("HEXADECIMAL: " + temp);
    }

    public String[] add(String [] arr,String append){
        int arrLength = arr.length;
        String arr2[] = new String[arrLength+1];
        for(int i = 0; i < arrLength; i++){
            arr2[i] = arr[i];
        }
        arr2[arrLength] = append;
        return arr2;
    }

    public void printArray(String[] arr){
        for(String x : arr){
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public String[] toCovert(String recive){
        String temp = "";
        int len = recive.length();
        String[] arr = {};
        for(int i = 0; i <= len; i++){
            if(i < len && recive.charAt(i) != ' ' && recive.charAt(i) != '\n' && recive.charAt(i) != '\0'){
                temp += recive.charAt(i);
            }else{
                if(!temp.isEmpty()){
                    arr = add(arr, temp);
                    temp = "";
                }
            }
        }
        return arr;
    }

    public String tostring(String[] in){
        String out = "";
        for(int i = 0; i < in.length; i++){
            out += (char) toInt(in[i]);
        }
        return out;
    }

    public void HexaToAscii(String recive){
        String[] arr = toCovert(recive);
        for(int i = 0; i < arr.length; i++){
            arr[i] = toDecimal(arr[i]);
        }
        System.out.print("Decimal: ");
        printArray(arr);
        System.out.println("Ascii: " + tostring(arr));
    }

    public void executeLoop(){
        String recive = "";
        Scanner scanner = new Scanner(System.in);
        while(true){
            System.out.print("\n\n0 - sair do loop\n 1 - Ascii => Hexadecimal\n 2 - Hexadeciaml => Ascii\n Option: ");
            int op = scanner.nextInt();
            scanner.nextLine();
            if(op == 0){
                break;
            }else if(op == 1){
                System.out.print("String para converter para Ascii(16): ");
                recive = scanner.nextLine();
                System.out.print("Aperte enter!");
                scanner.nextLine();
                asciiToHexa(recive);
            }else if(op == 2){
                System.out.print("Ascii(16) para converter para String: ");
                recive = scanner.nextLine();
                System.out.print("Aperte enter!");
                scanner.nextLine();
                HexaToAscii(recive);
            }

            System.out.print("Aperte enter!");
            scanner.nextLine();
        }
    }
}