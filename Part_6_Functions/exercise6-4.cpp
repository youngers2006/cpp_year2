#include <iostream>
#include <cmath>

namespace my_program {
    int factorial(int n) {
        if (n <= 0) {
            throw std::logic_error("cannot take a negative factorial.");
        }
        int n_f = 1;
        for (int i = 1; i < n+1; ++i) {
            n_f *= i;
        }
        return n_f;
    }
    float binomial_coeff(int n, int k) {
        if (n < k) {
            throw std::logic_error("n must be greater or equal to k.");
        }
        int n_fact = factorial(n);
        int k_fact = factorial(k);
        int n_minus_k_fact = factorial(n - k);
        float bn = n_fact / (k_fact * n_minus_k_fact);
        return bn;    
    }
}

int main() {
    int n;
    int k;
    std::cout << "Enter Value of n: " << std::endl;
    std::cin >> n;
    std::cout << "Enter Value of k: " << std::endl;
    std::cin >> k;
    try {
        int bn = my_program::binomial_coeff(n, k);
        std::cout << "Binmoial Coefficient: " << bn << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}