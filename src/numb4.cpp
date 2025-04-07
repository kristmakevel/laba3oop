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
    std::cout << "adding not in a block \n";
    //создаем новые использования и смотрим на счетчик
    auto sec_one = first_one;
    std::cout << first_one.use_count() << "\n";
    //собственно вне блока все сохраняется прекрасно
    {
        std::cout << "and now adding in a block \n";
        auto third_one = first_one;
        std::cout << first_one.use_count() << "\n";
    }
    //все что было сделано внутри блока остается внутри блока
    std::cout << "and now not in a block again \n";
    std::cout << first_one.use_count() << "\n";
    std::weak_ptr<archive> weak_arch = first_one;
    std::cout << "not in a block \n" << first_one.use_count() << "\n";
    if (auto weakest_arch = weak_arch.lock()) {
        std::cout << "count with weak_ptr:  " << weakest_arch.use_count() << "\n";
    }
    else {
        std::cout << "weak_ptr deleted :(\n";
    }

    std::cout << "not in a block: " << first_one.use_count() << "\n";

    return 0;
}