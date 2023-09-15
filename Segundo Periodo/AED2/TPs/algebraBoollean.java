public class algebraBoollean {

    public static boolean[] values;

    public static int contar(String x){
        int i = 0, count = 0;
        while(i < x.length()){
            if(x.charAt(i) == '('){
                count++;
            }
            i++;
        }
        return count;
    }

    public static boolean isEquals(String x, String y) {
        boolean istrue = true;
        if (x.length() == y.length()) {
            for(int i = 0; i < x.length(); i++){
                if(x.charAt(i) != y.charAt(i)){
                    istrue = false;
                    i = x.length();
                }
            }
        }else{
            istrue = false;
        }
        return istrue;
    }

    public static String subst(String x, String y, String subs) {
        int lenx = x.length(), leny = y.length();
        int i = 0;
        StringBuilder newStr = new StringBuilder();
        while (i < lenx) {
            boolean found = true;
            for (int j = 0; j < leny; j++) {
                if (i + j >= lenx || x.charAt(i + j) != y.charAt(j)) {
                    found = false;
                    j = leny;
                }
            }
            if (found) {
                newStr.append(subs);
                i += leny;
            } else {
                newStr.append(x.charAt(i));
                i++;
            }
        }
        return newStr.toString();
    }

    public static boolean[] allocate(boolean[] x) {
        boolean[] y = new boolean[x.length + 1];
        System.arraycopy(x, 0, y, 0, x.length);
        return y;
    }

    public static String interpret(String x, int start, int end) {
        for (int i = start; i < end; i++) {
            boolean[] values = new boolean[1];
            if (x.charAt(i) == '!') {
                x = subst(x, "!(1)", "0");
                x = subst(x, "!(0)", "1");
            } else if (x.charAt(i) == '&') {
                String substituted = "";
                substituted += x.charAt(i);
                while (x.charAt(i) != '(') {
                    i++;
                }
                substituted += x.charAt(i);
                i++;
                substituted += x.charAt(i);
                int j = 0;
                while (x.charAt(i) != ')') {
                    if (x.charAt(i) == '0' || x.charAt(i) == '1') {
                        if (values.length != j + 1) {
                            values = allocate(values);
                        }
                        values[j] = (x.charAt(i) == '0') ? false : true;
                        j++;
                    }
                    substituted += x.charAt(i);
                    i++;
                }
                substituted += x.charAt(i);
                boolean isTrue = true;
                for (int h = 0; h < values.length; h++) {
                    if (!values[h]) {
                        isTrue = false;
                        h = values.length;
                    }
                }
                if (isTrue) {
                    x = subst(x, substituted, "1");
                } else {
                    x = subst(x, substituted, "0");
                }
            }
        }
        return x;
    }

    public static void main(String[] args) {
        String x = "";
        int num = 0, i = 0;
        while (!x.equals("0")) {
            i = 0;
            num = 0;
            x = MyIO.readLine();
            if(x.equals("0")){
                continue;
            }
            x = subst(x, " ", "");
            num = x.charAt(0) - '0';
            values = new boolean[num];
      
            i++;
            while (i < num) {
                values[i - 1] = (x.charAt(i) == '0') ? false : true;
                i++;
            }
            i++;
            x = subst(x, "and", "&");
            x = subst(x, "or", "|");
            x = subst(x, "not", "!");
            for (int j = 0; j < num; j++) {
                x = subst(x, "" + (char) ('A' + j), "" + x.charAt(j + 1));
            }
            x = subst(x, "!(1)", "0");
            x = subst(x, "!(0)", "1");
            
            String z = "";
            for(int j = i; j < x.length(); j++){
                z += x.charAt(j);
            }
            x = z;
            int j = 0;
            while(contar(x) > 1){
                i = 0;
                while(i < x.length()){
                    x = subst(x, "!(1)", "0");
                    x = subst(x, "!(0)", "1");
                    
                    x = subst(x, "&(0,0,0,0)", "0");
                    x = subst(x, "&(0,0,0,1)", "0");
                    x = subst(x, "&(0,0,1,0)", "0");
                    x = subst(x, "&(0,0,1,1)", "0");
                    x = subst(x, "&(0,1,0,0)", "0");
                    x = subst(x, "&(0,1,0,1)", "0");
                    x = subst(x, "&(0,1,1,0)", "0");
                    x = subst(x, "&(0,1,1,1)", "0");
                    x = subst(x, "&(1,0,0,0)", "0");
                    x = subst(x, "&(1,0,0,1)", "0");
                    x = subst(x, "&(1,0,1,0)", "0");
                    x = subst(x, "&(1,0,1,1)", "0");
                    x = subst(x, "&(1,1,0,0)", "0");
                    x = subst(x, "&(1,1,0,1)", "0");
                    x = subst(x, "&(1,1,1,0)", "0");
                    x = subst(x, "&(1,1,1,1)", "1");
                    
                    x = subst(x, "|(0,0,0,0)", "0");
                    x = subst(x, "|(0,0,0,1)", "1");
                    x = subst(x, "|(0,0,1,0)", "1");
                    x = subst(x, "|(0,0,1,1)", "1");
                    x = subst(x, "|(0,1,0,0)", "1");
                    x = subst(x, "|(0,1,0,1)", "1");
                    x = subst(x, "|(0,1,1,0)", "1");
                    x = subst(x, "|(0,1,1,1)", "1");
                    x = subst(x, "|(1,0,0,0)", "1");
                    x = subst(x, "|(1,0,0,1)", "1");
                    x = subst(x, "|(1,0,1,0)", "1");
                    x = subst(x, "|(1,0,1,1)", "1");
                    x = subst(x, "|(1,1,0,0)", "1");
                    x = subst(x, "|(1,1,0,1)", "1");
                    x = subst(x, "|(1,1,1,0)", "1");
                    x = subst(x, "|(1,1,1,1)", "1");
                    
                    x = subst(x, "&(1,1,1)", "1");
                    x = subst(x, "&(1,1,0)", "0");
                    x = subst(x, "&(1,0,1)", "0");
                    x = subst(x, "&(1,0,0)", "0");
                    x = subst(x, "&(0,1,1)", "0");
                    x = subst(x, "&(0,1,0)", "0");
                    x = subst(x, "&(0,0,1)", "0");
                    x = subst(x, "&(0,0,0)", "0");
                    
                    x = subst(x, "&(1,0)", "0");
                    x = subst(x, "&(0,1)", "0");
                    x = subst(x, "&(1,1)", "1");
                    x = subst(x, "&(0,0)", "0");
                    
                    x = subst(x, "|(1,1,1)", "1");
                    x = subst(x, "|(1,1,0)", "1");
                    x = subst(x, "|(1,0,1)", "1");
                    x = subst(x, "|(1,0,0)", "1");
                    x = subst(x, "|(0,1,1)", "1");
                    x = subst(x, "|(0,1,0)", "1");
                    x = subst(x, "|(0,0,1)", "1");
                    x = subst(x, "|(0,0,0)", "0");
                    x = subst(x, "|(1,0)", "1");
                    x = subst(x, "|(0,1)", "1");
                    x = subst(x, "|(1,1)", "1");
                    x = subst(x, "|(0,0)", "0");
                    
                    i++;
                }
                j++;
            }
    
            String teste = "";
            boolean istrue = true;
            if(x.length() > 1 && x.charAt(0) == '|'){
                i = 0;
                istrue = false;
                while(x.charAt(i) == '0' || x.charAt(i) == '('){
                    i++;
                }
                j = 0;
                while(x.charAt(j) != ')'){
                    if(x.charAt(j) == '0' || x.charAt(j) == '1'){
                        teste += x.charAt(j);

                    }
                    j++;
                }
                for(j = 0; j < teste.length(); j++){
                    if(teste.charAt(j) == '1'){
                        istrue = true;
                        j = teste.length();
                    }
                }
            }
            if(x.length() > 1 && x.charAt(0) == '&'){
                i = 0;
                istrue = true;
                while(x.charAt(i) == '0' || x.charAt(i) == '('){
                    i++;
                }
                j = 0;
                while(x.charAt(j) != ')'){
                    if(x.charAt(j) == '0' || x.charAt(j) == '1'){
                        teste += x.charAt(j);

                    }
                    j++;
                }
                for(j = 0; j < teste.length(); j++){
                    if(teste.charAt(j) == '0'){
                        istrue = false;
                        j = teste.length();
                    }
                }
            }
            
            if(istrue && x.length() > 1){
                x = "1";
            }else if(x.length() > 1){
                x = "0";
            }
            System.out.println(x);
            x = "";
        }
    }
}
