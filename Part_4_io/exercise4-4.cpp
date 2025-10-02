#include <iostream>
#include <cmath>

float compute_deflection(float L, float E, float I, float w, float x);

int main() {
    float L, E, I, w;
    std::cout << "Input beam length: " << std::endl;
    std::cin >> L;
    std::cout << "Input YM: " << std::endl;
    std::cin >> E;
    std::cout << "Input second moment of inertia: " << std::endl;
    std::cin >> I;
    std::cout << "Input magnitude of distributed load: " << std::endl;
    std::cin >> w;

    float x = L / 2;
    float y = compute_deflection(L, E, I, w, x);
    std::cout << "Defletion of the beam: " << y << std::endl;
    return 0;
}

float compute_deflection(float L, float E, float I, float w, float x) {
    float y = -(w/(24*E*I)) * (pow(x,4) - 2.0 * L * pow(x,3) + pow(L,3) * x);
    return y;
}