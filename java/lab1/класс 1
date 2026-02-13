package LAB001JAVA;
import java.util.Scanner;
public class FuzzyNumber {

    private float left, centr, right;
    float al;
    float ar;
    float bl ;
    float br ;


    public void init(float l, float c, float r) {
        left = l;
        centr = c;
        right = r;
    }

    public void read() {
        Scanner s = new Scanner(System.in);
        left = s.nextFloat();
        centr = s.nextFloat();
        right = s.nextFloat();
    }
    public FuzzyNumber rf(FuzzyNumber other) {
        FuzzyNumber res = new FuzzyNumber();
        res.al = centr - left;
        res.ar = right - centr;
        res.bl = other.centr - other.left;
        res.br = other.right - other.centr;
        return res;
    }

    public String toString() {
        return "(" + left + "," + centr + "," + right + ")";
    }

    public void display() {
        System.out.println(toString());
    }



    public FuzzyNumber add(FuzzyNumber other) {
        FuzzyNumber res = new FuzzyNumber();
        FuzzyNumber d = rf(other);
        //(A + B – a1 – b1, A + B, A + B + ar + br);
        res.left = (centr + other.centr) - d.al - d.bl;
        res.centr = centr + other.centr;
        res.right = centr + other.centr + d.ar + d.br;
        return res;
    }


    public FuzzyNumber rem(FuzzyNumber other) {
        FuzzyNumber res = new FuzzyNumber();
        FuzzyNumber d = rf(other);
        //(A – B – a1 – b1, A – B, A – B + ar + br);
        res.left = centr - other.centr -d.al -d.bl;
        res.centr = centr - other.centr;
        res.right = centr - other.centr +d.ar +d.br;
        return res;
    }
    public FuzzyNumber um(FuzzyNumber other) {
        FuzzyNumber res = new FuzzyNumber();
        FuzzyNumber d = rf(other);

        //= (A*B – B*a1 – A*b1 + a1*b1, A*B, A*B + B*a1 + A*b1 + a1*b1);
        float c = centr * other.centr;
        float l = c - other.centr * d.al - centr * d.bl + d.al * d.bl;
        float r = c + other.centr * d.al + centr * d.bl + d.al * d.bl;
        res.left = l;
        res.centr = c;
        res.right = r;
        return res;
    }

    public FuzzyNumber inver() {
        if (centr <= 0)
            System.out.println("число больше 0 для обратного и не 0 по правилу матеатики");
        FuzzyNumber res = new FuzzyNumber();
        float al = centr-left;
        float ar = right-centr;
        // (1/(A + ar), 1/A, 1/(A – al)), A > 0;
        res.left = 1 / (centr + ar);
        res.centr = 1 / centr;
        res.right = 1 / (centr - al);
        return res;
    }

    public FuzzyNumber del(FuzzyNumber other) {
        if (other.centr <= 0)
            System.out.println("число больше 0 для обратного и не 0 по правилу матеатики");
        FuzzyNumber res = new FuzzyNumber();
        FuzzyNumber d = rf(other);

        //((A – al)/(B + br), A/B, (A + ar)/(B – bl), B > 0.
        res.left = ((centr - d.al) / (other.centr + d.br));
        res.centr = centr / other.centr;
        res.right = (centr + d.ar) / (other.centr - d.bl);

        return res;
    }
}
