#include <iostream>

using namespace std;


template<typename T>
concept SequenceApplicable = integral<T>;

template<SequenceApplicable T>
struct SequenceResult {
    T data[100];  
    int count;
};

template<SequenceApplicable T>
constexpr SequenceResult<T> make_sequence(T start, T step, int count) {
    SequenceResult<T> result{};
    for (int i = 0; i < count; i++) {
        result.data[i] = start + i * step;
    }
    result.count = count;
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    constexpr auto seq1 = make_sequence<int>(2, 5, 4);  
    constexpr auto seq2 = make_sequence<long>(10, -2, 5); 

    cout << "Последовательность 1: ";
    for (int i = 0; i < seq1.count; i++)
        cout << seq1.data[i] << " ";

    cout << "\nПоследовательность 2: ";
    for (int i = 0; i < seq2.count; i++)
        cout << seq2.data[i] << " ";

    return 0;
}
