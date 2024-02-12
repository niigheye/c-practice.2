//
// Created by sgris on 12.02.2024.
//


#include <iostream>
#include "mymath/mymath.h"
#include "mylib/mylib.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << "И умножать тоже! Зацени 2*2=";
    std::cout << mylib::umn(10, 32) << std::endl;

    return 0;
}