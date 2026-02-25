package lab3java;

interface Array {
    Array add(Array other);
    void print();
}


class Decimal implements Array {
    private String digits;
    private boolean sign;


    public Decimal(String s) {

        String zeros = "";
        for (int i = 0; i < 100; i++) zeros += "0";
        digits = zeros;


        if (s.charAt(0) == '-') {
            sign = false;
            s = s.substring(1);
        } else {
            sign = true;
            if (s.charAt(0) == '+') s = s.substring(1);
        }


        char[] chars = digits.toCharArray();

        for (int i = 0; i < s.length(); i++) {
            chars[i] = s.charAt(s.length() - 1 - i);
        }

        digits = new String(chars);
    }


    private int getDigit(int pos) {
        return digits.charAt(pos) - '0';
    }


    private void setDigit(int pos, int value) {
        char[] chars = digits.toCharArray();
        chars[pos] = (char)(value + '0');
        digits = new String(chars);
    }


    public Array add(Array other) {
        Decimal b = (Decimal)other;
        Decimal result = new Decimal("0");

        int carry = 0;  // перенос


        for (int i = 0; i < 100; i++) {
            int sum = getDigit(i) + b.getDigit(i) + carry;
            result.setDigit(i, sum % 10);
            carry = sum / 10;
        }

        result.sign = this.sign;
        return result;
    }


    public void print() {
        if (!sign) System.out.print("-");


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
