#include <iostream>
using namespace std;

struct Pair { 
    int first; 
    double second; 

    void init(int a, double b) {
        if (a == 0 && b == 0) {
            cout << "ОШИБКА: A=0 и B=0 " << endl;
            cout << "Так нельзя! попробуйте снова" << endl;
            exit(-1);
        }
        first = a;
        second = b;
        cout << "Уравнение успешно инициализировано!" << endl;
    }

    void read() {
        int a;
        double b;
        
        cout << "Введите коэффициент A (целое число): ";
        cin >> a;
        cout << "Введите коэффициент B (дробное число): ";
        cin >> b;
        
        init(a, b);
    }

    void display() {
        cout << "y = " << first << " * x + " << second << endl;
    }

    double function(double x) {
        return first * x + second;
    }
};

int main() {
    Pair p;
    
    cout << "Линейное уравнение y = Ax + B" << endl;
    
    cout << "Попытка 1: init(2, 3.5) - нормальные значения" << endl;
    p.init(2, 3.5);
    p.display();
    
    cout << "\nМетод read (с проверкой через init)" << endl;
    p.read();
    
    cout << "Введенное уравнение: ";
    p.display();
    
    // Вычисление значения
    double x;
    cout << "Введите x: ";
    cin >> x;
    double result = p.function(x);
    cout << p.first << " * " << x << " + " << p.second << " = " << result << endl;
    
    return 0;
}
