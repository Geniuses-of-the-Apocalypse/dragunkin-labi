package lab3java;


interface Array {
    Array add(Array other);
    void print();
}


class Decimal implements Array {
    private char[] digits;
    private boolean sign;


    public Decimal(String s) {
        digits = new char[100];
        for (int i = 0; i < 100; i++) digits[i] = '0';


        if (s.charAt(0) == '-') {
            sign = false;
            s = s.substring(1);
        } else {
            sign = true;
            if (s.charAt(0) == '+') s = s.substring(1);
        }


        for (int i = 0; i < s.length(); i++) {
            digits[i] = s.charAt(s.length() - 1 - i);
        }
    }

    // Получение цифры как числа(код аски - 0 аски)
    private int getDigit(int pos) {
        return digits[pos] - '0';
    }

    // Установка цифры из числа
    private void setDigit(int pos, int value) {
        digits[pos] = (char)(value + '0');
    }


    public Array add(Array other) {
        Decimal b = (Decimal)other;
        Decimal result = new Decimal("0");
        int carry = 0;  // Перенос

        // Сложение в столбик
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

        // Поиск первой ненулевой цифры
        int i = 99;
        while (i > 0 && digits[i] == '0') i--;

        // Вывод цифр от старшей к младшей
        for (int j = i; j >= 0; j--) {
            System.out.print(digits[j]);
        }
        System.out.println();
    }
}

