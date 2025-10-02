#include <iostream>
#include <cmath>

float vel_solver(int t, float y0);
float pos_solver(int t, float y0);

const float g = 9.8;

int main() {
    float y0;
    int T;
    std::cout << "Enter initial height: ";
    std::cin >> y0;
    std::cout << "Enter time: ";
    std::cin >> T;
    float V = vel_solver(T, y0);
    float Y = pos_solver(T, y0);
    std::cout << "Velocity at time T: " << V << std::endl;
    std::cout << "Position at time T: " << Y << std::endl;
    return 0;
}

float vel_solver(int t, float y0) {
    float V = -g * t;
    return V;
}

float pos_solver(int t, float y0) {
    float Y = -0.5 * g * pow(t,2);
    return Y;
}