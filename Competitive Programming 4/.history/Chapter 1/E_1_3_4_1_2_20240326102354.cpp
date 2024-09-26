#include <iostream>
#include <iomanip>
#include <cmath>

void printPi(int precision) {
    std::cout << std::fixed << std::setprecision(precision) << std::acos(-1) << std::endl;
}

int main() {
    int N;
    std::cout << "Enter the number of decimal points for Pi: ";
    std::cin >> N;
    printPi(N);
    return 0;
}
