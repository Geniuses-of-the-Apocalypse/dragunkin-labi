#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};


void init(Time &t, int h, int m, int s) {
    m += s / 60;
    s = s % 60;
    if (s < 0) {
        s += 60;
        m -= 1;
    }
    
    h += m / 60;
    m = m % 60;
    if (m < 0) {
        m += 60;
        h -= 1;
    }
    
    h = h % 24;
    if (h < 0) {
        h += 24;
    }
    
    t.hours = h;
    t.minutes = m;
    t.seconds = s;
}

void read(Time &t) {
    cout << "Введите время в формате 'часы минуты секунды': ";
    int h, m, s;
    cin >> h >> m >> s;
    init(t, h, m, s);
}

void display(const Time &t) {
    cout << (t.hours < 10 ? "0" : "") << t.hours << ":"
         << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
         << (t.seconds < 10 ? "0" : "") << t.seconds;
}

string toString(const Time &t) {
   string result = "";
    result += (t.hours < 10 ? "0" : "") + to_string(t.hours) + ":";
    result += (t.minutes < 10 ? "0" : "") + to_string(t.minutes) + ":";
    result += (t.seconds < 10 ? "0" : "") + to_string(t.seconds);
    return result;
}

void initFromString(Time &t, const string &timeStr) {
   int h = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int m = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
    int s = (timeStr[6] - '0') * 10 + (timeStr[7] - '0');
    
    init(t, h, m, s);
}

void initFromSeconds(Time &t, int totalSeconds) {
    int h = totalSeconds / 3600;
    int m = (totalSeconds % 3600) / 60;
    int s = totalSeconds % 60;
    init(t, h, m, s);
}

void initFromTime(Time &t, const Time &other) {
    t.hours = other.hours;
    t.minutes = other.minutes;
    t.seconds = other.seconds;
}

int differenceInSeconds(const Time &t1, const Time &t2) {
    int sec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int sec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    return abs(sec1 - sec2);
}

void addSeconds(Time &t, int secondsToAdd) {
    int totalSeconds = t.hours * 3600 + t.minutes * 60 + t.seconds + secondsToAdd;
    initFromSeconds(t, totalSeconds);
}

int compare(const Time &t1, const Time &t2) {
    if (t1.hours != t2.hours) {
        return (t1.hours < t2.hours) ? -1 : 1;
    }
    if (t1.minutes != t2.minutes) {
        return (t1.minutes < t2.minutes) ? -1 : 1;
    }
    if (t1.seconds != t2.seconds) {
        return (t1.seconds < t2.seconds) ? -1 : 1;
    }
    return 0;
}

int toSeconds(const Time &t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

int toMinutes(const Time &t) {
    double totalMinutes = (t.hours * 3600.0 + t.minutes * 60.0 + t.seconds) / 60.0;
    return round(totalMinutes);
}

int main() {
    cout << "=== РАБОТА СО ВРЕМЕНЕМ ===" << endl;
    cout << endl;
    
    Time t1, t2, t3, t4;
    
    cout << "1. ТЕСТИРОВАНИЕ ИНИЦИАЛИЗАЦИИ:" << endl;
    
    init(t1, 10, 30, 45);
    cout << "Инициализация числами (10, 30, 45): " << toString(t1) << endl;
    
    initFromString(t2, "14:25:30");
    cout << "Инициализация из строки ('14:25:30'): " << toString(t2) << endl;
    
    initFromSeconds(t3, 3665); // 1 час 1 минута 5 секунд
    cout << "Инициализация из секунд (3665): " << toString(t3) << endl;
    
    initFromTime(t4, t1);
    cout << "Инициализация копированием (из t1): " << toString(t4) << endl;
    
    cout << endl;
    
    cout << "2. ТЕСТИРОВАНИЕ ВВОДА С КЛАВИАТУРЫ:" << endl;
    Time t5;
    read(t5);
    cout << "Вы ввели: ";
    display(t5);
    cout << endl;
    
    cout << endl;
    
    cout << "3. ТЕСТИРОВАНИЕ ОПЕРАЦИЙ:" << endl;
    
    
    cout << "Разница между " << toString(t1) << " и " << toString(t2) 
         << " в секундах: " << differenceInSeconds(t1, t2) << endl;
    

    Time t6;
    initFromTime(t6, t1); 
    cout << "До добавления секунд: " << toString(t6);
    addSeconds(t6, 120); 
    cout << ", после добавления 120 секунд: " << toString(t6) << endl;
    
    int compResult = compare(t1, t2);
    cout << "Сравнение " << toString(t1) << " и " << toString(t2) << ": ";
    if (compResult < 0) cout << "t1 < t2";
    else if (compResult > 0) cout << "t1 > t2";
    else cout << "t1 = t2";
    cout << endl;
    
    cout << "Время " << toString(t1) << " в секундах: " << toSeconds(t1) << endl;
    cout << "Время " << toString(t1) << " в минутах: " << toMinutes(t1) << endl;
    
    cout << endl;
    
    cout << "4. ТЕСТИРОВАНИЕ ГРАНИЧНЫХ СЛУЧАЕВ:" << endl;
    
    Time t7;
    init(t7, 0, 0, 125);
    cout << "125 секунд нормализуется в: " << toString(t7) << endl;
    
    Time t8;
    init(t8, 0, 75, 0);
    cout << "75 минут нормализуется в: " << toString(t8) << endl;
    
    Time t9;
    init(t9, 23, 59, 59);
    cout << "Перед полуночью: " << toString(t9);
    addSeconds(t9, 1);
    cout << ", после добавления 1 секунды: " << toString(t9) << endl;
    
    Time t10;
    init(t10, 0, 0, -1); 
    cout << "-1 секунда нормализуется в: " << toString(t10) << endl;
    
    cout << endl;
    
    cout << "5. ДЕМОНСТРАЦИЯ ВСЕХ МЕТОДОВ:" << endl;
    Time demoTime;
    
    cout << "Исходное время: ";
    init(demoTime, 15, 45, 20);
    display(demoTime);
    cout << endl;
    
    cout << "В строковом формате: " << toString(demoTime) << endl;
    cout << "В секундах: " << toSeconds(demoTime) << endl;
    cout << "В минутах: " << toMinutes(demoTime) << endl;
    
    cout << "После добавления 100 секунд: ";
    addSeconds(demoTime, 100);
    display(demoTime);
    cout << endl;
    
    return 0;
}
