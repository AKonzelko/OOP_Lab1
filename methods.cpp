#include "header.h"
#include <cstdio>
#include <regex>
#include <cstring>

int cina(const char *line, int &quantity, int &grn, int &kop) {
    std::regex pattern(R"((\d+)\s*грн[,.\s]*(\d+)\s*коп[,.\s]*(\d+)\s*шт)");
    std::cmatch match;
    quantity = 1;

    if (std::regex_search(line, match, pattern)) {
        grn = std::stoi(match[1]);
        kop = std::stoi(match[2]);
        quantity = std::stoi(match[3]);
    }

    return 0;
}

int addiction(int grn1, int kop1, int grn2, int kop2, int &resultGrn, int &resultKop) {
    resultGrn = grn1 + grn2;
    resultKop = kop1 + kop2;

    if (resultKop >= 100) {
        resultGrn++;
        resultKop -= 100;
    }

    return 0;
}

int multiply(int grn, int kop, int num, int &resultGrn, int &resultKop) {
    resultGrn = grn * num;
    resultKop = kop * num;

    if (resultKop >= 100) {
        resultGrn += resultKop / 100;
        resultKop %= 100;
    }

    return 0;
}

void round(int &grn, int &kop) {
    if (kop >= 95) {
        grn++;
        kop = 0;
    } else {
        kop = ((kop + 5) / 10) * 10;
    }
}

void print(const int &totalGrn, const int &totalKop) {
    std::cout << "Загальна вартість товарів: Гривні: " << totalGrn << ", Копійки: " << totalKop << std::endl;
}
