package lab4java;


public class str implements inter {
    private String value;

    public str(String value) {
        this.value = value;
    }

    // Меньше (<)
    @Override
    public inter men(inter other) {
        str o = (str) other;
        if (this.value.compareTo(o.value) < 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Меньше или равно (<=)
    @Override
    public inter menr(inter other) {
        str o = (str) other;
        if (this.value.compareTo(o.value) <= 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Равно (==)
    @Override
    public inter raf(inter other) {
        str o = (str) other;
        if (this.value.equals(o.value)) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Больше (>)
    @Override
    public inter bol(inter other) {
        str o = (str) other;
        if (this.value.compareTo(o.value) > 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Больше или равно (>=)
    @Override
    public inter bolr(inter other) {
        str o = (str) other;
        if (this.value.compareTo(o.value) >= 0) {
            return new str("true");
        } else {
            return new str("false");
        }
    }

    // Копия объекта
    @Override
    public inter suur() {
        return new str(this.value);
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value;
    }
}
