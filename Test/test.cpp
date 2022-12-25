#include "pch.h"
#include "../quickSort/qs.h"
#include <random>

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
//сверх быстрая мегасортиров очка
TEST(TestMegaSort, SortDifferent)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = rand() % 100;
	}

	EXPECT_NO_THROW(sort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
TEST(TestMegaSort, SortNotDifferent)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = 10000;
	}

	EXPECT_NO_THROW(sort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
TEST(TestMegaSort, SortSorted)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = 10000 - i;
	}

	EXPECT_NO_THROW(sort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
//быстрая
TEST(TestQuickSort, SortDifferent)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = rand() % 100;
	}

	EXPECT_NO_THROW(quickSort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
TEST(TestQuickSort, SortNotDifferent)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = 10000;
	}

	EXPECT_NO_THROW(quickSort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
TEST(TestQuickSort, SortSorted)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = 10000 - i;
	}

	EXPECT_NO_THROW(quickSort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
//вставками
TEST(TestInsSort, SortDifferent)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = rand() % 100;
	}

	EXPECT_NO_THROW(insertionSort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
TEST(TestInsSort, SortNotDifferent)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = 10000;
	}

	EXPECT_NO_THROW(insertionSort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
TEST(TestInsSort, SortSorted)
{
	srand(0);
	int mas[10000];

	for (int i = 0; i < 10000; i++)
	{
		mas[i] = 10000 - i;
	}

	EXPECT_NO_THROW(insertionSort(mas, mas, mas+10000-1, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}
