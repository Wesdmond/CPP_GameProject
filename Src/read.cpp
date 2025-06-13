#include "read.h"
#include "class.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
std::vector<Weapon> Vw;
std::vector<Creations> Vc;
std::vector< std::pair <int, int>> Ve;
int size = 5;
std::vector<std::vector<int>> array(size, std::vector<int>(size));

void ReadFromFile()
{
    std::ifstream inputFile("Data/data.txt");
    if (!inputFile)
    {
        std::cerr << "Файл не может быть открыт!" << std::endl;
    }
    int number;
    inputFile >> number;  // Читаем количество объектов
    inputFile.ignore();

    for (int i = 0; i < number; ++i)
    {
        int n1, n2, n3, n4, n5, n6, n7, count;
        std::string Name;
        std::pair <int, int> N1;
        std::vector<std::pair<int, int>>N2;

        inputFile >> n1;
        inputFile.ignore();
        getline(inputFile, Name);
        inputFile >> n2;
        inputFile.ignore();
        inputFile >> count;
        inputFile.ignore();
        for (int i = 0; i < count; ++i)
        {
            inputFile >> n3 >> n4;
            N1 = std::make_pair(n3, n4);
            N2.push_back(N1);
        }
        inputFile >> n5 >> n6 >> n7;
        inputFile.ignore();
        Weapon weapon(n1, Name, n2, N2, n5, n6, n7);
        Vw.push_back(weapon);
    }
    inputFile >> number;  // Читаем количество объектов
    inputFile.ignore();
    for (int i = 0; i < number; ++i)
    {
        int n1, n2, n3, n4, n5, n6;
        std::string Name;
        inputFile >> n1;
        inputFile.ignore();
        getline(inputFile, Name);
        inputFile >> n2;
        inputFile.ignore();
        inputFile >> n3;
        inputFile.ignore();
        inputFile >> n4 >> n5 >> n6;
        inputFile.ignore();
        Creations creation(n1, Name, n2, n3, n4, n5, n6);
        Vc.push_back(creation);
    }
    inputFile >> number;  // Читаем количество объектов
    inputFile.ignore();
    for (int i = 0; i < number; ++i)
    {
        int n1, n2;
        std::pair <int, int> N1;

        inputFile >> n1 >> n2;
    #ifdef _DEBUG
        N1 = std::make_pair(n1, n2);
        Ve.push_back(N1);
    #endif
    }
    inputFile >> size;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            inputFile >> array[i][j];
        }
    }
}