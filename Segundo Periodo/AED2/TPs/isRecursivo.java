class isRecursivo {

  public static boolean isLetter(char x){
    return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
  }

  public static boolean isequals(String x, String y, int i){
    if(i == x.length()){
      return true;
    }
    if(x.charAt(i) != y.charAt(i)){
      return false;
    }
    return isequals(x, y, i+1);
  }

  public static boolean isequals(String x, String y){
    if(x.length() == y.length()){
      return isequals(x, y, 0);
    }else{
      return false;
    }
  }

  public static boolean isNumber(char num){
    return '0' <= num && num <= '9';
  }

  public static boolean isVogal(char x){
    return x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x== 'O' || x == 'u' || x == 'U';
  }
  
  public static boolean isAll_Vogal(String x, int i){
    if(i == x.length()){
      return true;
    }
    if(!isVogal(x.charAt(i))){
      return false;
    }
    
    return isAll_Vogal(x, i+1);
  }

  public static boolean isAll_Consoante(String x, int i){
    if(x.length() == i){
      return true;
    }
    if(!isLetter(x.charAt(i)) || isVogal(x.charAt(i))){
      return false;
    }
    
    return isAll_Consoante(x, i+1);
  }

  public static boolean isAll_Number(String x,int i){
    if(i == x.length()){
      return true;
    }
    if(!isNumber(x.charAt(i))){
      return false;
    }
    return isAll_Number(x, i+1);
  }

  public static boolean isFloating(String x, int i,int QuantVirgula){
      if(i == x.length()){
        return true;
      }
      if((x.charAt(i) == ',' || x.charAt(i) == '.')){
        QuantVirgula++;
      }
      if(QuantVirgula == 2){
        return false;
      }
      if(!('0' <= x.charAt(i) && x.charAt(i) <= '9') && x.charAt(i) != '.' && x.charAt(i) != ','){
        return false;
      }
      
      return isFloating(x,i+1,QuantVirgula);
  }

  public static boolean isFloating(String x){
    return isFloating(x, 0, 0);
  }
  
  public static void loop(){
    String entrada = "";
    entrada = MyIO.readLine();
    if(!isequals(entrada, "FIM")){
      if(isAll_Vogal(entrada,0)){
        System.out.print("SIM ");
      }else{
        System.out.print("NAO ");
      }
      if(isAll_Consoante(entrada,0)){
        System.out.print("SIM ");
      }else{
        System.out.print("NAO ");
      }
      if(isAll_Number(entrada,0)){
        System.out.print("SIM ");
      }else{
        System.out.print("NAO ");
      }
      if(isFloating(entrada)){
        System.out.print("SIM ");
      }else{
        System.out.print("NAO");
      }
      System.out.println();
      loop();
    }
}
  
  public static void main(String[] args) {
    loop();
  }
}