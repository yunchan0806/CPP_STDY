#include <iostream>

int main() {
    int a = 3;
    int& another_a = a;
    another_a = 5;
    std::cout << a << std::endl;
    std::cout << another_a << std::endl;
    
    return 0;
}