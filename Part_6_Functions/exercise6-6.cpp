#include <iostream>
#include <cmath>

int factorial(int n) {
    if (n > 0) {
        return n * factorial(n - 1);
    } else if (n == 0) {
        return 1;
    } else {
        throw std::invalid_argument("n must be positive");
    }
}

int pascals_triangle_value(int n, int m) {
    if (n == 0 || m == 0 || m == n) {
        return 1;
    }
    return (factorial(n) / (factorial(m) * factorial(n - m)));
}

void print_row(int n) {
    int val;
    std::cout << "Pascals triangle row " << n << ":" << std::endl;
    for (int i = 0; i <= n; ++i) {
        val = pascals_triangle_value(n, i);
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int sumate(int n) {
    int sum = 0;
    std::cout << "Pascals triangle row " << n << ":" << std::endl;
    for (int i = 0; i <= n; ++i) {
        sum += pascals_triangle_value(n, i);
    }
    return sum;
}

int fib(int n) {
    int num = 0;
    int num_next = 1;
    int interim;
    for (int i = 0; i < n; ++i) {
        interim = num_next;
        num_next = num + num_next;
        num = interim;
    }
    return num;
}

int fib_with_pas(int n) {
    int sum = 0;
    for (int i = 0; i <= floor(n / 2); ++i) {
        sum += pascals_triangle_value(n - i, i);
    }
    return sum;
}

int main() {
    print_row(5);
    int sum = sumate(5);
    std::cout << sum << std::endl;
    std::cout << fib(17) << " " << fib_with_pas(17);
    return 0;
}