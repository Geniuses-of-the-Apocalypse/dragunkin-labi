#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds = seconds % 60;
        if (seconds < 0) {
            seconds += 60;
            minutes -= 1;
        }
        
        hours += minutes / 60;
        minutes = minutes % 60;
        if (minutes < 0) {
            minutes += 60;
            hours -= 1;
        }
        
        hours = hours % 24;
        if (hours < 0) {
            hours += 24;
        }
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }
    
    Time(const string &timeStr) {
        // Парсинг строки формата "HH:MM:SS"
        hours = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
        minutes = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
        seconds = (timeStr[6] - '0') * 10 + (timeStr[7] - '0');
        normalize();
    }
    
    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        normalize();
    }
    
    Time(const Time &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    
    void read() {
        cout << "Введите время (часы минуты секунды): ";
        cin >> hours >> minutes >> seconds;
        normalize();
    }
    
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds;
    }
    
    string toString() const {
        string result = "";
        
       if (hours < 10) result += '0';
    result += to_string(hours);
    result += ':';
    
   
    if (minutes < 10) result += '0';
    result += to_string(minutes);
    result += ':';
    
    if (seconds < 10) result += '0';
    result += to_string(seconds);
        
        return result;
    }
    

    int differenceInSeconds(const Time &other) const {
        int sec1 = hours * 3600 + minutes * 60 + seconds;
        int sec2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return abs(sec1 - sec2);
    }
    
    void addSeconds(int secondsToAdd) {
        int totalSeconds = toSeconds() + secondsToAdd;
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        normalize();
    }
    
    int compare(const Time &other) const {
        if (hours != other.hours) {
            return (hours < other.hours) ? -1 : 1;
        }
        if (minutes != other.minutes) {
            return (minutes < other.minutes) ? -1 : 1;
        }
        if (seconds != other.seconds) {
            return (seconds < other.seconds) ? -1 : 1;
        }
        return 0;
    }
    

    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
    
   
    int toMinutes() const {
        return round(toSeconds() / 60.0);
    }
    

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
};

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ КЛАССА TIME ===" << endl;
    cout << endl;
    
    cout << "1. СОЗДАНИЕ ОБЪЕКТОВ РАЗНЫМИ СПОСОБАМИ:" << endl;
    
    Time t1;
    cout << "Конструктор без аргументов: ";
    t1.display();
    cout << endl;
    
    Time t2(10, 30, 45);
    cout << "Конструктор числами (10,30,45): " << t2.toString() << endl;
    
    Time t3("14:25:30");
    cout << "Конструктор строкой ('14:25:30'): " << t3.toString() << endl;
    
    Time t4(3665); // 3665 секунд = 1 час 1 минута 5 секунд
    cout << "Конструктор секундами (3665): " << t4.toString() << endl;
    

    Time t5(t2);
    cout << "Конструктор копирования (из t2): " << t5.toString() << endl;
    
    cout << endl;
    
    cout << "2. РАБОТА С МАССИВАМИ ОБЪЕКТОВ:" << endl;

    Time times1[3];
    cout << "Массив Time times1[3] (по умолчанию): ";
    for (int i = 0; i < 3; i++) {
        times1[i].display();
        cout << (i < 2 ? ", " : "");
    }
    cout << endl;
    
    // Массив с явной инициализацией
    Time times2[3] = {Time(1, 15, 30), Time("08:45:00"), Time(7200)};
    cout << "Массив с разной инициализацией: ";
    for (int i = 0; i < 3; i++) {
        times2[i].display();
        cout << (i < 2 ? ", " : "");
    }
    cout << endl;
    
    cout << endl;
    
 
    cout << "3. ОБЯЗАТЕЛЬНЫЕ ОПЕРАЦИИ:" << endl;
    
 
    cout << "Разница между " << t2.toString() << " и " << t3.toString() 
         << ": " << t2.differenceInSeconds(t3) << " секунд" << endl;
    
 
    Time t6(t2); 
    cout << "До добавления секунд: " << t6.toString();
    t6.addSeconds(150); 
    cout << ", после +150 секунд: " << t6.toString() << endl;
    
   
    int compareResult = t2.compare(t3);
    cout << "Сравнение " << t2.toString() << " и " << t3.toString() << ": ";
    switch (compareResult) {
        case -1: cout << "первое время РАНЬШЕ"; break;
        case 0: cout << "времена РАВНЫ"; break;
        case 1: cout << "первое время ПОЗЖЕ"; break;
    }
    cout << endl;
    

    cout << t2.toString() << " в секундах: " << t2.toSeconds() << endl;
    

    cout << t2.toString() << " в минутах: " << t2.toMinutes() << endl;
    
    cout << endl;
    

    cout << "4. ДЕМОНСТРАЦИЯ ВВОДА С КЛАВИАТУРЫ:" << endl;
    Time userTime;
    userTime.read();
    cout << "Вы ввели: " << userTime.toString() << endl;
    
    cout << endl;
    

    cout << "5. ТЕСТИРОВАНИЕ ГРАНИЧНЫХ СЛУЧАЕВ:" << endl;
    

    Time overflow(23, 59, 59);
    cout << "Переполнение: " << overflow.toString();
    overflow.addSeconds(2);
    cout << " + 2 секунды = " << overflow.toString() << endl;
    
 
    Time negative(0, 0, -10);
    cout << "Отрицательные секунды (0,0,-10): " << negative.toString() << endl;
    
   
    Time big(25, 70, 80);
    cout << "Большие значения (25,70,80): " << big.toString() << endl;
    
    cout << endl;
    
   
    cout << "6. ДОПОЛНИТЕЛЬНЫЕ ТЕСТЫ:" << endl;
    
   
    Time test(15, 45, 30);
    cout << "Тестовое время: " << test.toString() << endl;
    cout << "Метод display(): "; test.display(); cout << endl;
    cout << "Метод toString(): " << test.toString() << endl;
    cout << "Геттеры: hours=" << test.getHours() 
         << ", minutes=" << test.getMinutes() 
         << ", seconds=" << test.getSeconds() << endl;
    
    cout << endl;
    cout << "=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << endl;
    
    return 0;
}
