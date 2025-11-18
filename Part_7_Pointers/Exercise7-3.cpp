// write a code that counts the number of appeaances of a certain character in a CSV file
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>

void create_file(std::string filename);
int* counter(std::string filename);

int main() {
    std::string filename = "char_file.txt";
    bool create;
    std::cout << "Do you want to create a file?" << std::endl;
    std::cin >> create;
    if (create) {
        create_file(filename);
    }
    int* count = counter(filename);
    std::cout << "letters counted are: " << std::endl;
    for (int i = 0; i < 26; ++i) {
        std::cout << count[i] << std::endl;
    }
    delete[] count;
    return 0;
}

int* counter(std::string filename) {
    std::ifstream file;
    file.open(filename);
    int* count_arr = new int[26]();
    std::string line;
    std::stringstream sstream;
    while (std::getline(file, line)) {
        sstream << line;
    }
    char c;
    while (sstream >> c) {
        char letter = true;
        int val = int(c);
        if (c >= 65 && c <= 90) {
            c -= 65;
        } else if (c >= 97 && c <= 122) {
            c -= 97;
        } else {
            letter = false;
        }
        if (letter) {
            count_arr[c] += 1;
        }
    } 
    return count_arr;
}

void create_file(std::string filename) {
    char c;
    std::ofstream shit_file(filename);
    for (int i = 0; i < 10; ++i) {
        std::cout << "Char please" << std::endl;
        std::cin >> c;
        shit_file << c;
        if (i != 9) {
            shit_file << " ";
        }
    };
};