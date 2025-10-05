#include <iostream>
#include <cstdlib>
#include <utility>

namespace stats {
    float mean(float arr[], int size) {
        float sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        float mean = sum / size;
        return mean;
    }
    std::pair<float, float> max_min(float arr[], int size) {
        float init = arr[0];
        float min = init; 
        float max = init;
        float num;
        for (int i = 1; i < size; ++i) {
            num = arr[i];
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            } 
        }
        return std::make_pair(max, min);
    }
}

float rand_val;
float randArr[100];

int main() {
    int seed;
    std::cout << "Enter a seed value: " << std::endl;
    std::cin >> seed;
    srand(seed);
    for (int i = 0; i < 100; ++i) {
        rand_val = rand() % 100 + 1; // % (max - min + 1) + min
        randArr[i] = rand_val;
    }
    float mean = stats::mean(randArr, 100);
    std::pair<float, float> result = stats::max_min(randArr, 100);
    float max = result.first;
    float min = result.second;
    std::cout << "mean: " << mean << std::endl;
    std::cout << "max: " << max << std::endl;
    std::cout << "min: " << min << std::endl;
    return 0;
}