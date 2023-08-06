package Java;

public class Bin2Base{
    private String recive = "";
    private String number = "";
    private int base = 0;
    private int tempNumber = 0;

    public boolean isBinary(String tester){
        for(int i = 0; i < tester.length(); i++){
            if(!('0' <= tester.charAt(i) && tester.charAt(i) <= '9')){
                return false;
            }
        }
        return true;
    }

    public boolean baseisValid(int base){
        if(base == 8 || base == 10 || base == 16){
            return true;
        }else{
            return false;
        }
    }

    public int toInt(String num){
        int temp = 0;
        int len = num.length();
        for(int i = 0; i < len; i++){
            temp += (num.charAt(i) - '0') * Math.pow(10, len - i -1);
        }
        return temp;
    }

    public void convertToDecimal(){
        int len = this.recive.length();
        this.number = "";
        int temp = 0;
        for(int i = 0; i < len; i ++){
            temp += (this.recive.charAt(i) - '0') * Math.pow(this.base,i);
        }
        this.tempNumber = temp;
    }

    public void push_back(int add){
        this.number = add + this.number;
    }

    public void push_back(String add){
        this.number = add + this.number;
    }

    public void toHex(){
        int temp = this.tempNumber;
        int i = 0;
        while(temp > 0){
            i = temp % this.base;
            temp /= this.base;
            switch (i) {
                case 10:
                    push_back("a");
                    break;
                case 11:
                    push_back("b");
                    break;
                case 12:
                    push_back("c");
                    break;
                case 13:
                    push_back("d");
                    break;
                case 14:
                    push_back("e");
                    break;
                case 15:
                    push_back("f");
                    break;
                default:
                    push_back(i);
            }
        }
    }

    public void convertToother(){
        int temp = this.tempNumber;
        while(temp > 0){
            push_back(temp % this.base);
            temp /= this.base;
        }
    }

    public void convertTobase(){
        if(this.base == 16){
            toHex();
        }else{

        }
    }

    public void setNumber(String num, int base){
        if(baseisValid(base) && isBinary(num)){
            this.recive = num;
            this.base = base;
            this.number = "";
        }
    }

    public String getNumber(){
        return this.number;
    }
}