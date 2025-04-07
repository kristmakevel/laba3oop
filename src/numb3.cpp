#include <iostream>
#include <memory>
#include <vector>

class archive {
public:
    archive(int persons_id) : persons_id(persons_id) {
        std::cout << "exists now\n"; //создание объекта
    }
    ~archive() {
        std::cout << "doesn't exist from now on:(\n"; //удаление объекта
    }
    void add_data(const std::vector<float>& vectorr) {
        data = vectorr; //копируем вектор в поле data
    }
    const std::vector<float>& give_data() const {
        return data; //возвращаем ссылку на данные
    }
private:
    int persons_id;
    std::vector<float> data;
};

int main() {
    std::cout << "making an archive\n";
    auto first_one = std::make_shared<archive>(500);
    std::vector<float> vect = { 1.2, 2.3, 3.4, 4.5, 5.6 }; //создаем указатель на архив
    first_one->add_data(vect); //добавляем данные
    std::cout << first_one.use_count() << "\n";
    std::cout << "adding two not in a block \n"; 
    //создаем новые использования и смотрим на счетчик
    auto sec_one = first_one;
    std::cout << first_one.use_count() << "\n";
    auto third_one = first_one;
    std::cout << first_one.use_count() << "\n";
    std::cout << "now we have three!\n";
    //собственно вне блока все сохраняется прекрасно
    {
        std::cout << "and now adding two in a block \n";
        auto fourth_one = first_one;
        std::cout << first_one.use_count() << "\n";
        auto fifth_one = first_one;
        std::cout << first_one.use_count() << "\n";
        std::cout << "omg we have five\n";
    }
    //все что было сделано внутри блока остается внутри блока
    std::cout << "and now not in a block again \n";
    std::cout << first_one.use_count() << "\n";
    std::cout << "oh no only three again:(\n";
    //выход из main->объект уничтожается
    return 0;
}