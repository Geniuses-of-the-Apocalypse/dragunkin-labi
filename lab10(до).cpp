#include <iostream>
using namespace std;

template <typename Arg>
Arg product(Arg arg) { return arg; }
template <typename First, typename... Other>
auto product(First first, Other... other) {
    return first * product(other...);}

int main() {
    auto result1 = product(2, 3, 4);        
    cout<<result1<<endl;
    auto result2 = product(1.5, 2.1, 3.0);  
    cout<<result2<<endl;
    auto result3 = product(5);               
    cout<<result3<<endl;
     auto result4 = product(1, 2, 3, 4, 5, 6);
    cout<<result4;
    return 0;}
