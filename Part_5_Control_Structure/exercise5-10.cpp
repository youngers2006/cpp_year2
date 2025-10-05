#include <iostream>
#include <random>

int main() {
    int count = 0;
    int guess;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 100);
    int num_to_guess = distrib(gen);
    while (count != 5) {
        std::cout << "Guess Number Between 0 And 100: " << std::endl;
        std::cin >> guess;
        if (guess == num_to_guess) {
            std::cout << "You guessed correctly" << std::endl;
            return 0;
        } else {
            std::cout << "Thats Incorrect." << std::endl;
            count++;
        }
    }
    std::cout << "Thats your 5 guesses." << std::endl;
    std::cout << "The number was: " << num_to_guess << std::endl;
    return 0;
}