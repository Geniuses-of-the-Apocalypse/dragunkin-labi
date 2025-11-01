#include <iostream>
#include <string>
using namespace std;


class Array {
protected:
   static const int MAX_SIZE = 100; 
    unsigned char data[MAX_SIZE];    
    int size;                        

public:

    Array(int s = 0, unsigned char value = 0) {
        if (s < 0 || s > MAX_SIZE) {
            cout << "Ошибка: недопустимый размер!" << endl;
            exit(1);
        }
        size = s;
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }


    unsigned char& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Ошибка: индекс " << index << " вне диапазона!" << endl;
            exit(1);
        }
        return data[index];
    }


    virtual Array* add(Array& other) {
        cout << "Сложение в базовом классе Array" << endl;
        return new Array(0);
    }


    void display() {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << (int)data[i];
            if (i < size - 1) cout << " ";
        }
        cout << "]" << endl;
    }

    int getSize() { return size; }
};


class Decimal : public Array {
public:
    Decimal(int s = 0, unsigned char value = 0) : Array(s, value) {
      
    }


    Array* add(Array& other) override {
        cout << "Сложение десятичных чисел" << endl;
        

        int maxSize = (size > other.getSize()) ? size : other.getSize();
                Decimal* result = new Decimal(maxSize);
        
        for (int i = 0; i < maxSize; i++) {
            unsigned char sum = 0;
            if (i < size) sum += data[i];
            if (i < other.getSize()) sum += other[i];
            (*result)[i] = sum % 10;  // берем только последнюю цифру
        }
        
        return result;
    }

    void displayDecimal() {
       
        for (int i = size - 1; i >= 0; i--) {
            cout << (int)data[i];
        }
        cout << endl;
    }
};


class Hex : public Array {
public:
    Hex(int s = 0, unsigned char value = 0) : Array(s, value) {}

    
    Array* add(Array& other) override {
        cout << "Сложение шестнадцатеричных чисел" << endl;
        
      
        int maxSize = (size > other.getSize()) ? size : other.getSize();
        Hex* result = new Hex(maxSize);
        
        for (int i = 0; i < maxSize; i++) {
            unsigned char sum = 0;
            if (i < size) sum += data[i];
            if (i < other.getSize()) sum += other[i];
            (*result)[i] = sum % 16;  
        }
        
        return result;
    }

    void displayHex() {
        cout << "0x";
        for (int i = size - 1; i >= 0; i--) {
            if (data[i] < 10) {
                cout << (int)data[i];
            } else {
                cout << (char)('A' + data[i] - 10);
            }
        }
        cout << endl;
    }
    };

int main() {
    cout << "=== ЛАБОРАТОРНАЯ РАБОТА: ВИРТУАЛЬНЫЕ МЕТОДЫ ===" << endl;

   
    cout << "\n1. БАЗОВЫЙ КЛАСС ARRAY:" << endl;
    Array arr1(5, 1);  // массив из 5 элементов со значением 1
    cout << "arr1 = "; arr1.display();

    cout<<"Проверка оператора []"<<endl;
    cout << "arr1[2] = " << (int)arr1[2] << endl;
    arr1[2] = 9;
    cout << "После arr1[2] = 9: "; arr1.display();

  
    cout << "\n2. КЛАСС DECIMAL:" << endl;
    Decimal dec1(3, 5);  // +555
    Decimal dec2(2, 3);  // +33
    
    cout << "dec1 = "; dec1.displayDecimal();
    cout << "dec2 = "; dec2.displayDecimal();

   
    cout << "\n3. КЛАСС HEX:" << endl;
    Hex hex1(3, 10);  // 0xAAA (A=10)
    Hex hex2(2, 5);   // 0x55
    
    cout << "hex1 = "; hex1.displayHex();
    cout << "hex2 = "; hex2.displayHex();

   
    cout << "\n4. ВИРТУАЛЬНЫЕ ФУНКЦИИ СЛОЖЕНИЯ:" << endl;

   
    Array* ptr1 = &dec1;
    Array* ptr2 = &hex1;
    Array* ptr3 = &arr1;

   
    cout << "ptr1->add(dec2): "; 
    Array* result1 = ptr1->add(dec2);
    result1->display();
    delete result1;
    
    cout << "ptr2->add(hex2): ";
    Array* result2 = ptr2->add(hex2);
    result2->display();
    delete result2;

    cout << "ptr3->add(arr1): ";
    Array* result3 = ptr3->add(arr1);
    result3->display();
    delete result3;

  
    cout << "\n5. МАССИВ УКАЗАТЕЛЕЙ НА БАЗОВЫЙ КЛАСС:" << endl;
    Array* objects[3];
    objects[0] = new Decimal(2, 7);  // +77
    objects[1] = new Hex(2, 12);            // 0xCC
    objects[2] = new Array(3, 2);           // [2,2,2]

    for (int i = 0; i < 3; i++) {
        cout << "objects[" << i << "] = ";
        objects[i]->display();
        
        // Вызов виртуального метода
        cout << "objects[" << i << "]->add(*objects[" << i << "]): ";
        Array* result = objects[i]->add(*objects[i]);
        result->display();
        delete result;
    }

   
    cout << "\n6. РАЗНЫЕ ВАРИАНТЫ ВЫЗОВА:" << endl;

    // Прямой вызов
    cout << "Прямой вызов dec1.add(dec2): ";
    Array* directCall = dec1.add(dec2);
    directCall->display();
    delete directCall;

    // Через ссылку базового класса
    Array& ref = hex1;
    cout << "Через ссылку ref.add(hex2): ";
    Array* refCall = ref.add(hex2);
    refCall->display();
    delete refCall;

    
    for (int i = 0; i < 3; i++) {
        delete objects[i];
    }

 
    return 0;
}
