// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <string>
#include <algorithm>
#include <functional>

// Функция для подсчета слов в строке, которые не содержат цифры
unsigned int faStr1(const std::string& str) {
    unsigned int count = 0; // Счетчик слов
    // Лямбда-функции для проверки символов
    auto isNotSpace = [](char ch) { return !std::isspace(ch); };
    auto isDigit = [](char ch) { return std::isdigit(ch); };

    auto it = str.begin();
    while (it != str.end()) {
        // Находим начало слова
        it = std::find_if(it, str.end(), isNotSpace);
        // Находим конец слова
        auto wordEnd = std::find_if(it, str.end(), std::isspace);
        // Проверяем, есть ли цифры в слове
        if (it != wordEnd && std::none_of(it, wordEnd, isDigit)) {
            ++count; // Увеличиваем счетчик, если слово не содержит цифр
        }
        it = wordEnd;
    }

    return count;
}

// Функция для подсчета слов, начинающихся с заглавной буквы и не содержащих других заглавных букв
unsigned int faStr2(const std::string& str) {
    unsigned int count = 0; // Счетчик слов
    bool inWord = false; // Флаг, находимся ли мы внутри слова

    for (char ch : str) {
        if (std::isalpha(ch)) {
            // Проверяем, является ли символ началом слова
            if (!inWord && std::isupper(ch)) {
                inWord = true; // Начинаем новое слово
            } else if (inWord && std::islower(ch)) {
                continue; // Продолжаем слово, если символ маленькая буква
            }
        } else if (inWord && std::isspace(ch)) {
            ++count; // Увеличиваем счетчик, если слово закончилось
            inWord = false; // Слово закончилось
        } else {
            inWord = false; // Слово закончилось, если символ не буква
        }
    }

    // Проверяем, закончилось ли последнее слово
    if (inWord) {
        ++count;
    }

    return count;
}

// Функция для вычисления средней длины слов в строке
unsigned int faStr3(const std::string& str) {
    unsigned int sumLength = 0; // Суммарная длина слов
    unsigned int wordCount = 0; // Количество слов
    bool inWord = false; // Флаг, находимся ли мы внутри слова

    for (char ch : str) {
        if (std::isalpha(ch)) {
            // Начинаем новое слово или продолжаем текущее
            if (!inWord) {
                inWord = true; // Начинаем новое слово
                ++wordCount; // Увеличиваем счетчик слов
            }
            ++sumLength; // Увеличиваем суммарную длину слов
        } else {
            inWord = false; // Слово закончилось, если символ не буква
        }
    }

    // Возвращаем среднюю длину слова или 0, если слов нет
    return wordCount == 0 ? 0 : sumLength / wordCount;
}
