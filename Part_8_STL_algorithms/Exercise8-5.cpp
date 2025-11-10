#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace program {
    namespace dataEnter {
        std::vector<double> prompt_user() {
            bool continue_ = true;
            double data;
            std::vector<double> data_container;
            while (continue_) {
                std::cout << "Please Enter Data: " << std::endl;
                std::cin >> data;
                data_container.push_back(data);
                std::cout << "Continue? Enter 1 for continue and 0 to end." << std::endl;
                std::cin >> continue_;
            }
            return data_container;
        }
    }
    namespace sortAlgorithms {
        std::vector<double> insert_sort(std::vector<double> data_vec) {
            for (std::vector<double>::iterator vIt_i = data_vec.begin(); vIt_i != data_vec.end(); ++vIt_i) {
                std::vector<double>::iterator vIt_j = vIt_i - 1;
                double current_num = *vIt_i;
                vIt_i = data_vec.erase(vIt_i);
                while (vIt_j != data_vec.begin() && current_num < *vIt_j) {
                    vIt_j--;
                }
                data_vec.insert(vIt_j, *vIt_i);
            }
            return data_vec;
        }
    }
}

int main() {
    std::vector<double> data_vec = program::dataEnter::prompt_user();
    std::vector<double> data_vec_sorted = program::sortAlgorithms::insert_sort(data_vec);
    std::for_each(data_vec.begin(), data_vec.end(), [] (const double& x) { std::cout << x << std::endl; });
    std::for_each(data_vec_sorted.begin(), data_vec_sorted.end(), [] (const double& x) { std::cout << x << std::endl; });
    return 0;
}
