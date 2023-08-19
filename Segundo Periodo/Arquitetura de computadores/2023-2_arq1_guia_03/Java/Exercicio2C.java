package Java;

public class Exercicio2C {


    // padding para bin > base
    /* public static String[] padding(int base,String num){  
        while(num.length() % base != 0){
            num = "0" + num;
        }
        String[] sep = new String[num.length()/base];
        int len = num.length();
        int count = 1;
        String temp = "" + num.charAt(0);
        while(count < len){
            temp += num.charAt(count);
            if((count+1)%base == 0){
                sep[(count/base)] = temp;
                temp = "";
            }
            count++;
        }
        return sep;
    } */

    public static int toInt(String num){
        int i = 0, len = num.length(), resul = 0;
        while(i < len){
            resul += (num.charAt(i) - '0') * Math.pow(10,len-i-1);
            i++;
        }
        return resul;
    }

    public static boolean isEquals(String x, String y){
        boolean is = true;
        if(x.length() == y.length()){
            for (int i = 0; i < x.length() ; i++) {
                if(x.charAt(i) != y.charAt(i)){
                    is = false;
                }
            }
        }else{
            is = false;
        }
        return is;
    }

    public static String toDecimal(String num){
        String newString = "";
        if(isEquals(num, "0")){
            return "0";
        }
        int number = num.length() > 1 ? toInt(num) : num.charAt(0) - '0';
        while(number > 0){
            newString = (number % 2) + newString;
            number /= 2;
        }

        return newString;
    }

    public static boolean isLetter(char x){
        return ('a' <= x && x <= 'f') || ('A' <= x && x <= 'F');
    } 

    public static String toNumber(char binNum){
        String[] num = {"10","11","12","13","14","15"};
        if(isLetter(binNum)){
            return ('a' <= binNum && binNum <= 'f') ? num[binNum-'a']:num[binNum-'A'];
        }
        return binNum + "";
    }

    public static String padding(int base, String num){
        while(num.length() % base != 0){
            num = "0" + num;
        }
        return num;
    }

    public static String toBin(int base, String num){
        String newNum = "";
        int len = num.length();
        if(base == 16){
            for(int i = 0; i < len;i++){
                newNum += padding(base-12,toDecimal(toNumber(num.charAt(i))));
            }
        }else{
            base = (base == 8) ? 3 : 2;
            for(int i = 0; i < len; i++){
                newNum += padding(base,toDecimal(num.charAt(i) + ""));
            }
        }
        return newNum;
    }

    public static String C1(int base ,int nbits, String num){
        String x = toBin(base, num);
        return Exercicio1C.C1(nbits, x);
    }

    public static String C2(int base,int nbits, String num){
        String x = toBin(base, num);
        return Exercicio1C.C2(nbits, x);
    }

    public static void main(String[] args) {
        toBin(8, "100");
    }
}
