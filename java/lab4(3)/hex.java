package lab3java;


class Hex implements Array {
    private char[] digits;


    public Hex(String s) {
        digits = new char[100];
        for (int i = 0; i < 100; i++) digits[i] = '0';


        if (s.startsWith("0x") || s.startsWith("0X")) {
            s = s.substring(2);
        }
        s = s.toUpperCase();


        for (int i = 0; i < s.length(); i++) {
            digits[i] = s.charAt(s.length() - 1 - i);
        }
    }

    // Преобразование hex-символа в число
    private int hexCharToInt(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        return c - 'A' + 10;
    }

    // Преобразование числа в hex-символ
    private char intToHexChar(int n) {
        if (n < 10) return (char)(n + '0');
        return (char)(n - 10 + 'A');
    }

    // Получение цифры как числа
    private int getDigit(int pos) {
        return hexCharToInt(digits[pos]);
    }

    // Установка цифры из числа
    private void setDigit(int pos, int value) {
        digits[pos] = intToHexChar(value);
    }


    public Array add(Array other) {
        Hex b = (Hex)other;
        Hex result = new Hex("0");
        int carry = 0;

        // Сложение в столбик (основание 16)
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
        while (i > 0 && digits[i] == '0') i--;

        for (int j = i; j >= 0; j--) {
            System.out.print(digits[j]);
        }
        System.out.println();
    }
}

