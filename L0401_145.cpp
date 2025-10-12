#include <iostream>
#include <string>
<<<<<<< HEAD:L0401_145.cpp.txt
#include <cstdlib>
#include <ctime>
#include "my_qsort.h"
=======
#include <cstdlib>   // для rand()
#include <ctime>     // для srand()

// Универсальная функция swap
template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Функция partition с рандомным pivot
template<typename T, typename Compare>
int partition(T arr[], int low, int high, Compare compare) {
    // Выбираем случайный индекс pivot между low и high
    int randomIndex = low + rand() % (high - low + 1);
    
    // Меняем выбранный элемент с последним, чтобы использовать arr[high] как pivot
    swap(arr[randomIndex], arr[high]);

    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Рекурсивная функция QuickSort
template<typename T, typename Compare>
void my_qsort(T arr[], int low, int high, Compare compare) {
    if (low < high) {
        int pi = partition(arr, low, high, compare);
        my_qsort(arr, low, pi - 1, compare);
        my_qsort(arr, pi + 1, high, compare);
    }
}
>>>>>>> a85ed9fe5a5dddd5320d903ffc06ba4264ab8dcb:L0401_145.cpp

struct Student {
    std::string name;
    int age;
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int nums[] = {42, 7, 19, 73, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    my_qsort(nums, 0, n - 1, [](const int &a, const int &b) {
        return a < b;
    });

    std::cout << "Сортировка чисел: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

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

    std::cout << "Сортировка студентов по возрасту:\n";
    for (auto &s : students)
        std::cout << s.name << " (" << s.age << ")\n";

    return 0;
<<<<<<< HEAD:L0401_145.cpp.txt
}
=======
} 
>>>>>>> a85ed9fe5a5dddd5320d903ffc06ba4264ab8dcb:L0401_145.cpp
