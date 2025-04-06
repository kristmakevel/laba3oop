#include <iostream>
#include <vector>

int* auto_filling(int size, int mult) {
    int* auto_fill_arr = new int[size];
    for (int i = 0; i < size; i++) {
        auto_fill_arr[i] = (i + 1) * mult;
    }
    return auto_fill_arr;
}


void array_wrong(int size, int mult, std::vector<int>& arr) {
    std::cout << "write all of the numbers for the second array \n";
    int x = 0;
    for (int i = 0; i < size; i++) {
        auto new_n = std::make_unique<int>(); //умный указатель -> память очистится когда функция отработает
        std::cin >> x;
        *new_n = x * mult;
        arr[i] = *new_n;
    }
    std::cout << "your second array: \n";
    for (int i = 0;i < size;i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int size = 0;
    int mult = 0;
    std::cout << "enter size: ";
    std::cin >> size;
    std::cout << "enter the number you want to multiply to: ";
    std::cin >> mult;

    int* arr = auto_filling(size, mult);
    std::cout << "your first array: \n";
    for (int i = 0;i < size;i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    delete[] arr; // есть delete -> без утечки

    std::vector <int> ar(size);
    array_wrong(size, mult, ar);
    return 0;
}