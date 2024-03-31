// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

// Функция для подсчета слов без цифр в строке
unsigned int faStr1(const char* input) {
    unsigned int wordCounter = 0;

    while (*input) {
        // Пропустить пробельные символы
        while (*input && std::isspace(*input)) ++input;

        // Если начало слова найдено
        if (*input && !std::isspace(*input)) {
            bool digitFound = false;
            // Продолжаем до пробела или конца строки
            while (*input && !std::isspace(*input)) {
                if (std::isdigit(*input)) {
                    digitFound = true;
                    break;
                }
                ++input;
            }
            // Увеличиваем счетчик, если цифр нет
            if (!digitFound) ++wordCounter;
        }
        // Пропустить оставшиеся символы слова
        while (*input && !std::isspace(*input)) ++input;
    }

    return wordCounter;
}

// Функция для подсчета слов, начинающихся с заглавной буквы
unsigned int faStr2(const char* input) {
    unsigned int capitalizedWordCounter = 0;
    bool isStartOfWord = false;

    while (*input) {
        if (std::isalpha(*input) && !isStartOfWord) {
            if (std::isupper(*input)) {
                ++input;
                while (std::isalpha(*input) && std::islower(*input)) ++input;
                if (std::isspace(*input)) ++capitalizedWordCounter;
            } else {
                ++input;
                continue;
            }
        } else {
            if (!std::isspace(*input)) {
                isStartOfWord = false;
            } else {
                isStartOfWord = true;
            }
            ++input;
        }
    }

    return capitalizedWordCounter;
}

// Функция для вычисления средней длины слов в строке
unsigned int faStr3(const char* input) {
    unsigned int totalLength = 0;
    unsigned int totalWords = 0;
    bool isInsideWord = false;

    while (*input) {
        if (std::isalpha(*input)) {
            if (!isInsideWord) {
                isInsideWord = true;
                ++totalWords;
            }
            ++totalLength;
        } else {
            isInsideWord = false;
        }
        ++input;
    }
    return totalWords ? totalLength / totalWords : 0;
}
