// import function header files
#include <iostream>
#include <cmath>
#include <vector>

// define function headers for use in the code
double f(double x);
double trapezium_approx(double* x_arr, double* f_arr, int n);

int main() {
    // define a and b and accept user input
    double a; 
    double b; 
    std::cout << "Please input value for a" << std::endl;
    std::cin >> a;
    std::cout << "Please input value for b" << std::endl;
    std::cin >> b;

    // while a and b are not appropriate request the user tries again with the a and b input
    while (b < a) {
        std::cout << "b must be > a" << std::endl;
        std::cout << "Please input value for a" << std::endl;
        std::cin >> a;
        std::cout << "Please input value for b" << std::endl;
        std::cin >> b;
    }

    // accept user input for n
    int n; 
    std::cout << "Please input value for n" << std::endl;
    std::cin >> n;

    // while n is not appropriate request the user tries again with the n input
    while (n <= 1) {
        std::cout << "n must be > 1" << std::endl;
        std::cout << "Please input value for n" << std::endl;
        std::cin >> n;
    }

    // dynamically allocate memory of input size n
    double* x_arr = new double[n](); 
    double* f_arr = new double[n]();

    // define step size value delta x
    double delta_x = (b - a) / (n - 1.0);

    // loop through the evaluation and x containers and input the values for f(x) and x
    x_arr[0] = a;
    for (int i = 1; i < n; ++i) {
        x_arr[i] = x_arr[i - 1] + delta_x;
        f_arr[i] = f(x_arr[i]);
    }

    // use the defined integral evalutaion function to evaluate th integral
    double integral_eval = trapezium_approx(x_arr, f_arr, n);

    // output value to the terminal
    std::cout << "Integral value is: " << integral_eval << std::endl;

    // delete arrays to prevent data leaks
    delete[] x_arr;
    delete[] f_arr;

    // return 0 for the compiler
    return 0;
}

double f(double x) {
    // use given equation to calulate value for f(x)
    return sin(3.1415 * x);
}

double trapezium_approx(double* x_arr, double* f_arr, int n) {
    // define function return value 
    double Integral = 0.0;

    // loop through summation and use the defined equation to calculate the return value
    for (int i = 0; i < n - 1; ++i) {
        Integral += (x_arr[i+1] - x_arr[i]) * ((f_arr[i+1] + f_arr[i]) / 2.0);
    }

    // return the evaluation of the integral
    return Integral;
}