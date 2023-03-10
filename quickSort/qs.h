#pragma once
#include <iostream>
const int optimisation = 11;
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
