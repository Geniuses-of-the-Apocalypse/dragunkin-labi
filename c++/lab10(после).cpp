#include <iostream>
using namespace std;

template<typename... Args> auto product16(Args... args) {
    return (args * ...);}
int main() {
    auto result1 = product16(2, 3, 4);        
    cout<<result1<<endl;
    auto result2 = product16(1.5, 2.1, 3.0);  
    cout<<result2<<endl;
    auto result3 = product16(5);               
    cout<<result3<<endl;
     auto result4 = product16(1, 2, 3, 4, 5, 6);
    cout<<result4;
    return 0;}
