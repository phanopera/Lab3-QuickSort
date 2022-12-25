#include <iostream>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "profileapi.h"

const int optimisation = 16;
template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp) {
    if (first >= last) { return; }


    if (last - first > optimisation) {

        T* il = first;//0
        T* ir = last;//z
        T* mid = first + (last - first) / 2;//Центральный элемент массива
        if (comp(*first, *last)) { //first<last
            if (comp(*first, *mid)) { //first<mid
                if (comp(*last, *mid)) {
                    mid = last;//средний - ласт
                }
                //средний - мид
            }
            //средний - мид
        }
        else {//last<first
            if (comp(*first, *mid)) { //first<mid
                mid = first;//средний - ферст
            }
            else {
                if (comp(*mid, *last)) {
                    mid = last;//средний - ласт
                }
                //средний - ласт
            }
        }


        const T value = *mid;

        do {
            //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
            //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
            while (comp(*il, value)) {
                il++;
            }
            while (comp(value, *ir)) {
                ir--;
            }
            //Меняем элементы местами
            if (il <= ir) {

                std::swap(*il, *ir);

                il++;
                ir--;
            }
        } while (il <= ir);
        // выбор крайне правого элемент в качестве опорного элемента массива

        //Рекурсивные вызовы, если осталось, что сортировать
        while (first < last)
        {
            //"Левый кусок"
            if (ir - first > last - il)
            {
                quickSort(first, ir, comp);
                first = il;
            }
            else//"Прaвый кусок"
            {
                quickSort(il, last, comp);
                last = ir;
            }
        }
    }
    else {
        insertionSort(first, last, comp);
    }
}

//сортировка вставками https://www.techiedelight.com/ru/insertion-sort-iterative-recursive/
template<typename T, typename Compare>
void insertionSort(T* first, T* last, Compare comp) {
    if (first == last) { return; }
    for (T* i = first + 1; i <= last; i++) {
        T value = *i;        //массив 2й элемент
        T* j = i - 1;
        // найти индекс `j` в отсортированном подмножестве `T*[0…i-1]`, где находится элемент `T*[i]`
        while (j >= first && comp(value, *j))
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
    if (first >= last) { return; }
    T* il = first;//0
    T* ir = last;//z
    T* mid = first + (last - first) / 2;//Центральный элемент массива
    if (comp(*first, *last)) { //first<last
        if (comp(*first, *mid)) { //first<mid
            if (comp(*last, *mid)) {
                mid = last;//средний - ласт
            }
            //средний - мид
        }
        //средний - мид
    }
    else {//last<first
        if (comp(*first, *mid)) { //first<mid
            mid = first;//средний - ферст
        }
        else {
            if (comp(*mid, *last)) {
                mid = last;//средний - ласт
            }
            //средний - ласт
        }
    }


    const T value = *mid;

    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (comp(*il, value)) {
            il++;
        }
        while (comp(value, *ir)) {
            ir--;
        }
        //Меняем элементы местами
        if (il <= ir) {
            std::swap(*il, *ir);

            il++;
            ir--;
        }
    } while (il <= ir);
    // выбор крайне правого элемент в качестве опорного элемента массива

    //Рекурсивные вызовы, если осталось, что сортировать
    while (first < last)
    {
        //"Левый кусок"
        if (ir - first > last - il)
        {
            quickSort(first, ir, comp);
            first = il;
        }
        else//"Прaвый кусок"
        {
            quickSort(il, last, comp);
            last = ir;
        }
    }
}



void addDigits(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % size;
        std::cout << mas[i] << " ";
    }
}
void showDigits(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << " ";
    }
}


void getBenchTime() {
    LARGE_INTEGER frequency{ 0 }; // ticks per second
    LARGE_INTEGER init_ticks{ 0 };
    LARGE_INTEGER curr_ticks{ 0 };
    std::ofstream fout;
    fout.open("TimeOutput.txt", std::ios_base::trunc);
    if (!fout.is_open())
    {
        std::cout << "Ошибка при открытии файла!" << std::endl;
    }
    else
    {
        QueryPerformanceFrequency(&frequency);
        for (int size = 2; size <= 50; size++)
        {
            int* mas = new int[size];
            for (int i = 0; i < size; i++)
            {
                mas[i] = i;

            }
            QueryPerformanceCounter(&init_ticks);
            //соник-сортировка
            for (int j = 0; j < 10000; j++)
            {
                quickSort(mas, mas+ size-1, [](int a, int b) { return a > b; });
                quickSort(mas, mas+ size-1, [](int a, int b) { return a < b; });
            }
            QueryPerformanceCounter(&curr_ticks);
            fout << "quickSort, size: " << size << "; time: "
                << (double)((curr_ticks.QuadPart - init_ticks.QuadPart) * 1000000 / frequency.QuadPart) << std::endl;

           
            QueryPerformanceCounter(&init_ticks);
            //вставочки
            for (int j = 0; j < 10000; j++)
            {
                insertionSort(mas, mas + size-1, [](int a, int b) { return a > b; });
                insertionSort(mas, mas + size-1, [](int a, int b) { return a < b; });
            }
            QueryPerformanceCounter(&curr_ticks);
            fout << "insertSort, size: " << size << "; time: "
                << (double)((curr_ticks.QuadPart - init_ticks.QuadPart) * 1000000 / frequency.QuadPart) << std::endl;

            
            QueryPerformanceCounter(&init_ticks);
            //супер мега ультра нано сортировка
            for (int j = 0; j < 10000; j++)
            {
                quickSort(mas, mas + size - 1, [](int a, int b) { return a > b; });
                quickSort(mas, mas + size - 1, [](int a, int b) { return a < b; });
            }
            QueryPerformanceCounter(&curr_ticks);
            fout << "sort, size: " << size << "; time: "
                << (double)((curr_ticks.QuadPart - init_ticks.QuadPart) * 1000000 / frequency.QuadPart) << std::endl;

            delete[] mas;
        }
        fout.close();
    } 

}


int main()
{
    int size=9;
    /* int a[30];
     addDigits(a, size);
     quickSort(a, a + size -1, [](int a, int b) { return a < b; });
     std::cout << "\n";
     showDigits(a, size);*/
    int a[9];

    addDigits(a, size);
    std::cout << "\n";
    sort(a, a + size - 1, [](int a, int b) { return a < b; });
    showDigits(a, size);

    std::cout << "\n";

    std::cout << "\n";
    getBenchTime();
}
