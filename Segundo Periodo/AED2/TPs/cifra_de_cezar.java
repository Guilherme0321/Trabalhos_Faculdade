class Main{
    public static boolean isequals(String x, String y){
          int len = x.length(), leny = y.length();
          boolean isTrue = true;
          if(len != leny){
              isTrue = false;
          }else{
              for (int i = 0; i < len; i++) {
                  if(x.charAt(i) != y.charAt(i)){
                      isTrue = false;
                    i = len;
                  }
              }
          }
          return isTrue;
    }
      public static void main(String[] args){
        MyIO.setCharset("UTF-8");
          String x = "", y = "";
          
          while(!isequals(x,"FIM")){
              x = MyIO.readLine();
            if(isequals(x,"FIM")){
                continue;
            }
              y = "";
          for(int i = 0; i < x.length();i++){
              y += (int)(x.charAt(i))!='\uFFFD' ? (char)(x.charAt(i)+3):'\uFFFD';
          }
          
          MyIO.println(y);
          }
          
          
      }
  }