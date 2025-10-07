#include <iostream>
#include <string>
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
    // 🎲 Выбираем случайный индекс pivot между low и high
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

struct Student {
    std::string name;
    int age;
};

int main() {
    // Инициализируем генератор случайных чисел
    srand(static_cast<unsigned>(time(nullptr)));

    // Пример 1: сортировка чисел
    int nums[] = {42, 7, 19, 73, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    my_qsort(nums, 0, n - 1, [](const int &a, const int &b) {
        return a < b;  // сортировка по возрастанию
    });

    std::cout << "Сортировка чисел: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";

    // Пример 2: сортировка структур
    Student students[] = {
        {"Иван", 22},
        {"Мария", 19},
        {"Петр", 25},
        {"Анна", 20}
    };
    int m = sizeof(students) / sizeof(students[0]);

    my_qsort(students, 0, m - 1, [](const Student &a, const Student &b) {
        return a.age < b.age;  // сортировка по возрасту
    });

    std::cout << "Сортировка студентов по возрасту:\n";
    for (auto &s : students)
        std::cout << s.name << " (" << s.age << ")\n";

    return 0;
} 
