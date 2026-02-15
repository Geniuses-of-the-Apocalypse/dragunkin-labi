package lab0002java;

public class main {
    public void main(String[] args) {
        System.out.println("=== Тестирование класса Triad ===");
        Triad a = new Triad(2, 423, 3);
        Triad b = new Triad(3, 42, 1);
        a.display();
        b.display();
        System.out.println("сравнение a and b " + a.prov(b));

        System.out.println("===== тест времени =====");
        time c = new time(44, -44, 2);
        time d = new time(832, 42134, -1);
        c.display();
        d.display();

        System.out.println("\n=== Сравнение времени ===");
        System.out.println("c == d: " + c.rav(d));
        System.out.println("c != d: " + c.nerav(d));
        System.out.println("c > d: " + c.bol(d));
        System.out.println("c >= d: " + c.bolrav(d));
        System.out.println("c < d: " + c.men(d));
        System.out.println("c <= d: " + c.menrav(d));


    }
}
