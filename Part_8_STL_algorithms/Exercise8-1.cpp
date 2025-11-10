#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

namespace methods {
    namespace method_1 {

    }
    namespace method_2 {

    }
}

int main() {
    int seed;
    std::cout << "Provide seed: " << std::endl;
    std::cin >> seed;
    srand(seed);

    std::vector<double> rand_nums_1(100);
    std::vector<double> rand_nums_2(100);
    std::generate(rand_nums_1.begin(), rand_nums_1.end(), [] () { return rand(); });
    std::generate(rand_nums_2.begin(), rand_nums_2.end(), [] () { return rand(); });
    std::vector<double> sum_nums(100);
    for (
        std::vector<double>::iterator vIt_1 = rand_nums_1.begin(), vIt_2 = rand_nums_2.begin(), vIt_3 = sum_nums.begin(); 
        vIt_1 != rand_nums_1.end() && vIt_2 != rand_nums_2.end() && vIt_3 != sum_nums.end(); 
        ++vIt_1, ++vIt_2, ++vIt_3 
    ) {
        *vIt_3 = *vIt_1 + *vIt_2;
    }

    for (int i = sum_nums.size() - 1; i > 10; --i) {
        sum_nums.pop_back();
    }

    for (std::vector<double>::iterator vIt = sum_nums.begin(); vIt != sum_nums.end(); ++vIt) {
        std::cout << *vIt << std::endl;
    }
    double value;
    std::vector<double> inputs;
    bool continue_ = true;
    while (continue_) {
        std::cout << "Enter a value" << std::endl;
        std::cin >> value;
        inputs.push_back(value);
        std::cout << "Continue?: Enter 1 for yes and 0 for no" << std::endl;
        std::cin >> continue_;
    }
    std::cout << "Inputted value were: " << std::endl;
    for (std::vector<double>::iterator vIt = inputs.begin(); vIt != inputs.end(); ++vIt) {
        std::cout << *vIt << std::endl;
    }
    return 0;
}

