#include <iostream>
#include <cmath>

double* grid_maker(const int& N);
double* eval_sin_grid(double* grid, const int& N);
double* eval_derivative_grid(double* grid, const int& N);
double* apply_deriv(double* grid, const int& N);

int main() {
    int N;
    std::cout << "Enter value for N: " << std::endl;
    std::cin >> N;
    double* grid = grid_maker(N);
    double* f_grid = eval_sin_grid(grid, N);
    double* f_prime_grid = eval_derivative_grid(grid, N);
    double* real_f_prime_grid = apply_deriv(grid, N);
    double error = 0;
    for (int i = 0; i < N-1; ++i) {
        error += std::abs(real_f_prime_grid[i] - f_prime_grid[i]);
    }
    std::cout << error << std::endl;
    delete[] grid;
    delete[] f_grid;
    delete[] f_prime_grid;
    delete[] real_f_prime_grid;
    return 0;
}

double* grid_maker(const int& N) {
    double* arr = new double[N]();
    double factor = 1.0 / (N - 1.0);
    for (int i = 1; i < N; ++i) {
        arr[i] = arr[i - 1] + factor;
    }
    return arr;
}

double* eval_sin_grid(double* grid, const int& N) {
    double* arr = new double[N]();
    for (int i = 0; i < N; ++i) {
        arr[i] = sin(3.1415 * grid[i]); 
    }
    return arr;
}

double* apply_deriv(double* grid, const int& N) {
    double* arr = new double[N]();
    for (int i = 0; i < N; ++i) {
        arr[i] = 3.1415 * cos(3.1415 * grid[i]); 
    }
    return arr;
}

double* eval_derivative_grid(double* grid, const int& N) {
    double* deriv = new double[N]();
    double h = 1.0 / (N - 1.0);
    for (int i = 0; i < N-1; ++i) {
        deriv[i] = (sin(3.1415 * grid[i + 1]) - sin(3.1415 * grid[i])) / h; 
    }
    return deriv;
}