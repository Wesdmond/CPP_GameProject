#include "readtext.h"
#include <iostream>
#include <fstream>
void Display(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return;
    }

    int lineCount;
    file >> lineCount;
    file.ignore();

    std::string line;
    for (int i = 0; i < lineCount; ++i) {
        std::getline(file, line);
        std::cout << line << std::endl;
    }
    file.close();
    std::cout << std::endl;
}