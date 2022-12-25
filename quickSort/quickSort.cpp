#include <iostream>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "profileapi.h"
#include "Header.h"

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
                quickSort(mas, mas + size - 1, [](int a, int b) { return a > b; });
                quickSort(mas, mas + size - 1, [](int a, int b) { return a < b; });
            }
            QueryPerformanceCounter(&curr_ticks);
            fout << "quickSort, size: " << size << "; time: "
                << (double)((curr_ticks.QuadPart - init_ticks.QuadPart) * 1000000 / frequency.QuadPart) << std::endl;


            QueryPerformanceCounter(&init_ticks);
            //вставочки
            for (int j = 0; j < 10000; j++)
            {
                insertionSort(mas, mas + size - 1, [](int a, int b) { return a > b; });
                insertionSort(mas, mas + size - 1, [](int a, int b) { return a < b; });
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
    int size = 20;
    /* int a[30];
     addDigits(a, size);
     quickSort(a, a + size -1, [](int a, int b) { return a < b; });
     std::cout << "\n";
     showDigits(a, size);*/
    int a[20];

    addDigits(a, size);
    std::cout << "\n";
    sort(a, a + size - 1, [](int a, int b) { return a < b; });
    showDigits(a, size);

    getBenchTime();
}
