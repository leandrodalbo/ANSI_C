#include <stdio.h>

void sort(int list[], int firstIndex, int lastIndex);
void swap(int *a, int *b, int *pivote);
void swap2(int *a, int *b);

int main()
{

    int numbers[] = {34, 12, 5, 66, 88, 33, 21, 32, 32, 22, 19, 35};

    sort(numbers, 0, 11);

    for (int i = 0; i < 12; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}

void sort(int list[], int firstIndex, int lastIndex)
{
    if (firstIndex < lastIndex)
    {
        int pivot = list[lastIndex];

        int i = firstIndex;
        int pivotIndex = lastIndex;

        while (i < pivotIndex && pivotIndex > 1)
        {

            if (list[i] > pivot)
            {
                swap(&list[i], &list[pivotIndex - 1], &list[pivotIndex]);
                pivotIndex--;
                continue;
            }

            i++;
        }

        if (pivotIndex == 1 && list[0] > list[pivotIndex])
        {
            swap2(&list[0], &list[pivotIndex]);
        }

        sort(list, firstIndex, pivotIndex - 1);
        sort(list, pivotIndex + 1, lastIndex);
    }
}

void swap(int *a, int *b, int *pivote)
{
    int t = *a;
    *a = *b;
    *b = *pivote;
    *pivote = t;
}

void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}