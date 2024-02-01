#include <iostream>
#include <cmath>

char get_symbol(const int code) {
    return code < 10 ? (0x30 + code) : ('A' + code - 10);
}

// функция на вход принимает ссылку на число и размер разряда
//функция возвращает разряд числа
int get_digit (int &num, const int digit_size) {
    int digit = 0;
    while (num >= digit_size){
        num -= digit_size;
        ++digit;
    }
    return digit;
}

//функция принимает на вход число (до 32 бит) и указатель на массив строки
void num_to_word(int num, char *str) {
    const int masks[4] = {
        0x0000F000,
        0x00000F00,
        0x000000F0,
        0x0000000F
    };
    const int shifts[4] = {24, 16, 8, 0};
    for (int i = 0; i < 4; ++i) {
        str[i] = get_symbol((num & masks[i]) >> shifts[i]);
    }
}

int main() {
    char str[5] = {0}; //зануляем массив

    num_to_word(0x012f, str);
    std::cout << str << std::endl;
    return 0;
}
