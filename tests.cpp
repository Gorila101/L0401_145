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

void test_int_sort() {
    int arr[] = {42, 7, 19, 73, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    my_qsort(arr, 0, n - 1, [](const int &a, const int &b) {
        return a < b;
    });

    for (int i = 1; i < n; i++)
        assert(arr[i - 1] <= arr[i]);

    std::cout << " test_int_sort passed.\n";
}

void test_struct_sort() {
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

    for (int i = 1; i < m; i++)
        assert(students[i - 1].age <= students[i].age);

    std::cout << "✅ test_struct_sort passed.\n";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    test_int_sort();
    test_struct_sort();

    std::cout << " Все тесты успешно пройдены!\n";
    return 0;
}
