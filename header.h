#include <iostream>

struct money{
    int grn;
    short int kop;
};

money cina(const char* line, int &quantity);

money operator+(const money& obj1, const money& obj2);

money operator*(const money& obj, int num);

void round(money &obj);

void print(const money &total);