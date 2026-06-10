# Modern C++ Array Console Application

Интерактивное консольное приложение на C++, демонстрирующее оптимизацию работы с массивами фиксированного размера и валидацию потока ввода.

## Профессиональные навыки, продемонстрированные в проекте

1. **Безопасные контейнеры (C++11+)**: Применение `std::array` вместо классических C-массивов для гарантированной безопасности работы со стековой памятью.
2. **Оптимизация строковых констант (C++17)**: Использование `std::string_view` для статических строк, что исключает динамическое выделение памяти (аллокации в куче).
3. **Range-based цикл с инициализатором (C++20)**: Использование расширенного синтаксиса цикла `for` для локализации счетчика индексов внутри области видимости цикла.
4. **Синхронизация знаковости типов**: Приведение всех переменных индексов и размеров к единому типу `int32_t` для предотвращения предупреждений компилятора о сравнении знаковых и беззнаковых чисел.

## Характеристики программы
- Фиксированный размер данных (6 элементов)
- Защита от некорректного ввода (строки, символы) с очисткой входного буфера `std::cin`

## Исходный код проекта

```cpp
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

    while (i < numbers.size()) {
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

    for (int32_t index{0}; const int num : numbers) {
        std::cout << num;
        if (index < max_elements - 1) {
            std::cout << " - ";
        }
        index++;
    }

    std::cout << std::endl;
    return 0;
}
```

## Как скомпилировать и запустить

Для сборки кода требуется компилятор с поддержкой стандарта C++20 (например, GCC 10+, Clang 10+ или MSVC 2019+).

```bash
# Компиляция (флаг -std=c++20 обязателен)
clang++ -std=c++20 n.cpp -o modern_array

# Запуск программы
./modern_array
```

## Пример вывода в консоль

```text
Number-Array
	Max elements to number is 6
	Array type Integer
	Array numbers 0 - 1 - 2 - 3 - 4 - 5

Create your own array
	Number[1]: 10
	Number[2]: abc
	Number[2]: 20
	Number[3]: 30
	Number[4]: 40
	Number[5]: 50
	Number[6]: 60

Your array info:
	Elements entered: 10 - 20 - 30 - 40 - 50 - 60
```
