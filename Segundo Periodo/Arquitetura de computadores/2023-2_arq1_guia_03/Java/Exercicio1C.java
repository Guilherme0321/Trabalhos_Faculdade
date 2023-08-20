package Java;

public class Exercicio1C {

    public static int findFist_one(String num){
        int i = num.length()-1;
        int p = -1;
        while( i >= 0){
            if(num.charAt(i) == '1'){
                p = i;
                i = 0;
            }
            i--;
        }
        return p;
    }

    public static boolean isBinary(String num){
        boolean isTrue = true;
        for(int i = 0; i < num.length(); i++){
            if(num.charAt(i) != '0' && num.charAt(i) != '1'){
                isTrue = false;
                i = num.length();
            }
        }
        return isTrue;
    }

    public static char subst(char x){
        return ( x == '0') ? (char)(x+1) : (char)(x-1); 
    }

    public static String C1(int nbits, String num){
        String newNum = "";
        int i = nbits -1;
        if(isBinary(num)){
            while(i >= 0){
                newNum = subst(num.charAt(i)) + newNum;
                i--;
            }
            newNum = '1' + newNum;
        }
        return newNum;
    }

    public static String C2(int nbits, String num){
        String newNum = "";
        int i = nbits-1;        
        if(isBinary(num)){
            i = findFist_one(num);
            int dif = nbits-1 - i;
            newNum = "0";
            i--;
            while(i >= 0){
                newNum = subst(num.charAt(i)) + newNum;
                i--;
            }
            while(dif > 0){
                newNum += '0';
                dif--;
            }
            newNum = '1' + newNum;
        }
        return newNum;
    }

}