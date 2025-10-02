#include <iostream>

int a = 2;
int b = 5;
int c = 4;

int main() {
    auto result = a + b * c / a * (b - c) + b % c;
    std::cout << "Result is: " << result << std::endl;
    return 0;
}