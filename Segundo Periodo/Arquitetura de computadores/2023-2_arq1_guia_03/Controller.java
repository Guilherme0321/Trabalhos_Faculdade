import Java.*;

public class Controller {
    public static void main(String[] args) {
        String x = "1011";
        int nbits = 4;
        String tab = "      ";
        x = Exercicio1C.C1(nbits, x);

        System.out.println("Exercicio 1C: \n");
        System.out.println(tab + "C1 = " + x);
        x = Exercicio1C.C2(5, "10101");
        System.out.println(tab + "C2 = " + x);
        System.out.println();

        System.out.println("Exercicio 2C: \n");
        System.out.println(tab + "C1 = " + Exercicio2C.C1(16,7, "40"));
        System.out.println(tab + "C2 = " + Exercicio2C.C2(16,7, "40"));

        System.out.println("Exercicio 3C: \n");
        System.out.println(tab + "complemento em decimal = " + Exercicio3C.C2(4, "10110"));

    }
}
