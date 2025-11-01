#include <iostream>
#include <string>
using namespace std;

class Triad {
protected:
    int first, second, third;

public:
    Triad() : first(0), second(0), third(0) {}
    
    Triad(int f, int s, int t) {
        if (f < 0 || s < 0 || t < 0) {
            cout << "Ошибка: числа не могут быть отрицательными!" << endl;
            exit(1);
        }
        first = f;
        second = s;
        third = t;
    }
    
  
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }
    

    void setFirst(int f) { 
        if (f < 0) {
            cout << "Ошибка: число не может быть отрицательным!" << endl;
            return;
        }
        first = f; 
    }
    
    void setSecond(int s) { 
        if (s < 0) {
            cout << "Ошибка: число не может быть отрицательным!" << endl;
            return;
        }
        second = s; 
    }
    
    void setThird(int t) { 
        if (t < 0) {
            cout << "Ошибка: число не может быть отрицательным!" << endl;
            return;
        }
        third = t; 
    }
    

    bool equals(const Triad& other) const {
        return (first == other.first) && 
               (second == other.second) && 
               (third == other.third);
    }
    
    // Преобразование в строку
    string toString() const {
        return "(" + to_string(first) + ", " + to_string(second) + ", " + to_string(third) + ")";
    }
    
    // Вывод на экран
    void display() const {
        cout << toString();
    }
};

// Производный класс Time
class Time : public Triad {
public:

    Time() : Triad() {}
    
    Time(int h, int m, int s) : Triad(h, m, s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            cout << "Ошибка: недопустимое время!" << endl;
            exit(1);
        }
    }
    

    void normalize() {
        
        while (third >= 60) {
            third -= 60;
            second++;
        }
        while (second >= 60) {
            second -= 60;
            first++;
        }
        while (first >= 24) {
            first -= 24;
        }
    }
    
    
    int getHours() const { return first; }
    int getMinutes() const { return second; }
    int getSeconds() const { return third; }
    
   
    void setHours(int h) {
        if (h < 0 || h > 23) {
            cout << "Ошибка: часы должны быть от 0 до 23!" << endl;
            return;
        }
        first = h;
    }
    
    void setMinutes(int m) {
        if (m < 0 || m > 59) {
            cout << "Ошибка: минуты должны быть от 0 до 59!" << endl;
            return;
        }
        second = m;
    }
    
    void setSeconds(int s) {
        if (s < 0 || s > 59) {
            cout << "Ошибка: секунды должны быть от 0 до 59!" << endl;
            return;
        }
        third = s;
    }
    
   
    bool operator==(const Time& other) const {
        return (first == other.first) && (second == other.second) && (third == other.third);
    }
    
    bool operator!=(const Time& other) const {
        return !(*this == other);
    }
    
    bool operator<(const Time& other) const {
        if (first != other.first) return first < other.first;
        if (second != other.second) return second < other.second;
        return third < other.third;
    }
    
    bool operator>(const Time& other) const {
        return other < *this;
    }
    
    bool operator<=(const Time& other) const {
        return !(other < *this);
    }
    
    bool operator>=(const Time& other) const {
        return !(*this < other);
    }
    
    //прероб в стр
    string toString() const {
        string h = (first < 10) ? "0" + to_string(first) : to_string(first);
        string m = (second < 10) ? "0" + to_string(second) : to_string(second);
        string s = (third < 10) ? "0" + to_string(third) : to_string(third);
        return h + ":" + m + ":" + s;
    }
    
    void display() const {
        cout << toString();
    }
};

int main() {
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА: НАСЛЕДОВАНИЕ ===" << endl;
    
    // 1. ДЕМОНСТРАЦИЯ БАЗОВОГО КЛАССА
    cout << "\n1. БАЗОВЫЙ КЛАСС TRIAD:" << endl;
    
    Triad t1(1, 2, 3);
    Triad t2(4, 5, 6);
    cout << "t1 = "; t1.display(); cout << endl;
    cout << "t2 = "; t2.display(); cout << endl;
    cout << "t1 equals t2: " << (t1.equals(t2) ? "да" : "нет") << endl;
    
    // 2. ДЕМОНСТРАЦИЯ ПРОИЗВОДНОГО КЛАССА
    cout << "\n2. ПРОИЗВОДНЫЙ КЛАСС TIME:" << endl;
    
    Time time1(10, 30, 45);
    Time time2(14, 15, 20);
    cout << "time1 = "; time1.display(); cout << endl;
    cout << "time2 = "; time2.display(); cout << endl;
    
    // 3. МЕТОДЫ СРАВНЕНИЯ
    cout << "\n3. СРАВНЕНИЕ ВРЕМЕНИ:" << endl;
    
    Time morning(8, 0, 0);
    Time noon(12, 0, 0);
    Time evening(18, 0, 0);
    
    cout << "Утро = "; morning.display(); 
    cout << " < Обед = "; noon.display();
    cout << " : " << (morning < noon ? "да" : "нет") << endl;
    
    cout << "Утро = "; morning.display();
    cout << " == Обед = "; noon.display();
    cout << " : " << (morning == noon ? "да" : "нет") << endl;
    
    cout << "Вечер = "; evening.display();
    cout << " > Обед = "; noon.display();
    cout << " : " << (evening > noon ? "да" : "нет") << endl;
    
    
    cout << "\n4. МАССИВЫ ОБЪЕКТОВ:" << endl;
    
    Time times[3] = {Time(9,0,0), Time(12,30,0), Time(17,45,0)};
    for (int i = 0; i < 3; i++) {
        cout << "times[" << i << "] = "; times[i].display(); cout << endl;
    }
    
   
    cout << "\n5. ПРИНЦИП ПОДСТАНОВКИ:" << endl;
    
 
    Time myTime(15, 20, 25);
    cout << "Объект Time: "; myTime.display(); cout << endl;
    

    Triad* triadPtr = &myTime;
    cout << "Через указатель Triad*: "; triadPtr->display(); cout << endl;
    
    
    Triad& triadRef = myTime;
    cout << "Через ссылку Triad&: "; triadRef.display(); cout << endl;
    
  
    cout << "getFirst() для Time: " << myTime.getFirst() << endl;
    cout << "getSecond() для Time: " << myTime.getSecond() << endl;
    cout << "getThird() для Time: " << myTime.getThird() << endl;
    
    
    Triad baseTriad(15, 20, 25);
    cout << "Time equals Triad(15,20,25): " << myTime.equals(baseTriad) << endl;
    
    
    cout << "\nМассив указателей Triad* на разные объекты:" << endl;
    Triad* objects[3];
    objects[0] = new Triad(1, 1, 1);        
    objects[1] = new Time(10, 30, 0);       
    objects[2] = new Triad(2, 2, 2);       
    
    for (int i = 0; i < 3; i++) {
        cout << "objects[" << i << "] = ";
        objects[i]->display();
        cout << " (тип: " << (i == 1 ? "Time" : "Triad") << ")" << endl;
    }
    
   
    for (int i = 0; i < 3; i++) {
        delete objects[i];
    }
    
    
    
    return 0;
}
