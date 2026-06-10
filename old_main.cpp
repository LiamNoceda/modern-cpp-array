#include <iostream>
#include <limits>

int main() {
    std::cout << "Wasm-Array\n";
    std::cout << "\tMax elements to enter is 6\n";
    std::cout << "\tArray type Integer\n";
    std::cout << "\tArray numbers 4 - 5 - 1 - 8 - 10 - 2\n\n";

    const int max{6};
    int numbers[max];
    int i{};

    std::cout << "Create your own array:\n";

    while (i < max) {
        std::cout << "\tEnter number [" << i + 1 << "]: "; 
        std::cin >> numbers[i];

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        i++;
    }

    std::cout << "\n";

    std::cout << "Your array info:\n";
    std::cout << "\tElements entered: ";

    for (i = 0; i < max; i++) {
        std::cout << numbers[i];
        if (i < max - 1) {
            std::cout << " - ";
        }
    }

    std::cout << "\n";
    return 0;
}
