package lab3java;

class Hex implements Array {
    private String digits;


    public Hex(String s) {
        String zeros = "";
        for (int i = 0; i < 100; i++) zeros += "0";
        digits = zeros;


        if (s.startsWith("0x") || s.startsWith("0X")) {
            s = s.substring(2);
        }

        s = s.toUpperCase();


        char[] chars = digits.toCharArray();

        for (int i = 0; i < s.length(); i++) {
            chars[i] = s.charAt(s.length() - 1 - i);
        }

        digits = new String(chars);
    }


    private int hexCharToInt(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        return c - 'A' + 10;
    }


    private char intToHexChar(int n) {
        if (n < 10) return (char)(n + '0');
        return (char)(n - 10 + 'A');
    }


    private int getDigit(int pos) {
        return hexCharToInt(digits.charAt(pos));
    }


    private void setDigit(int pos, int value) {
        char[] chars = digits.toCharArray();
        chars[pos] = intToHexChar(value);
        digits = new String(chars);
    }


    public Array add(Array other) {
        Hex b = (Hex)other;
        Hex result = new Hex("0");

        int carry = 0;


        for (int i = 0; i < 100; i++) {
            int sum = getDigit(i) + b.getDigit(i) + carry;
            result.setDigit(i, sum % 16);
            carry = sum / 16;
        }

        return result;
    }


    public void print() {
        System.out.print("0x");

        int i = 99;
        while (i > 0 && digits.charAt(i) == '0') {
            i--;
        }

        for (int j = i; j >= 0; j--) {
            System.out.print(digits.charAt(j));
        }
        System.out.println();
    }
}
