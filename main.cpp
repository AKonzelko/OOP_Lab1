#include <iostream>
#include "methods.cpp"

int main(){
    FILE *file = fopen("price.txt", "r");
    if (file == NULL){
        perror("Error opening file");
        return -1;
    }
    char line[256];
    money total = {0, 0};
    while (fgets(line, sizeof(line), file)) {
        int quantity;
        money a = cina(line, quantity);
        std::cout << "Гривні: " << a.grn << ", Копійки: " << a.kop << ", Кількість: " << quantity << std::endl;
        a = a * quantity;
        total = total + a;
    }
    print(total);
    round(total);
    print(total);
    fclose(file);
    return 0;
}