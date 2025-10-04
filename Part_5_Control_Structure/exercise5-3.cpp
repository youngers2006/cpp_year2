#include <iostream>
#include <cmath>

double approx_1(int n);
double approx_2(int n);
int n1_finder();
int n2_finder();

int main() {
    int n1 = n1_finder();
    int n2 = n2_finder();
    double pi1 = approx_1(n1);
    double pi2 = approx_2(n2);

    std::cout << "found n values: " << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
    std::cout << "Approximation one result: " << pi1 << std::endl;
    std::cout << "Approximation two result: " << pi2 << std::endl;

    if (n1 < n2) {
        std::cout << "Method one converges faster" << std::endl;
    } else {
        std::cout << "Method two converges faster" << std::endl;
    }

    return 0;
}

double approx_1(int n) {
    double pi_approx = 0.0;
    for (int k = 0; k < n; ++k) {
            pi_approx += (4.0 * pow(-1, k) / (2.0 * k + 1.0));
        }
    return pi_approx;
}
double approx_2(int n) {
    double pi_approx = 2.0;
    for (int k = 1; k < n; ++k) {
        pi_approx *= (4.0 * pow(k, 2)) / (4.0 * pow(k, 2) - 1.0);
    }
    return pi_approx;
}
int n1_finder() {
    double pi_approx = 0;
    int n = 1;
    while (abs(pi_approx - 3.1415) > 0.0001) {
        pi_approx = approx_1(n);
        n++;
        if (n > 20000) {
            std::cout << "Method one couldnt converge" << std::endl;
            return 0;
        }
    }
    return n;
}
int n2_finder() {
    double pi_approx = 0;
    int n = 1;
    while (abs(pi_approx - 3.1415) > 0.0001) {
        pi_approx = approx_2(n);
        n++;
        if (n > 20000) {
            std::cout << "Method two couldnt converge" << std::endl;
            return 0;
        }
    }
    return n;
}