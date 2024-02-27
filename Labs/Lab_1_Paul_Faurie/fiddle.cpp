#include <iostream>
#include <sstream>
#include <string>


int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    int number;
    if (iss >> number) {
        std::cout << "Integer entered: " << number << std::endl;
    } else {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
    }

    return 0;
}