#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
#include <ctime>
#include "my_qsort.h"

struct Student {
    std::string name;
    int age;
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Тест 1: числа
    int nums[] = {42, 7, 19, 73, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    my_qsort(nums, 0, n - 1, [](const int &a, const int &b) {
        return a < b;
    });
    for (int i = 1; i < n; ++i) assert(nums[i - 1] <= nums[i]);
    std::cout << "✅ Тест сортировки чисел пройден\n";

    // Тест 2: структуры
    Student students[] = {
        {"Иван", 22},
        {"Мария", 19},
        {"Петр", 25},
        {"Анна", 20}
    };
    int m = sizeof(students) / sizeof(students[0]);
    my_qsort(students, 0, m - 1, [](const Student &a, const Student &b) {
        return a.age < b.age;
    });
    for (int i = 1; i < m; ++i) assert(students[i - 1].age <= students[i].age);
    std::cout << " Тест сортировки студентов пройден\n";

    std::cout << " Все тесты успешно пройдены!\n";
    return 0;
}
