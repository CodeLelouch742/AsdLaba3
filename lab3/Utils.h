#include <iostream>
#include <chrono>
#include <Windows.h>
#include <cstdlib>

void showArr(float* arr, int length);

using namespace std;

void copy_arr(float* arr, float* bufArr,int length)
{
    for (int i = 0; i < length; i++)
    {
        bufArr[i] = arr[i];
    }
}

void exchange(float* element1, float* element2)
{
    float buf = *element1;
    *element1 = *element2;
    *element2 = buf;
}

/* Реализация сортировки вставками */
void insertionSort(float* arr, int length)
{
    int i, buf, j;
    for (i = 1; i < length; i++)
    {
        buf = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > buf)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = buf;
    }
}


/* Реализация сортировки выбором */
void selectionSort(float* arr, int length)
{
    int min;

    for (int i = 0; i < length - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < length; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            exchange(&arr[min],&arr[i]);
    }
}


/* Реализация сортировки пузырьком */
void bubbleSort(float* arr,int length)
{
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (length - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
                exchange(&arr[j],&arr[j + 1]);
        }
    }
}


/* Реализация сортировки слиянием */
void merge(float* arr, int l, int m, int r)//O(n)
{
    int i = 0, j = 0, k = l;
    int n1 = m - l + 1;
    int n2 = r - m;
    float* L = new float[n1]();
    float* R = new float[n2]();

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(float* arr, int l, int r)
{
    int m = l + (r - l) / 2;
    if (l < r)
    {
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


/* Реализация сортировки Шелла */
void shellSort(float* arr, int length)
{
    for (int i = length / 2; i > 0; i /= 2)
    {
        for (int j = i; j < length; j += 1)
        {
            float buf = arr[j];
            int k;
            for (k = j; k >= i && arr[k - i] > buf; k -= i)
                arr[k] = arr[k - i];
            arr[k] = buf;
        }
    }
}


/* Реализация быстрой сортировки */
int sectionExchange(float* arr, int low, int high)
{
    float buf = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < buf)
        {
            i++;
            exchange(&arr[i], &arr[j]);
        }
    }
    exchange(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(float* arr, int low, int high)
{
    if (low < high)
    {
        int buf = sectionExchange(arr, low, high);
        quickSort(arr, low, buf - 1);
        quickSort(arr, buf + 1, high);
    }
}