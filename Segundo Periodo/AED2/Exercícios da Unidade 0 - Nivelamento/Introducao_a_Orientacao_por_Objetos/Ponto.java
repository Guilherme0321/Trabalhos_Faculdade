package Introducao_a_Orientacao_por_Objetos;

public class Ponto {
    private double x;
    private double y;
    private int id;
    private static int nextID = 0;

    public Ponto(){
        this.x = 0;
        this.y = 0;
        this.id = this.nextID;
        this.nextID++;
    }

    public Ponto(double x, double y){
        this.x = x;
        this.y = y;
        this.id = nextID;
        this.nextID++;
    }

    public void setX(double x){
        this.x = x;
    }

    public void setY(double y){
        this.y = y;
    }

    public int getID(){
        return this.id;
    }
    
    public static int getNextID(){
        return nextID;
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return this.y;
    }

    private static double calcHipotenuza(double x, double y, double w, double z){
        double distX = x - w;
        double distY = y - z;
        return Math.sqrt((distX * distX) + (distY * distY));
    }

    public double dist(Ponto x){
        return calcHipotenuza(this.x, this.y, x.getX(), x.getY());
    }

    public double dist(double x, double y){
        return calcHipotenuza(this.x, this.y, x, y);
    }

    public static double dist(double x, double y, double w, double z){
        return calcHipotenuza(x, y, w, z);
    }

    public double getAreaRetangulo(Ponto p){
        return (this.x - p.getX()) * (this.y - p.getY());
    }

    public static boolean isTriangulo(Ponto p1, Ponto p2, Ponto p3){
        double p1p2 = p1.dist(p2);
        double p1p3 = p1.dist(p3);
        double p2p3 = p2.dist(p3);
        return (p1p2 + p1p3 > p2p3 && p1p2 + p2p3 > p1p3 && p2p3 + p1p3 > p1p2);
    }

}
