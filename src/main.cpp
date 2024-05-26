// Copyright 2024 UNN-IASR
#include "textgen.h"

int main() {
    setlocale(LC_ALL, "Russian");
    build("input.txt");
    std::string generated_text = generate_text(MAXGEN);
    std::cout << generated_text << std::endl;
    return 0;
}