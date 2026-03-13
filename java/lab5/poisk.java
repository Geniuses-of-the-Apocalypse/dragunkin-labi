package lab005java;
import java.util.*;
import java.util.regex.*;
public class poisk {
    public static int poisk1(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        Set<String> uniqueWords = new HashSet<>();
        while (matcher.find()) {
            String word = matcher.group().toLowerCase();
            uniqueWords.add(word);}
        return uniqueWords.size();}}
