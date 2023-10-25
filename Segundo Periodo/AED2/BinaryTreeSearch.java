class No{
    private int elemento;
    private No dir;
    private No esq;
    public No(int element){
        this.elemento = element;
        this.dir = null;
    }
    public No(int element, No dir){
        this.elemento = element;
        this.dir = dir;
    }
    public int getElement(){
        return this.elemento;
    }
    public void setElement(int i){
        this.elemento = i;
    }
    public No getDir(){
        return this.dir;
    }
    public void setDir(No dir){
        this.dir = dir;
    }
    public void setEsq(No esq){
        this.esq = esq;
    }
    public No getEsq(){
        return this.esq; 
    }
}

public class BinaryTreeSearch {
    private No root;

    public BinaryTreeSearch(){
        this.root = null;
    }

    public void add(int elemento){
        this.root = add(elemento,root);
    }

    private No add(int elemento, No root){
        if(root == null){ // se root == null, crie um objeto No com o atributo igual ao elemento e retorne
            return new No(elemento); 
        }else if(elemento < root.getElement()){ // se o elemento for menor que a raiz va para a arvore da esquerda 

            root.setEsq(add(elemento,root.getEsq())); // chama recursivamente a função para ir para o proximo galho

        }else if(elemento > root.getElement()){ // se o elemento for maior que a raiz va para a arvore da direita

            root.setDir(add(elemento,root.getDir()));; // chama recursivamente a função para ir para o proximo galho
        }
        return root;
    }

/*     private No getBigger(No i,No j) throws Exception{
        if(i == null){
            throw new Exception("Raiz é null");
        }else if(j.getDir() == null){
            i.setElement(j.getElement());
            j = j.getEsq();
        }else{
            j.setDir(getBigger(i, j.getDir()));
        }
        return j;
    } */

    private No getBigger(No i,No j) throws Exception{
        No n; // variavel de controle
        for(n = j; n.getDir() != null; n = n.getDir()); // percorre todos da direita
        i.setElement(n.getElement()); // passa os atributos do maior para o not pai(i)

        return n.getEsq(); // retorna a referencia do nó a esquerda, porque pode haver uma outra referencia a esquerda
    }

    // getBigger pode ser feito das duas formas




    private No remover(int i, No no) throws Exception{
        if (no == null) { // testa se no == null 
            return null;
        } else if (no.getElement() > i) { // testa se está na arvore da esquerda
            no.setEsq(remover(i, no.getEsq()));
        } else if (no.getElement() < i) {  // testa se está na arvore da direita
            no.setDir(remover(i, no.getDir())); 
        } else if (no.getDir() == null) { // caso seja nó folha ou o nó tenha apenas um filho
            no = no.getEsq();
        } else if (no.getEsq() == null) { // caso seja nó folha ou o nó tenha apenas um filho
            no = no.getDir();
        } else { 
            no.setEsq(getBigger(no, no.getEsq())); // caso o nó tenha mais de um filho
        }
        return no;
    }

    public void remover(int i) throws Exception{
        remover(i,root);
    }

    public void printar(){
        printar(root);
        System.out.println();
    }

    private void printar(No root){
        if(root != null){
            System.out.print(root.getElement() + " ");
            printar(root.getEsq());
            printar(root.getDir());
        }
    }
}