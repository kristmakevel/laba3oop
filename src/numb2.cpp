#include <iostream>
#include <vector>
#include <memory>
#include <fstream>


int* auto_filling(int size, int mult) {
    int* auto_fill_arr = new int[size];
    for (int i = 0; i < size; i++) {
        auto_fill_arr[i] = (i + 1) * mult;
    }
    return auto_fill_arr;
}


void array_not_that_wrong(int size, int mult, std::vector<int>& arr) {
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


class Files {
    std::unique_ptr<std::fstream> file;
public:
    explicit Files(const std::string& file_name) {
        file = std::make_unique<std::fstream>(file_name, std::ios::out);
        if (!file->is_open()) throw std::runtime_error("can't open a file");
    }
    void writing(const std::string& data) { *file << data; } //записываем данные в файл
    ~Files() { if (file) file->close(); } //деструктор, закрываем файл

};


int main() {
    for (int i = 0; i < 10; i += 1) {
        auto idk = std::make_unique<int>(500);
    }
    Files fh("test.txt");
    fh.writing("idk something");
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
    array_not_that_wrong(size, mult, ar);
    return 0;
}
