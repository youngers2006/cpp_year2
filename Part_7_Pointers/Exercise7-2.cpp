#include <iostream>
#include <cmath>

namespace array_funcs {
    float* insert(float a[], float val, int p) {
        a[p+1] = val; 
        return a;
    }
    float* insertSort(float a[], int size) {
        for (int i = 1; i < size; ++i) {
            float current_num = a[i];
            int j = i - 1;
            while (j >= 0 && current_num < a[j]) {
                a = insert(a, a[j], j);
                j--;
            }
            a = insert(a, current_num, j);
        }
        return a;
    }
}

int main() {
    float a[3] = {6.0, 2.0, 1.0};
    float* a_sorted = array_funcs::insertSort(a, 3);
    for (int i = 0; i < 3; ++i) {
        std::cout << a_sorted[i] << std::endl;
    }
    return 0;
}

