// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

// Объявления функций с новыми сигнатурами
unsigned int faStr1(const std::string& str);
unsigned int faStr2(const std::string& str);
unsigned int faStr3(const std::string& str);

int main() {
    // Пример использования функций
    std::string text = "Пример текста для анализа";
    unsigned int result1 = faStr1(text);
    unsigned int result2 = faStr2(text);
    unsigned int result3 = faStr3(text);

    // Вывод результатов
    std::cout << "faStr1: " << result1 << std::endl;
    std::cout << "faStr2: " << result2 << std::endl;
    std::cout << "faStr3: " << result3 << std::endl;

    return 0;
}
