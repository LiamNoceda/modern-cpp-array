# Modern C++ Array Console Application

Интерактивное консольное приложение на C++, демонстрирующее оптимизацию работы с массивами фиксированного размера, валидацию потока ввода и проведение глубокого рефакторинга кодовой базы под стандарты C++17 и C++20.

## Профессиональные навыки, продемонстрированные в проекте

1. **Безопасные контейнеры (C++11+)**: Применение `std::array` вместо классических C-массивов для гарантированной безопасности работы со стековой памятью.
2. **Оптимизация строковых констант (C++17)**: Использование `std::string_view` для статических строк, что исключает динамическое выделение памяти (аллокации в куче).
3. **Range-based цикл с инициализатором (C++20)**: Использование расширенного синтаксиса цикла `for` для локализации счетчика индексов внутри области видимости цикла.
4. **Синхронизация знаковости типов**: Приведение всех переменных индексов и размеров к единому типу `int32_t` для предотвращения предупреждений компилятора о сравнении знаковых и беззнаковых чисел.

---

## Анализ рефакторинга: Сравнение старой и новой архитектуры

Ниже представлен детальный разбор изменений, внесенных в проект в процессе его оптимизации.

### Исходная версия (Самый первый вариант кода)
Использование устаревшего стиля управления памятью и вывода данных:
```cpp
const int max{6};
int numbers[max]; // Небезопасный C-массив
int i{};

// ... (ввод данных)

for (i = 0; i < max; i++) {
    std::cout << numbers[i];
    if (i < max -1) {
        std::cout << " - ";
    }
}
std::cout << std::endl; // Потенциально избыточный сброс буфера (flush) внутри программы
```

### Актуальная версия (Финальный оптимизированный вариант)
Безопасный стек, строгая изоляция данных и соответствие современным стандартам:
```cpp
constexpr int32_t max_elements{6};
std::array<int, max_elements> numbers{}; // Замена на безопасный std::array

// ... (ввод данных)

// Внедрен синтаксис C++20. Счетчик index изолирован внутри цикла
for (int32_t index{0}; const int32_t& num : numbers) {
    std::cout << num;
    if (index < max_elements - 1) { // Безопасное сравнение знаковых типов (int32_t и int32_t)
        std::cout << " - ";
    }
    index++;
}
```

### Ключевые архитектурные изменения
* **Безопасность памяти**: `std::array` хранит данные в стеке так же эффективно, как и массив в стиле C, но защищает от случайного выхода за границы памяти и предоставляет доступ к методам контейнеров.
* **Изоляция переменных**: В первой версии переменная `i` оставалась доступна в области видимости всей функции `main` после завершения циклов. В новой версии счетчик `index` существует только внутри блока `for`.
* **Устранение предупреждений компилятора**: В исходной версии или промежуточных вариантах возникал риск сравнения знаковых (`int`) и беззнаковых (`std::size_t`) типов данных при вызове `.size()`. В финальной версии все индексы приведены к `int32_t`, а условие проверки изменено на сравнение с константой `max_elements`, что полностью исключает предупреждения (warnings) компилятора.

---

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

    std::array<int32_t, max_elements> numbers{};
    int32_t i{};

    std::cout << "Create your own array\n";

    while (i < max_elements) {
        std::cout << "\tNumber[" << i + 1 << "]: ";
        std::cin >> numbers[i];

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
std::cout << "\t[Error] Invalid input! Please enter an integer.\n";
            continue;
        }

        i++;
    }

    std::cout << "\nYour array info:\n";
    std::cout << "\tElements entered: ";

    for (int32_t index{0}; const int32_t& num : numbers) {
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
clang++ -std=c++20 main.cpp -o modern_array

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
	[Error] Invalid input! Please enter an integer.
	Number[2]: 20
	Number[3]: 30
	Number[4]: 40
	Number[5]: 50
	Number[6]: 60

Your array info:
	Elements entered: 10 - 20 - 30 - 40 - 50 - 60
```

---
