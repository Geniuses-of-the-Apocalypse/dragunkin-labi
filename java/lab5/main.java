package lab005java;
public class main {
        public static void main(String[] args) {
            String text = "Hello world! Hello, WORLD. This is a test text. I am caterpillar";
            int result = poisk.poisk1(text);
            System.out.println("Количество уникальных слов: " + result);
            String text2 = "Java java JAVA Python python";
            System.out.println("Уникальных слов во втором тексте: " + poisk.poisk1(text2));
            poisk t= new poisk(); poisk a = new poisk(); a.poisk1(t.vvod());}}
