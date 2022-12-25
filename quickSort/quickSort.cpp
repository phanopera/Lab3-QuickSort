#include "qs.h"

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
}
