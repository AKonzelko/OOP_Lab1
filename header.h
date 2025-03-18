#include <iostream>

struct money{
    int grn;
    short int kop;
};

int cina(const char* line, int &quantity, int &grn, int &kop);

int addition(int grn1, int kop1, int grn2, int kop2, int &resultGrn, int &resultKop);

int multiply(int grn, int kop, int num, int &resultGrn, int &resultKop);

void round(money &obj);

void print(const int &totalGrn, const int &totalKop);