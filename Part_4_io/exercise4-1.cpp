#include <iostream>
#include <cmath>

float Vol_calc(float r);
float A_calc(float r);

float pi = 3.1415926;

int main() {
    float r;
    std::cout << "Enter the value for Radius: " << std::endl;
    std::cin >> r;
    float V = Vol_calc(r);
    float A = A_calc(r);
    std::cout << "Volume is: " << V << std::endl;
    std::cout << "Area is: " << A << std::endl;
    return 0;
}

float Vol_calc(float r) {
    float V = 4.0 * pi * pow(r,3);
    return V;
}

float A_calc(float r) {
    float A = 4.0 * pi * pow(r,2);
    return A;
}

