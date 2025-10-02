#include <iostream>
#include <cmath>

float compute_vel(float m, float Cd, int t);
float compute_vel_terminal(float m, float Cd);

const float g = 9.81;

int t1 = 3;
int t2 = 5;
int t3 = 10;

int main() {
    float mass, Cd;
    std::cout << "Enter the mass of the parachutist: " << std::endl;
    std::cin >> mass;
    std::cout << "Enter coefficient of drag of the parachutist: " << std::endl;
    std::cin >> Cd;

    float v1 = compute_vel(mass, Cd, t1);
    float v2 = compute_vel(mass, Cd, t2);
    float v3 = compute_vel(mass, Cd, t3);
    float v_term = compute_vel_terminal(mass, Cd);

    std::cout << "V at 3 seconds: " << v1 << std::endl;
    std::cout << "V at 5 seconds: " << v2 << std::endl;
    std::cout << "V at 10 seconds: " << v3 << std::endl;
    std::cout << "Terminal Velocity: " << v_term << std::endl;
    return 0;
}

float compute_vel(float m, float Cd, int t) {
    float V = ((m * g) / Cd) * (exp(-(Cd * t) / m) - 1.0);
    return V;
}

float compute_vel_terminal(float m, float Cd) {
    float t = -(m / Cd) * log(1 / g);
    float V = compute_vel(m, Cd, t); 
    return V;
}