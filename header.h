#ifndef HEADER_H
#define HEADER_H

struct money {
    int grn;
    short int kop;
};

void cina(const char *line, money &obj, int &quantity);
void addition(money &total, const money &obj);
void multiply(money &obj, int num);
void round(money &obj);
void print(const money &obj);

#endif