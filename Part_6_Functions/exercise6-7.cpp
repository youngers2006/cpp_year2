#include <iostream>
#include <cmath>
#include <numeric>

namespace my_program {
    namespace euler_solver {
        float y_prime(float y, float lambda) {
            return (lambda * y);
        }
        float next_step_forwards(float y, float lambda, float dt) {
            float y_ = y + y_prime(y, lambda)* dt;
            return y_;
        }
        float euler_integration_forwards(float y0, float lambda, float timestep, float t_f) {
            int num_steps = t_f / timestep;
            float y = y0;
            for (int step = 0; step < num_steps; ++step) {
                y = next_step_forwards(y, lambda, timestep);
            }
            return y;
        }
        float next_step_backwards(float y, float lambda, float dt) {
            float y_ = y / (1 - lambda * dt);
            return y_;
        }
        float euler_integration_backwards(float y0, float lambda, float timestep, float t_f) {
            int num_steps = t_f / timestep;
            float y = y0;
            for (int step = 0; step < num_steps; ++step) {
                y = next_step_backwards(y, lambda, timestep);
            }
            return y;
        }
    }
    namespace evaluation {
        float target_value(float t, float lambda, float y0) {
            float y = y0 * exp(lambda * t);
            return y;
        }
        float error(float prediction, float t_f, float lambda, float y0) {
            float error = std::abs(prediction - target_value(t_f, lambda, y0));
            return error;
        }
    }
}

int main() {
    float tf = 5.0;
    float y0 = 2.0;
    float lambda = 0.8;
    float timestep = 0.001;
    float ytf = my_program::euler_solver::euler_integration_forwards(y0, lambda, timestep, tf);
    float ytb = my_program::euler_solver::euler_integration_forwards(y0, lambda, timestep, tf);
    float errorf = my_program::evaluation::error(ytf, tf, lambda, y0);
    float errorb = my_program::evaluation::error(ytb, tf, lambda, y0);
    float target = my_program::evaluation::target_value(tf, lambda, y0);
    std::cout << "y_tf: " << ytf << std::endl;
    std::cout << "y_tb: " << ytb << std::endl;
    std::cout << "target y_t: " << target << std::endl;
    std::cout << "errorf: " << errorf << std::endl;
    std::cout << "errorb: " << errorb << std::endl;
    return 0;
}