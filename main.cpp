#include <iostream>
#include "methods.cpp"


int main(){
    FILE *file = fopen("price.txt", "r");
    if (file == NULL){
        perror("Error opening file");
        return -1;
    }
    char line[256];
    int totalGrn = 0, totalKop = 0;
    while (fgets(line, sizeof(line), file)) {
        int quantity, grn, kop;
        cina(line, quantity, grn, kop);
        std::cout << "Гривні: " << grn << ", Копійки: " << kop << ", Кількість: " << quantity << std::endl;
        int aGrn, aKop;
        multiply(grn, kop, quantity, aGrn, aKop);
        addiction(totalGrn, totalKop, aGrn, aKop, totalGrn, totalKop);
    }
    print(totalGrn, totalKop);
    round(totalGrn, totalKop);
    print(totalGrn, totalKop);
    fclose(file);
    return 0;
}