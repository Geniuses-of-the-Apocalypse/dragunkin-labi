package lab4java;

public interface inter<T extends inter<T>> {
    T men(T other);
    T menr(T other);
    T raf(T other);
    T bol(T other);
    T bolr(T other);
    T suur();
}
