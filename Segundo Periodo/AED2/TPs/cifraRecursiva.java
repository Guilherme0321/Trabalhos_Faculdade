class cifraRecursiva {
    public static boolean isEquals(String x, String y, int i) {
        if (i == x.length()) {
            return true;
        }
        if (x.charAt(i) != y.charAt(i)) {
            return false;
        }
        return isEquals(x, y, i + 1);
    }

    public static boolean isEquals(String x, String y) {
        int len = x.length();
        if (len != y.length()) {
            return false;
        } else {
            return isEquals(x, y, 0);
        }
    }

    public static String toCifra(String x, int i) {
        if (i == x.length()) {
            return "";
        } else {
            char novoChar;

            if (x.charAt(i) != '\uFFFD') {
                novoChar = (char) (x.charAt(i) + 3);
            } else {
                novoChar = '\uFFFD';
            }
            return novoChar + toCifra(x, i + 1);
        }
    }

    public static void loop() {
        String x;
        MyIO.setCharset("UTF-8");
        
        while (true) {
            x = MyIO.readLine();
            if (isEquals(x, "FIM")) {
                break; 
            }
            
            String y = toCifra(x, 0);
            System.out.println(y);
        }
    }
    

    public static void main(String[] args) {
        loop();
    }
}
