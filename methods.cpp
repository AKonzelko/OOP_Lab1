#include "header.h"
#include <cstdio>
#include <regex>
#include <cstring>

money cina(const char* line, int &quantity) {
    std::regex pattern(R"((\d+)\s*грн[,.\s]*(\d+)\s*коп[,.\s]*(\d+)\s*шт)");
    std::cmatch match;
    money result = {0, 0};
    quantity = 1;

    if (std::regex_search(line, match, pattern)) {
        result.grn = std::stoi(match[1]);
        result.kop = static_cast<short int>(std::stoi(match[2]));
        quantity = std::stoi(match[3]);
    }

    return result;
}

money operator+(const money& obj1, const money& obj2){
    money result;
    result.grn = obj1.grn + obj2.grn;
    result.kop = obj1.kop + obj2.kop;

    if(result.kop >= 100){
        result.grn++;
        result.kop -= 100;
    }
    return result;
}

money operator*(const money& obj, int num){
    money result;
    result.grn = obj.grn * num;
    result.kop = obj.kop * num;

    if(result.kop >= 100){
        result.grn += result.kop / 100;
        result.kop %= 100;
    }
    return result;
}

void round(money &obj) {
    if (obj.kop >= 95) {
        obj.grn++;
        obj.kop = 0;
    } else {
        obj.kop = ((obj.kop + 5) / 10) * 10;
    }
}

void print(const money &total) {
    std::cout << "Загальна вартість товарів: Гривні: " << total.grn << ", Копійки: " << total.kop << std::endl;
}
