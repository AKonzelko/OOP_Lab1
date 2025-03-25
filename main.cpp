#include <iostream>
#include "methods.cpp"
#include <cstdio>

using namespace std;

int main() {
    FILE *file = fopen("price.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    char line[256];
    money total = {0, 0};
    while (fgets(line, sizeof(line), file)) {
        int quantity;
        money obj = {0, 0};
        cina(line, obj, quantity);
        cout << "Гривні: " << obj.grn << ", Копійки: " << obj.kop << ", Кількість: " << quantity << endl;
        multiply(obj, quantity);
        addition(total, obj);
    }
    print(total);
    round(total);
    print(total);
    fclose(file);
    return 0;
}
