package lab0002java;
import java.util.Scanner;

public class Triad {
 Scanner scanner = new Scanner(System.in);
 protected int p,d,t;

 public Triad(int p,int d, int t) {
     this.p=p;
     this.d=d;
     this.t=t;};
 public Triad(Triad o){
     p = o.p;
     d=o.d;
     t = o.t; };
 public Triad(){
     p = 0;
     d=0;
     t = 0;

 }
 public void setp(int value) {p=value;};
 public void setd(int value){d=value;};
 public void sedt(int value){t=value;};

    public int getp() {return p;};
    public int getd() {return d;};
    public int gett() {return t;};

    public String tostring(){return "p= "+ p + " d= "+d + " t= "+t;};

    public void read(){
        System.out.println("введите 1 число");
        p = scanner.nextInt();
        System.out.println("введите 2 число");
        d = scanner.nextInt();
        System.out.println("введите 3 число");
        t= scanner.nextInt();}

    public void display(){
        System.out.println(tostring());}

    public double prov(Triad other)
    {
        if(this.p != other.p)
            return Integer.compare(this.p, other.p );
        if(this.d != other.d)
            return Integer.compare(this.d, other.d );
            return Integer.compare(this.t, other.t );}

}
