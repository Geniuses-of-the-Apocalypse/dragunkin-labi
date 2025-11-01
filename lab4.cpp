#include <iostream>
#include <string>
#include <sstream>
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
    
    void read() {
        cout << "Введите время (часы минуты секунды): ";
        cin >> hours >> minutes >> seconds;
        normalize();
    }
    
    void display() const {
        cout << *this;
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
        int sec1 = toSeconds();
        int sec2 = other.toSeconds();
        return abs(sec1 - sec2);
    }

    void addSeconds(int secondsToAdd) {
        *this += secondsToAdd;
    }
    
    int compare(const Time &other) const {
        if (*this < other) return -1;
        if (*this > other) return 1;
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


    Time operator+(int secondsToAdd) const {
        Time result(*this);
        result += secondsToAdd;
        return result;
    }
    
    Time operator-(int secondsToSubtract) const {
        return *this + (-secondsToSubtract);
    }
    
    Time& operator+=(int secondsToAdd) {
        int totalSeconds = toSeconds() + secondsToAdd;
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;
        normalize();
        return *this;
    }
    
    Time& operator-=(int secondsToSubtract) {
        return *this += (-secondsToSubtract);
    }

    bool operator<(const Time &other) const {
        if (hours != other.hours) return hours < other.hours;
        if (minutes != other.minutes) return minutes < other.minutes;
        return seconds < other.seconds;
    }
    
    bool operator>(const Time &other) const {
        return other < *this;
    }
    
    bool operator==(const Time &other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    friend ostream& operator<<(ostream &os, const Time &t) {
        os << (t.hours < 10 ? "0" : "") << t.hours << ":"
           << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
           << (t.seconds < 10 ? "0" : "") << t.seconds;
        return os;
    }
};

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ КЛАССА TIME С ИСПОЛЬЗОВАНИЕМ ПЕРЕГРУЗОК ===" << endl;
    cout << endl;
    
    cout << "1. РАЗЛИЧНЫЕ СПОСОБЫ СОЗДАНИЯ ОБЪЕКТОВ:" << endl;
    
    Time t1;
    Time t2(10, 30, 45);
    Time t3("14:25:30");
    Time t4(3665);
    
    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;
    cout << "t3 = " << t3 << endl;
    cout << "t4 = " << t4 << endl;
    
    cout << endl;
    

    cout << "2. АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ:" << endl;
    

    Time t5 = t2 + 120;
    cout << t2 << " + 120 секунд = " << t5 << endl;
    
    Time t6 = t2 - 60;
    cout << t2 << " - 60 секунд = " << t6 << endl;
    

    Time t7 = t2;
    t7 += 300;
    cout << t2 << " += 300 секунд = " << t7 << endl;
    
    Time t8 = t2;
    t8 -= 150;
    cout << t2 << " -= 150 секунд = " << t8 << endl;
    

    Time t9 = t2 + 60 + 30;
    cout << t2 << " + 60 + 30 = " << t9 << endl;
    
    cout << endl;
    

    cout << "3. ОПЕРАТОРЫ СРАВНЕНИЯ:" << endl;
    
    Time morning(8, 0, 0);
    Time noon(12, 0, 0);
    Time evening(18, 0, 0);
    
    cout << morning << " < " << noon << " : " << (morning < noon ? "true" : "false") << endl;
    cout << evening << " > " << noon << " : " << (evening > noon ? "true" : "false") << endl;
    cout << morning << " == " << Time(8, 0, 0) << " : " << (morning == Time(8, 0, 0) ? "true" : "false") << endl;
    

    if (morning < noon) {
        cout << morning << " действительно раньше чем " << noon << endl;
    }
    
    cout << endl;
    

    cout << "4. РАБОТА С МАССИВАМИ С ИСПОЛЬЗОВАНИЕМ ПЕРЕГРУЗОК:" << endl;
    
    Time schedule[4] = {
        Time(9, 0, 0),
        Time(11, 30, 0),
        Time(14, 15, 0),
        Time(16, 45, 0)
    };
    
    cout << "Расписание занятий:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Занятие " << (i + 1) << ": " << schedule[i] << endl;
    }
    

    cout << "Расписание после сдвига на 15 минут:" << endl;
    for (int i = 0; i < 4; i++) {
        schedule[i] += 900;
        cout << "Занятие " << (i + 1) << ": " << schedule[i] << endl;
    }
    
    cout << endl;
    
    cout << "5. КОМБИНАЦИЯ ПЕРЕГРУЗОК И МЕТОДОВ:" << endl;
    
    Time start(9, 0, 0);
    Time end = start + 7200;  
    
    cout << "Начало: " << start << endl;
    cout << "Конец: " << end << endl;
    

    cout << "Продолжительность: " << start.differenceInSeconds(end) << " секунд" << endl;
    
   
    Time check1 = start + 1800;  // 30 минут
    Time check2 = start + 3600;  // 1 час
    
    cout << "Проверка 1 (30 мин): " << check1 << endl;
    cout << "Проверка 2 (1 час): " << check2 << endl;
    

    if (start < check1 && check1 < check2 && check2 < end) {
        cout << "Все временные точки в правильном порядке!" << endl;
    }
    
    cout << endl;
    

    cout << "6. ОБЯЗАТЕЛЬНЫЕ МЕТОДЫ ЧЕРЕЗ ПЕРЕГРУЗКИ:" << endl;
    
    Time demo(2, 30, 45);
    
    // display() использует перегрузку <<
    cout << "display(): "; demo.display(); cout << endl;
    
    // toString() использует перегрузку <<
    cout << "toString(): " << demo.toString() << endl;
    
    // addSeconds() использует перегрузку +=
    cout << "До addSeconds(120): " << demo;
    demo.addSeconds(120);
    cout << " | После: " << demo << endl;
    
    // compare() использует перегрузки <, >, ==
    Time other(3, 0, 0);
    cout << "compare(" << demo << ", " << other << "): " << demo.compare(other) << endl;
    
    cout << endl;
    

    cout << "7. СЛОЖНЫЕ ВЫРАЖЕНИЯ:" << endl;
    
    Time base(10, 0, 0);
    
    Time result = base + 3600 - 600 + 120;
    cout << base << " + 1 час - 10 минут + 2 минуты = " << result << endl;

    Time deadline(17, 0, 0);
    Time current = base + 25000;
    
    cout << "Текущее время: " << current << endl;
    cout << "Дедлайн: " << deadline << endl;
    
    if (current > deadline) {
        cout << "Опаздываем!" << endl;
    } else {
        cout << "Успеваем!" << endl;
    }
    
    cout << endl;
    

    cout << "8. ГРАНИЧНЫЕ СЛУЧАИ:" << endl;
    
    Time midnight(23, 59, 59);
    cout << "Полночь: " << midnight;
    cout << " | Через 2 секунды: " << (midnight + 2) << endl;
    
    Time newDay = midnight + 1;
    cout << "Новый день: " << newDay << endl;
    

    Time big = Time(0, 0, 0) + 100000;
    cout << "100000 секунд от полуночи: " << big << endl;
    
    cout << endl;
    cout << "=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << endl;
    
    return 0;
}
