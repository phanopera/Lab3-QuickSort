#include "pch.h"
#include "../../quickSort/qs.h"
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
		mas[i] = rand() % size/100;
	}

	EXPECT_NO_THROW(sort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = size;
	}

	EXPECT_NO_THROW(sort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = size-i;
	}

	EXPECT_NO_THROW(sort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = rand() % size/100;
	}

	EXPECT_NO_THROW(quickSort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = size;
	}

	EXPECT_NO_THROW(quickSort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = size-i;
	}

	EXPECT_NO_THROW(quickSort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = rand() % size/100;
	}

	EXPECT_NO_THROW(insertionSort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = size;
	}

	EXPECT_NO_THROW(insertionSort(mas, 10000, [](int a, int b) { return a < b; }));
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
		mas[i] = size-i;
	}

	EXPECT_NO_THROW(insertionSort(mas, 10000, [](int a, int b) { return a < b; }));
	for (int i = 0; i < 10000 - 1; i++)
	{
		EXPECT_LE(mas[i], mas[i + 1]);
	}
}