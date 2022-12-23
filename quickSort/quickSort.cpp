// quickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp) {}

/*template<typename T>
bool comp(const T& a, const T& b) {
    if (a < b) { return true; }
    else { return false; }
}*/

//сортировка вставками https://www.techiedelight.com/ru/insertion-sort-iterative-recursive/
template<typename T, typename Compare>
void insertionSort(T* first, T* last, Compare comp) {
    if (first == last) { return; }
    for (T* i = first+1; i <= last; i++) {
        T value = *i;        //массив 2й элемент
        T* j = i-1;
        // найти индекс `j` в отсортированном подмножестве `T*[0…i-1]`, где находится элемент `T*[i]`
        while (j >= first && comp(value,*j))
        {
            *(j + 1) = std::move(*j);
            j--;
        }
        // подмассив `T*[j…i-1]` сдвинут на вправо на одну позицию, т.е. `T*[j+1…i]`
        *(j + 1) = value;
    }
}

//быстрая сортировка https://www.techiedelight.com/ru/quicksort/
template<typename T, typename Compare>
void quickSort(T* first, T* last, Compare comp) {

    while (last > first) {
        T* il = first;//0
        T* ir = last;//z
        //T* mid = first + (last - first) / 2;

        T* value = first;
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (true) {
            while (comp(*il, *value)) {
                il++; 
            }
            while (comp(*value, *ir)) {
                ir--; 
            }

            if (il >= ir) {
                break;
            }
            std::swap(*(il++), *(ir--));            //Меняем элементы местами
        }

        std::swap(*ir, *value);            //Меняем элементы местами
        //Рекурсивные вызовы, если осталось, что сортировать
        if (ir - first > last - ir) {
            quick_sort(ir + 1, last, comp);
            last = ir - 1;
        }
        else {
            quick_sort(first, ir - 1, comp);
            first = ir + 1;
        }
    }
}


void addDigits(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        int value = rand() % size;
        mas[i] = value;
        std::cout << mas[i]<<" ";
    }
}

int main()
{
    int a[20];
    addDigits(a,20);
    //insertionSort(a, a + 9, [](int a, int b) { return a < b; });
   // quickSort(a, a + 19, [](int a, int b) { return a < b; });
    quick_sort(a, a + 19, [](int a, int b) { return a < b; });
    std::cout << "\n";
   for (int i = 0; i < 20; i++) {
        std::cout << a[i] << " ";
    }
    //int a[100];
    //sort(a, a + 100, [](int a, int b) { return a < b; });
   // std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
