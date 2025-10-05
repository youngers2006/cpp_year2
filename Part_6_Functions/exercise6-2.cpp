#include <iostream>

void swap(int& a, int& b, int& c) {
    int inter_a = a;
    a = b;
    b = c;
    c = inter_a;
}

int main() {
    int a = 5;
    int b = 2;
    int c = 8;
    swap(a, b, c);
    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}