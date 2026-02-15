package lab0002java;

import java.util.Scanner;

public class time extends Triad {
            int h,m,s;
    Scanner scanner = new Scanner(System.in);

    public time(int h, int m, int s){
        super(Ppr(h), Mpr(m), Spr(s));
    }

    public static int Ppr(int h){
        if(h>=0&&h<24)
            return h;
        else if (h<0) {
            int res = 24 + (h % 24);
            return res;
        }
        else  return h%24;
    }
    public static int pr60(int v){
        if (v>=0 && v<60)
            return v;
        else if (v<0) {
            int res = 60 + (v%60);
            return res;}
        else return v%60;

        }
        public static int Mpr(int m)
        {
            return pr60(m);
        }
        public static int Spr(int s)
        {
            return pr60(s);
        }
        @Override
    public void setp(int h) {this.p=h;};
    @Override
    public void setd(int m) {this.d=m;};
    @Override
    public void sedt(int s) {this.p=s;};

    public int getH(){
        return p;}
    public int getM(){return d;}
    public int getS(){return t;}

    public boolean rav(time other){return this.prov(other)==0;}
    public boolean nerav(time other){return this.prov(other)!=0;}
    public boolean bol(time other){return this.prov(other)>0;}
    public boolean bolrav(time other){return this.prov(other)>=0;}
    public boolean men(time other){return this.prov(other)<0;}
    public boolean menrav(time other){return this.prov(other)<=0;}
    @Override
    public String tostring(){
        return String.format("%02d:%02d:%02d",p,d,t);}

    @Override
    public void display() {
        System.out.println(tostring());}
}

