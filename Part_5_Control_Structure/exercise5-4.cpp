#include <iostream>
#include <cmath>

int factorial(int n);

int main() {
    int n;
    std::cout << "Enter Value To Find Factorial: " << std::endl;
    std::cin >> n;
    int n_f = factorial(n);
    std::cout << "n Factorial: " << n_f << std::endl;
}

int factorial(int n) {
    int n_f = 1;
    for (int i = 1; i < n+1; ++i) {
        n_f *= i;
    }
    return n_f;
}