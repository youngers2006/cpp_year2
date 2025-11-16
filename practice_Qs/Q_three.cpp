#include <iostream>
#include <cmath>
#include <stdexcept>

// define functions to be used in the code.
int factorial_calc(int n);
double e_approx(double x, int N);
double tanh_approx(double x, int N);

int main() {
    // Taking N as user input and ensuring it is within boundaries.
    int N;
    std::cout << "Enter a value of N" << std::endl;
    std::cin >> N;

    // Loop continues to prompt user till N is within boundaries.
    while (N <= 0) {
        std::cout << "Value of N invalid, N > 0. Please try again: " << std::endl;
        std::cin >> N; 
    }

    // Take user input for x.
    double x;
    std::cout << "Enter a value of x" << std::endl;
    std::cin >> x;

    // Calculate approximation for tanh with e function and compare to cmath approximatio by calculating abs error.
    double approx = tanh_approx(x, N);
    double actual = tanh(x);
    double error = std::abs(approx - actual);

    // output results to the terminal for the user.
    std::cout << "Actual value: " << actual << std::endl;
    std::cout << "Approx value: " << approx << std::endl;
    std::cout << "Error: " << error << std::endl;
    return 0;
}

int factorial_calc(int n) {
    if (n == 0) {
        return 1; // factorial of 0 = 1 so return 0 in this case
    } else if (n > 0) {
        return n * factorial_calc(n-1); // recursively work from n back to 0 using a recursion of factorial functions.
    } else {
        throw std::invalid_argument("n must be positive."); // factorial of a negative number is not defined so throw error
    }
}

double e_approx(double x, int N) {
    double approx = 0; // initialise the sum as 0.
    for (int n = 0; n <= N; ++n) {
        // for each value of n find the term in the sum and add to summation.
        approx += (1 / factorial_calc(n)) * pow(x, n); 
    }
    // return the summation.
    return approx;
}

double tanh_approx(double x, int N) {
    // calculate tanh using relation shown in the question using e approximations.
    return (e_approx(x, N) - e_approx(-x, N)) / (e_approx(x, N) + e_approx(-x, N));
}