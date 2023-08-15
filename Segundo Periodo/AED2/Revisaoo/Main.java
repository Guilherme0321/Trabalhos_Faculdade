
public class Main{

    public static boolean isVogal(char x){
        return x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

    public static boolean isletter(char x){
        return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
    }

   public static boolean isConsoante(String s, int n) {
    boolean resp = true;
    if (n != s.length()) {
        if ((s.charAt(n) >= 'a' && s.charAt(n) <= 'z') || (s.charAt(n) >= 'A' && s.charAt(n) <= 'Z')) {
            if (!isVogal(s.charAt(n)) && isletter(s.charAt(n))) {
                resp = isConsoante(s, n+1);
            } else {
                resp = false;
            }
        } else {
            resp = false;
        }
    }
    return resp;
}

    public static int[] biggerElement(int[] x){
        int bigger = x[0], smaller = x[0];
        for(int i : x){
            bigger = (i > bigger) ? i : bigger;

            smaller = (i < smaller) ? i : smaller;
        }

        int[] retorno = {bigger,smaller};
        return retorno;
    }

    public static boolean sorted_has(int[] x, int y){
        boolean isIn = false;
        int len = x.length;
        for(int i = (int)len/2; i < len; i++){
            if(x[i] == y){
                isIn = true;
                i = len;
            }
        }
        return isIn;
    }

    public static boolean Array_has(int[] x, int y){
        boolean isIn = false;
        int len = x.length;
        for(int i = 0; i < len; i++){
            if(x[i] == y){
                isIn = true;
                i = len;
            }
        }
        return isIn;
    }
    public static void main(String[] args){
        int[] arr = {5,4,65,9,8};
        System.out.println("Exercicio 01: " + Array_has(arr, 65));
        System.out.println("Exercicio 01: " + Array_has(arr, 2));

        int[] arr2 = {1,2,3,4,5,6};
        System.out.println("Exericio 02: " + sorted_has(arr2, 4));
        System.out.println("Exericio 02: " + sorted_has(arr2, 2));

        int[] arr3 = {1,6,4,8,9,7,10,2};
        int [] retorno = biggerElement(arr3);
        System.out.print("Exercicio 03: maior: " + retorno[0] + " menor: " + retorno[1]);
        
        String testar = "o", teste2 = "bbbbbbbb";
        System.out.println("Exercicio do slide (7): " + isConsoante(testar, 0));
        System.out.println("Exercicio do slide (7): " + isConsoante(teste2, 0));
    }
}
