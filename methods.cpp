#include "header.h"
#include <iostream>
#include <regex>
#include <cstring>

void cina(const char *line, money &obj, int &quantity) {
    std::regex pattern(R"((\d+)\s*грн[,.\s]*(\d+)\s*коп[,.\s]*(\d+)\s*шт)");
    std::cmatch match;
    quantity = 1;

    if (std::regex_search(line, match, pattern)) {
        obj.grn = std::stoi(match[1]);
        obj.kop = std::stoi(match[2]);
        quantity = std::stoi(match[3]);
    }
}

void addition(money &total, const money &obj) {
    total.grn += obj.grn;
    total.kop += obj.kop;

    if (total.kop >= 100) {
        total.grn += total.kop / 100;
        total.kop %= 100;
    }
}

void multiply(money &obj, int num) {
    obj.grn *= num;
    obj.kop *= num;

    if (obj.kop >= 100) {
        obj.grn += obj.kop / 100;
        obj.kop %= 100;
    }
}

void round(money &obj) {
    if (obj.kop >= 95) {
        obj.grn++;
        obj.kop = 0;
    } else {
        obj.kop = ((obj.kop + 5) / 10) * 10;
    }
}

void print(const money &obj) {
    std::cout << "Загальна вартість товарів: Гривні: " << obj.grn << ", Копійки: " << obj.kop << std::endl;
}


