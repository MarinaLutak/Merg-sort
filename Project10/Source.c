#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include < stdlib.h >
#include < string.h >
#include <Windows.h>

void Merg(int arr[], int begin, int end)
{
    int i = begin, t = 0, mid = begin + (end - begin) / 2, j = mid + 1, d[100];

    while (i <= mid && j <= end)
    {

        if (arr[i] <= arr[j]) {
            d[t] = arr[i]; i++;
        }
        else {
            d[t] = arr[j]; j++;
        }
        t++;
    }

    while (i <= mid)
    {
        d[t] = arr[i]; i++; t++;
    }

    while (j <= end)
    {
        d[t] = arr[j]; j++; t++;
    }

    for (i = 0; i < t; i++)
        arr[begin + i] = d[i];
}

void MergSort(int arr[8], int left, int right)
{
    int  tmp;
    if (left < right)
        if (right - left == 1) {
            if (arr[right] < arr[left]) {
                tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
            }
        }
        else {
            MergSort(arr, left, left + (right - left) / 2);
            MergSort(arr, left + (right - left) / 2 + 1, right);
            Merg(arr, left, right);
        }
}

void main()
{

    system("chcp 1251");
    system("cls");
    int n = 8, a[] = { 8,3,2,9,7,1,5,4 };

    printf("Вхідний масив:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    MergSort(a, 0, n - 1);
    printf("\nВідсортований масив:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    system("pause");

}