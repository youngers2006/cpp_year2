#include <iostream>
#include <cmath>

double** create_mat(int N, int M, double val);
void print_mat(double** mat, int N, int M);
double** mat_mul_square(double** mat1, double** mat2, int N);

int main() {
    double** mat1 = create_mat(2, 2, 1.5);
    double** mat2 = create_mat(2, 2, 1.5);
    double** mat3 = mat_mul_square(mat1, mat2, 2);
    print_mat(mat3, 2, 2);
    return 0;
}

double** create_mat(int N, int M, double val) {
    double **mat = new double*[N];
    for (int i = 0; i < N; ++i) {
        mat[i] = new double[M]();
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            mat[i][j] = val;
        }
    }
    return mat;
}

void print_mat(double** mat, int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << mat[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

double** mat_mul_square(double** mat1, double** mat2, int N) {
    double** mat_3 = new double*[N];
    for (int i = 0; i < N; ++i) {
        mat_3[i] = new double[N]();
    }
    double res = 0;
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res += mat1[i][k] * mat2[k][j];
            }
            mat_3[i][j] = res;
            res = 0;
        }
    }
    return mat_3;
}
