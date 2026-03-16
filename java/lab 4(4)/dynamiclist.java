package lab4java;

public class str implements inter<str>, Comparable<str> {
    private String value;

    public str(String value) {
        this.value = value;
    }

    // Меньше (<)
    @Override
    public str men(str other) {
        if (this.value.compareTo(other.value) < 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Меньше или равно (<=)
    @Override
    public str menr(str other) {
        if (this.value.compareTo(other.value) <= 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Равно (==)
    @Override
    public str raf(str other) {
        if (this.value.equals(other.value)) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Больше (>)
    @Override
    public str bol(str other) {
        if (this.value.compareTo(other.value) > 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Больше или равно (>=)
    @Override
    public str bolr(str other) {
        if (this.value.compareTo(other.value) >= 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Копия объекта
    @Override
    public str suur() {
        return new str(this.value);
    }


    @Override
    public int compareTo(str other) {
        return this.value.compareTo(other.value);
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value;
    }
}
