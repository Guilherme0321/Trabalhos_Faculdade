public class Matriz {

    private Celula first;
    private int line, column;


    public Matriz(){
        first = null;
        line = 0;
        column = 0;
    }

    /* 
    Descrição do construtor da matriz
    - cria do lado de fora uma variavel referenciando first, depois dentro crie outra pra guardar a referencia do primeiro da linha
    - dentro do segundo for, um if pra testar se é a ultima coluna, se sim, não ira criar uma nova celula a direita
    - abaixo outro teste, se temp tiver uma celula em cima e tiver uma a direita, então ira fazer o da direita referenciar o da direita de cima
    - depois fora do segundo for, testa se é a ultima linha, se for, não cria um celula abaixo, mas se sim, cria uma celula abaixo e faz temp referenciar o de baixo
     */

    public Matriz(int line, int column){
        first = new Celula(); // cria a primeira celula
        this.line = line;
        this.column = column;
        Celula temp = first; // cria uma copia de referencia para first
        for(int i = 0; i < line; i++){ // cria as linhas
            Celula firstPos = temp;
            for(int j = 0; j < column; j++){ // cria a lista como se fosse uma lista encadeada
                Celula tmpTemp = temp;
                if(j < column-1){ // testa se é o ultimo, se for, não cria mais uma celula a direita
                    temp.setDir(new Celula());
                    temp.getDir().setEsq(temp);
                    temp = temp.getDir();
                }
                if(tmpTemp.getUp() != null && tmpTemp.getDir() != null){ // testa de existe celula acima, e se a direita é nula
                    tmpTemp.getDir().setUp(tmpTemp.getUp().getDir());
                    tmpTemp.getDir().getUp().setDown(tmpTemp.getDir());
                }
            }

            if(i < line-1){ // testa se é a ultima linha, se sim, não criará uma celula abaixo
                firstPos.setDown(new Celula());
                firstPos.getDown().setUp(firstPos);
                temp = firstPos.getDown();
            }
        }
    }

    public void setValue(int value, int line, int column){
        Celula temp = getCelua(line, column);
        temp.setElement(value);
    }

    public int getValue(int line, int column){
        Celula temp = getCelua(line, column);
        return temp.getElement();
    }

    private Celula getCelua(int line, int column){
        Celula temp = null;
        if(line < this.line && column < this.column){
            int i = 0;
            temp = first;
            while(i < line){
                temp = temp.getDown();
                i++;
            }
            i = 0;
            while(i < column){
                temp = temp.getDir();
                i++;
            }
        }else{
            System.out.println("Posição invalida!");
        }
        return temp;
    }

    public int getLines(){
        return this.line;
    }
    public int getColumns(){
        return this.column;
    }

    public Matriz somar(Matriz matriz){
        Matriz newMatriz = null;
        if(this.line == matriz.getLines() && this.column == matriz.getColumns()){
            newMatriz = new Matriz(line,column);
            for(int i = 0; i < line; i++){
                for(int j = 0; j < column; j++){
                    newMatriz.setValue(matriz.getValue(i, j) + getValue(i, j) , i, j);
                }
            }
        }else{
            System.out.println("Posição invalida!");
        }
        return newMatriz;
    }

    public Matriz multiplicar(Matriz matriz){
        Matriz result = null;
        int c = 0, l = 0;
        if(getLines() == matriz.getLines() && getColumns() == matriz.getColumns()){
            result = new Matriz(getLines(), matriz.getColumns());
            for(Celula temp = first; temp != null; temp = temp.getDown(), l++){
                c = 0;
                for(Celula i = matriz.first; i != null; i = i.getDir(), c++){
                    int value = 0;
                    for(Celula j = temp, k = i; j != null; j = j.getDir(), k = k.getDown()){
                        value += (k.getElement() * j.getElement());
                    }
                    result.setValue(value, l, c);
                }
            }
        }
        return result;
    }

    public void showMatriz(){
        for(Celula j = first; j != null; j = j.getDown()){
            for(Celula i = j; i != null; i = i.getDir()){
                System.out.printf("%d ", i.getElement());
            }
            System.out.println();
        }
    }

    public void showDiagonal(){
        for(Celula i = first; i != null; i = i.getDir()){
            System.out.printf("%d ", i.getElement());
            if(i.getDown() != null){
                i = i.getDown();
            }
        }
        System.out.println();
    }

    public void showSecondDiagonal() {
        Celula i;
        for (i = first; i.getDir() != null; i = i.getDir());
    
        for (Celula j = i; j != null; j = j.getEsq()) {
            System.out.printf("%d ", j.getElement());
            if (j.getDown() != null) {
                j = j.getDown();
            }
        }
        System.out.println();
    }

    public static Matriz makeMatriz(){
        int line = MyIO.readInt(), column = MyIO.readInt();
        Matriz matriz = new Matriz(line, column);
        int h = 0;
        for(Celula i = matriz.first; i != null && h < line; i = i.getDown()){
            int k = 0;
            for(Celula j = i; j != null && k < column; j = j.getDir()){
                int element = MyIO.readInt();
                j.setElement(element);
                k++;
            }
            h++;
        }
        return matriz;
    }

    public static void main(String[] args) {
        int countEntrada = 0;
/*         Matriz x = Matriz.makeMatriz();
        x.showMatriz();
        x.showDiagonal();
        x.showSecondDiagonal(); */
        countEntrada = MyIO.readInt();
        while(countEntrada > 0){
            Matriz matriz = makeMatriz();
            matriz.showDiagonal();
            matriz.showSecondDiagonal();

            Matriz secondMatriz = makeMatriz();
            Matriz soma = matriz.somar(secondMatriz);
            soma.showMatriz();

            Matriz mult = matriz.multiplicar(secondMatriz);
            mult.showMatriz();

            countEntrada--;
        }
    }
}

class Celula{
    private int element;
    private Celula dir;
    private Celula esq;
    private Celula up;
    private Celula down;

    public Celula(){
        this.element = 0;
        this.dir = null;
        this.esq = null;
        this.up = null;
        this.down = null;
    }

    public Celula(int element){
        this.element = element;
        this.dir = null;
        this.esq = null;
        this.up = null;
        this.down = null;
    }

    public int getElement(){
        return element;
    }

    public Celula getDir(){
        return dir;
    }
    public Celula getEsq(){
        return esq;
    }
    public Celula getUp(){
        return up;
    }
    public Celula getDown(){
        return down;
    }

    public void setElement(int element){
        this.element = element;
    }
    public void setDir(Celula dir){
        this.dir = dir;
    }
    public void setEsq(Celula esq){
        this.esq = esq;
    }
    public void setUp(Celula up){
        this.up = up;
    }
    public void setDown(Celula down){
        this.down = down;
    }
}
