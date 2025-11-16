#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>

int main() {
    srand(42);
    int size = 10;
    std::vector<double> vec1(size);
    std::vector<double> vec2(size);
    std::generate(vec1.begin(), vec1.end(), [] () { return rand(); });
    std::generate(vec2.begin(), vec2.end(), [] () { return rand(); });
    std::for_each(vec1.begin(), vec1.end(), [] (double& x) { std::cout << x << std::endl; });
    std::for_each(vec2.begin(), vec2.end(), [] (double& x) { std::cout << x << std::endl; });
    std::for_each(vec1.begin(), vec1.end(), [] (double& x) { x*=2; });
    std::for_each(vec2.begin(), vec2.end(), [] (double& x) { x*=2; });
    std::for_each(vec1.begin(), vec1.end(), [] (double& x) { std::cout << x << std::endl; });
    std::for_each(vec2.begin(), vec2.end(), [] (double& x) { std::cout << x << std::endl; });
    std::vector<double> dists;
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(dists), [] (double& x, double& y) { return sqrt(pow(x,2) + pow(y,2)); });
    std::for_each(dists.begin(), dists.end(), [] (double& x) { std::cout << x << std::endl; });
    double max = *std::max_element(dists.begin(), dists.end());
    double min = *std::min_element(dists.begin(), dists.end());
    std::cout << "max" << std::endl;
    std::cout << max << std::endl;
    std::cout << "min" << std::endl;
    std::cout << min << std::endl;
    return 0; 
}