package lab3java;


public class Main {
    public static void main(String[] args) {
        System.out.println("=== ТЕСТ 1: Decimal ===");
        Decimal d1 = new Decimal("123");
        Decimal d2 = new Decimal("456");
        Decimal d3 = new Decimal("-50");
        Decimal d4 = new Decimal("30");

        System.out.print("123 + 456 = ");
        d1.add(d2).print();
        System.out.print("-50 + 30 = ");
        d3.add(d4).print();

        System.out.println("\n=== ТЕСТ 2: Hex ===");
        Hex h1 = new Hex("A5");
        Hex h2 = new Hex("5A");
        Hex h3 = new Hex("FFF");
        Hex h4 = new Hex("1");

        System.out.print("A5 + 5A = ");
        h1.add(h2).print();
        System.out.print("FFF + 1 = ");
        h3.add(h4).print();

        System.out.println("\n=== ТЕСТ 3: Интерфейс ===");
        Array a1 = new Decimal("777");
        Array a2 = new Decimal("222");
        Array a3 = new Hex("ABC");
        Array a4 = new Hex("123");

        System.out.print("777 + 222 = ");
        a1.add(a2).print();
        System.out.print("ABC + 123 = ");
        a3.add(a4).print();
    }
}
