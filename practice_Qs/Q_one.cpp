#include <iostream>
#include <vector>
#include <cmath>

// define both functions for use in the code
double eval_fn(std::vector<double> coeffs, double x); 
std::vector<double> differentiator(std::vector<double> coeffs);

int main() {
    bool still_going = true;
    double coeff;
    std::vector<double> coeffs;
    while (still_going) {
        std::cout << "input coeff value: " << std::endl;
        std::cin >> coeff;
        std::cout << "adding more?" << std::endl;
        std::cin >> still_going;
        coeffs.push_back(coeff);
    }
    std::cout << "what is the initial value of x0: " << std::endl;
    double x0;
    std::cin >> x0;

    int N = 100;
    int iters = 0;
    double error;
    double xn = x0;
    double xn_;
    double fxn;
    double f_prime_xn;
    std::vector<double> diff_coeffs = differentiator(coeffs);

    do
    {
        fxn = eval_fn(coeffs, xn);
        f_prime_xn = eval_fn(diff_coeffs, xn);
        xn_ = xn - (fxn / f_prime_xn);
        error = abs(xn_ - xn);
        xn = xn_;
        iters++;
    } while (error > pow(10,-8) && iters < N);
    if (iters < N) {
        std::cout << "converged on value: " << xn << std::endl;
    } else {
        std::cout << "did not converge" << std::endl;
    }
    return 0;
}

double eval_fn(std::vector<double> coeffs, double x) {
    double result = 0.0;
    int n = 0;
    for (std::vector<double>::iterator vIt = coeffs.begin(); vIt != coeffs.end(); ++vIt) {
        result += pow(x, n) * *vIt;
        n++;
    }
    return result;
}

std::vector<double> differentiator(std::vector<double> coeffs) {
    double b;
    int n = 0;
    std::vector<double> new_coeffs;
    for (std::vector<double>::iterator vIt = coeffs.begin() + 1; vIt != coeffs.end(); ++vIt) {
        b = *vIt * (n + 1);
        n++;
        new_coeffs.push_back(b);
    }
    return new_coeffs;
}