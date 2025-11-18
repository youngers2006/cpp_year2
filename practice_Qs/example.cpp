#include <iostream>
#include <cmath>
#include <vector>

double factorial(int x);
double sin_approx(double x, int K);
double cos_approx(double x, int K);

int main() {
    double x; // define input as double

    std::cout << "Please input the value in radians you would like to approximate: " << std::endl;
    std::cin >> x;

    // request loop for input until x is valid argument
    while (x < -1 * M_PI || x > M_PI) { 
        std::cout << "x must be between pi and negative pi. Please try again: " << std::endl;
        std::cin >> x;
    }

    // using C++ sin functions
    double sin_true = sin(x);
    double cos_true = cos(x);

    // using approximation functions
    int K = 5; // define K as 5 per the question
    double sin_est = sin_approx(x, K);
    double cos_est = cos_approx(x, K);

    // calculating y from C++ functions and from estimators
    double y = pow(sin_true, 2) + pow(cos_true, 2);
    double y_est = pow(sin_est, 2) + pow(cos_est, 2);

    // calculating error and returning error
    double error = std::abs(y - y_est);
    std::cout << "Absolute error is: " << error << std::endl;
    return 0;
}

double factorial(int x) {
    if (x > 0) { // check that the value is positive
        return x * factorial(x-1); // run recursive calculation
    } else if (x == 0) { // when the value of x reaches 0 this condition will trigger and return a value, allowing the recusion above.
        return 1.0; // return value for 0, if x = 0 will return 1, if x > 0 will return the factorial of x.
    } else { // if x is negative return a warning and return zero to indicate an incorrect argument
        std::cout << "x must be >= 0" << std::endl;
        return 0.0;
    }
}

double sin_approx(double x, int K) {
    double approx = 0.0; // define output as double
    for (int k = 0; k <= K; ++k) { // loop through each value of k
        approx += (pow(-1,k) * pow(x, 2*k + 1)) / factorial(2 * k + 1); // using equation in the question calculate the approximation
    }
    return approx; // return calculated value
}

double cos_approx(double x, int K) {
    double approx = 0.0; // define output as double
    for (int k = 0; k <= K; ++k) { // loop through each value of k
        approx += (pow(-1,k) * pow(x, 2*k)) / factorial(2*k); // using equation in the question calculate the approximation
    }
    return approx; // return calculated value
}