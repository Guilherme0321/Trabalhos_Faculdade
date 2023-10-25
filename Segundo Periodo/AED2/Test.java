public class Test {
    public static void main(String[] args) throws Exception {
        BinaryTreeSearch tree = new BinaryTreeSearch();
        tree.add(5);
        tree.add(1);
        tree.add(2);
        tree.add(8);
        tree.add(7);
        tree.add(6);
        tree.add(4);
        tree.add(9);
        tree.add(10);
        tree.printar();
        tree.remover(8);
        tree.printar();
        tree.remover(10);
        tree.printar();
        tree.remover(9);
        tree.printar();
        tree.remover(1);
        tree.printar();
        tree.remover(7);
        tree.printar();
    }
}
