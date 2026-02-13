package LAB001JAVA;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n=== Вариант 11: ===");
        FuzzyNumber a2 = new FuzzyNumber();
        FuzzyNumber b2 = new FuzzyNumber();
        a2.init(3,4,2);
        b2.init(9, 33 ,2);

        System.out.println("A = " + a2);
        System.out.println("B = " + b2);
        System.out.println("A + B = " + a2.add(b2));
        System.out.println("A - B = " + a2.rem(b2));
        System.out.println("A * B = " + a2.um(b2));
        System.out.println("1/A = " + a2.inver());
        System.out.println("A / B = " + a2.del(b2));

        // Демонстрация методов read и display
        System.out.println("\n=== Демонстрация read() и display() ===");
        FuzzyNumber inputNumber = new FuzzyNumber();
        inputNumber.read();
        System.out.print("Введенное число: ");
        inputNumber.display();


       inputNumber.add(b2);
        FuzzyNumber result = inputNumber.add(a2);
        System.out.println("A + B (для введеного и а2)= " + result);
        result.toString();
        System.out.println("\nдля стринга" + result);
    }
}
