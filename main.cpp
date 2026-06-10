#include <iostream>
#include <limits>
#include <array>
#include <string_view>

int main() {
    constexpr std::string_view title = "Number-Array\n";
    std::cout << title;

    std::cout << "\tMax elements to number is 6\n";
    std::cout << "\tArray type Integer\n";
    std::cout << "\tArray numbers 0 - 1 - 2 - 3 - 4 - 5\n\n";

    constexpr int32_t max_elements{6};

    std::array<int, max_elements> numbers{};
    int32_t i{};

    std::cout << "Create your own array\n";

    while (i < max_elements) {
        std::cout << "\tNumber[" << i + 1 << "]: ";
        std::cin >> numbers[i];

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        i++;
    }

    std::cout << "\nYour array info:\n";
    std::cout << "\tElements entered: ";

    for (int32_t index{0}; const int& num : numbers) {
        std::cout << num;
        if (index < max_elements - 1) {
            std::cout << " - ";
        }
        index++;
    }

    std::cout << std::endl;
    return 0;
}
