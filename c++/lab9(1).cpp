#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Twin {
private:
    T first;
    T second;

public:
    Twin(T f = T(), T s = T()) : first(f), second(s) {}
    
    void swap() {
        T temp = first;
        first = second;
        second = temp; }
    
    T getFirst() const {  return first; } 
    T getSecond() const { return second;}  
    void setFirst(T value) { first = value; }
    void setSecond(T value) {second = value;}
    string toString() const {
        return "(" + to_string(first) + ", " + to_string(second) + ")";
    }
    void clear() {
        first = T();
        second = T();
    }
    friend ostream& operator<<(ostream& os, const Twin& twin) {
        os << "(" << twin.first << ", " << twin.second << ")";
        return os;
    }
    friend istream& operator>>(istream& is, Twin& twin) {
        is >> twin.first >> twin.second; 
        return is;
    }
};
int main() {
    Twin<int> intPair;
    cout << "Введите два целых числа через пробел: ";
    cin >> intPair;
    cout << "Целая пара: " << intPair << endl;
    intPair.clear();
    Twin<double> doublePair;
    cout << "Введите два дробных числа через пробел: ";
    cin >> doublePair;
    cout << "Дробная пара: " << doublePair << endl;
    cout << "toString: " << doublePair.toString() << endl;
    cout<< "обмен местами"<<endl;
    doublePair.swap();
    cout << "Дробная пара: " << doublePair << endl;
    cout << "toString: " << doublePair.toString() << endl;
    doublePair.clear();
    
    return 0;
}
