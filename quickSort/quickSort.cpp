#include <iostream>
const int optimisation = 16;
template<typename T, typename Compare>
void sort(T* first, T* last, Compare comp) {
            if (first == last) { return; }

           
            while(last - first > optimisation) {

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
                    sort(first, ir, comp);
                }
                if (il < last) {
                    //"Прaвый кусок"
                    sort(il, last, comp);
                }
            }
            insertionSort(first, last, comp);
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

/*//быстрая сортировка https://www.techiedelight.com/ru/quicksort/
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
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (*il < *mid) {
            il++;
        }
        while (*ir > *mid) {
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
   /* if (ir > first) {
        //"Левый кусок"
        quickSort(first, ir + 1, comp);
    }
    if (il < last) {
        //"Прaвый кусок"
        quickSort(first, last, comp);
    }*

    if (last - ir > ir - il)
    {
        quickSort(il, j, comp);
        il = j + 1;
    }
    else
    {
        quickSort(j + 1, ir, comp);
        ir = j;
    }
}*/
/*template<typename T, typename Compare>
inline void quickSort(T* first, T* last, Compare comp)
{
    if (!first || !last) throw std::exception("Nullptr in args!");

    T* il = first;
    T* ir = last;

    while(il < ir)
    {

        //Finding median
        T* mid = il + (ir - il) / 2;
        if (comp(*mid, *il)) std::swap(*mid, *il);
        if (comp(*ir, *il)) std::swap(*ir, *il);
        if (comp(*ir, *mid)) std::swap(*ir, *mid);

        //Partition
       // const T mid = *mid;
        T* i = il;
        T* j = ir;

        while(true)
        {
            while(comp(*i, *mid)) i++;
            while(comp(*mid, *j)) j--;
            if (i >= j) break;
            std::swap(*i, *j);
            i++;
            j--;
        }

        if (ir - j > j - il)
        {
            quickSort(il, j, comp);
            il = j + 1;
        }
        else
        {
            quickSort(j + 1, ir, comp);
            ir = j;
        }
    }
}*/


/*РАБОЧИЙ РАБОЧИЙ РАБОЧИЙ
template<typename T, typename Compare>
inline void quickSort(T* first, T* last, Compare comp)
{
if (!first || !last) throw std::exception("Nullptr in args!");

T* il = first;
T* ir = last;

while (il < ir)
{
    /*if (useInsertion && ir - il <= 64)
    {
        insertions(il, ir, comp);
        return;
    }*/

    //Finding median
   // T* mid = il + (ir - il) / 2;
   /* if (comp(*mid, *il)) std::swap(*mid, *il);
    if (comp(*ir, *il)) std::swap(*ir, *il);
    if (comp(*ir, *mid)) std::swap(*ir, *mid);*

    //Partition
    const T value = *mid;
    T* i = il;
    T* j = ir;

    while (true)
    {
        while (comp(*i, value)) i++;
        while (comp(value, *j)) j--;
        if (i >= j) break;
        std::swap(*i, *j);
        i++;
        j--;
    }

    if (ir - j > j - il)
    {
        quickSort(il, j, comp);
        il = j + 1;
    }
    else
    {
        quickSort(j + 1, ir, comp);
        ir = j;
    }
}}*/

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
        std::cout << mas[i] << " ";
    }
}
void showDigits(int* mas, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << mas[i] << " ";
    }
}

int main()
{
    int size=10;
    /* int a[30];
     addDigits(a, size);
     quickSort(a, a + size -1, [](int a, int b) { return a < b; });
     std::cout << "\n";
     showDigits(a, size);*/
    int a[10];

    addDigits(a, size);
    std::cout << "\n";
    sort(a, a + size - 1, [](int a, int b) { return a < b; });
    showDigits(a, size);
}
