#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> prime_finder(int n);
bool prime_tester(int num);

int main() {
    int n;
    std::cout << "Enter Number of Primes to be Found: " << std::endl;
    std::cin >> n;
    std::vector<int> primes = prime_finder(n);
    std::cout << "The first n primes are: " << std::endl;
    for (int i : primes) {
        std::cout << i << std::endl;
    }
    return 0;
}

bool prime_tester(int num) {
    int bound = static_cast<int>(sqrt(num));
    if (num <= 1) {
        return false;
    }
    for (int test_num = 2; test_num < bound + 1; ++test_num) {
        if (num % test_num == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int> prime_finder(int n) {
    std::vector<int> primes;
    primes.reserve(n);
    bool is_prime;
    int count = 0;
    int num = 2;
    while (count != n) {
        is_prime = prime_tester(num);
        if (is_prime) {
            primes.push_back(num);
            count += 1;
        } 
        num++;
    }
    return primes;
}