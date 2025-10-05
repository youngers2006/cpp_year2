#include <iostream>
#include <cmath>

namespace my_program{
    int fib(int n) {
        int x_1 = 1;
        int x_2 = 1;
        int x;
        for (int i = 2; i < n; ++i) {
            x = x_1 + x_2;
            x_2 = x_1;
            x_1 = x;
        }
        return x;
    }
}

int main() {
    int n;
    std::cout << "What term of the fibonacci sequence do you want: " << std::endl;
    std::cin >> n;
    int x = my_program::fib(n);
    std::cout << x << std::endl;
    return 0;
}