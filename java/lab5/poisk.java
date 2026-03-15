package lab005java;
import java.util.*;
import java.util.regex.*;
import java.util.Scanner;
public class poisk {
    public static int poisk1(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        Set<String> uniqueWords = new HashSet<>();
        while (matcher.find()) {
            String word = matcher.group().toLowerCase();
            uniqueWords.add(word);}
        int a= uniqueWords.size();
        System.out.println(a);
        return a;}
    public static String vvod(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("введите строку");
        String text = scanner.nextLine();
        System.out.println("вы ввели " + text);
        return text;}}
