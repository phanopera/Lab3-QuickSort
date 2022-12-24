// quickSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
const int optimisation=16;
template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp) {
    while (first < last) {
        if (last - first < optimisation) {
            insertionSort(first, last, comp);
            return;
        }

        T* mid = first + (last - first) / 2;
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

        if (mid - first < last - mid) {
            quickSort(first, mid, comp);
            first = mid + 1;
        }
        else
        {
            quickSort(mid + 1, last, comp);
            last = mid;
        }
    }


}

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
        if (first == last) { return; }
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
            while (*il < value) {
                il++;
            }
            while (*ir > value) {
                ir--;
            }
            //Меняем элементы местами
            if (il <= ir) {
                if (*il > *ir) { std::swap(*il, *ir); }

                il++;
                ir--;
            }
        } while (il <= ir);
        // выбор крайне правого элемент в качестве опорного элемента массива

        //Рекурсивные вызовы, если осталось, что сортировать
        if (ir > first) {
            //"Левый кусок"
            quickSort(first, ir, comp);
        }
        if (il < last) {
            //"Прaвый кусок"
            quickSort(il, last, comp);
        }
}


void addDigits(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % size;
        std::cout << mas[i]<<" ";
    }
}
void showDigits(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << " ";
    }
}

int main()
{
   /* int size=50;
    int a[50];
    addDigits(a, size);
    quickSort(a, a + size -1, [](int a, int b) { return a < b; });
    std::cout << "\n";
    showDigits(a, size);*/
    int a[100];
    sort(a, a + 100, [](int a, int b) { return a < b; });
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
