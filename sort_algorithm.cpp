#include <bits/stdc++.h>
using namespace std;
int ary[11], tmp;
int n = sizeof(ary) / sizeof(*ary);

void init()
{
    ary[0] = 10;
    ary[1] = 1;
    ary[2] = 9;
    ary[3] = 2;
    ary[4] = 8;
    ary[5] = 3;
    ary[6] = 7;
    ary[7] = 4;
    ary[8] = 11;
    ary[9] = 5;
    ary[10] = 6;
}
void printAry()
{
    for (int i = 0; i < n; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;
}
void bubsort(int ary[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ary[j] > ary[j + 1])
            {
                tmp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ary[i] << " ";
    }
    cout << endl;
}

void selectSort(int ary[], int n)
{
    int mi = INT_MIN;
    int miIdx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        mi = ary[i];
        miIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ary[j] < mi)
            {
                mi = ary[j];
                miIdx = j;
            }
        }
        if (miIdx != i)
        {
            ary[miIdx] = ary[i];
            ary[i] = mi;
        }
    }
}
void insertSort(int ary[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j;
        tmp = ary[i];
        for (j = i - 1; j >= 0 && ary[j] > tmp; j--)
        {
            ary[j + 1] = ary[j];
        }
        ary[j + 1] = tmp;
    }
}

void merge(int ary[], int begin, int mid, int end)
{
    int *tmpary = new int[end - begin + 1];
    int tmpIdx = 0;
    int i1 = begin, i2 = mid + 1;
    while (i1 <= mid && i2 <= end)
    {
        if (ary[i1] <= ary[i2])
        {
            tmpary[tmpIdx++] = ary[i1++];
        }
        else
        {
            tmpary[tmpIdx++] = ary[i2++];
        }
    }
    while (i1 <= mid)
    {
        tmpary[tmpIdx++] = ary[i1++];
    }
    while (i2 <= end)
    {
        tmpary[tmpIdx++] = ary[i2++];
    }
    int k = 0;
    while (begin <= end)
    {
        ary[begin++] = tmpary[k++];
    }
    delete[] tmpary;
}

void mergeSort(int ary[], int begin, int end)
{
    if (end > begin)
    {
        int mid = (begin + end) / 2;
        mergeSort(ary, begin, mid);
        mergeSort(ary, mid + 1, end);
        merge(ary, begin, mid, end);
    }
}

void quickSort(int ary[], int begin, int end)
{
    if (begin >= end)
        return;
    int prinum = ary[begin];
    int i = begin, j = end;
    while (i < j)
    {
        while (ary[j] >= prinum && i < j)
            j--;
        while (ary[i] <= prinum && i < j)
            i++;
        swap(ary[i], ary[j]);
    }
    cout << "i:" << i << " j:" << j << endl;
    swap(ary[begin], ary[i]);
    quickSort(ary, begin, i - 1);
    quickSort(ary, j + 1, end);
}
int main()
{
    init();
    bubsort(ary, n);
    printAry();
    init();
    selectSort(ary, n);
    printAry();
    init();
    insertSort(ary, n);
    printAry();
    init();
    mergeSort(ary, 0, n - 1);
    printAry();
    init();
    quickSort(ary, 0, n - 1);
    printAry();
}