package Java;

public class Exercicio3C extends Exercicio1C{

    public static String toDecimal(String num){
        int number = 0, len = num.length();
        for (int i = 0; i < len; i++) {
            number += (num.charAt(i) - '0') * Math.pow(2,len-1-i);
        }
        return number + "";
    }

    public static String C2(int nbits, String num){
        String newString = "";
        int i = 0;
        if(isBinary(num)){
            i = findFist_one(num);
            int dif = nbits -i - 1;
            newString = "1";
            i--;
            while(i >= 0){
                newString = subst(num.charAt(i)) + newString;
                i--;
            }
            while(dif >= 0){
                newString += "0";
                dif--;
            }
        }
        return toDecimal(newString);
    }
}
