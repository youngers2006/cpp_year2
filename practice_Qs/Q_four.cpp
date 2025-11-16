#include <iostream>
#include <cmath>

// define functions
double ln_approx(double y, int N);
double cosh_inv_approx(double x, int N);

int main() {
    // revieve and validate x input
    double x;
    std::cout << "Please enter a value for x." << std::endl;
    std::cin >> x;

    // while loop to ensure that x is input correctly and will continuously prompt the user until successful
    while (x < 1.0) {
        std::cout << "value for x must be >= 1. Please try again." <<std::endl;
        std::cin >> x;
    }

    // revieve and validate N input
    int N;
    std::cout << "Please enter a value for N." << std::endl;
    std::cin >> N;

    // while loop to ensure that N is input correctly and will continuously prompt the user until successful
    while (N <= 0) {
        std::cout << "value for N must be > 0. Please try again." <<std::endl;
        std::cin >> N;
    }

    // Use approximate and cmath functions to calculate acosh values and find the error
    double approx_acosh = cosh_inv_approx(x, N);
    double acosh_acc = acosh(x);
    double error = std::abs(approx_acosh - acosh_acc);

    // return all found values to the terminal
    std::cout << "approximate: " << approx_acosh << std::endl;
    std::cout << "real: " << acosh_acc << std::endl;
    std::cout << "error: " << error << std::endl;
    return 0;
}

double ln_approx(double y, int N) {
    // initialise the return value
    double approx = 0; 

    // loop through each item of the summation in the equation given in the test sheet
    for (int k = 0; k <= N; ++k) {
        approx += (2 / (2 * k - 1)) * pow((y - 1) / (y + 1), 2 * k - 1);
    }

    // return found value
    return approx;
}

double cosh_inv_approx(double x, int N) {
    // using equation in the test sheet, return the approximated value.
    return ln_approx(x + pow(pow(x, 2) - 1.0, 0.5), N);
}