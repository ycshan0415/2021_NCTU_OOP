#include<iostream>
#include <time.h>
using namespace std;

int data[1000] = {0};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A, int left, int right)
{
    int pivot = A[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[right]);
    return i + 1;//pivot = i + 1
}

void quickSort(int *A, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(A, left, right);
        quickSort(A, left, pivot - 1);
        quickSort(A, pivot + 1, right);
    }
}

int main()
{
    clock_t t;
	t = clock();

    int count;
    while(1)
    {
        cin >> count;

        if(count == 0)
            break;
        
        for (int i = 0; i < count; i++){
            cin >> data[i];
        }
        
        quickSort(data, 0, count - 1);
        
        for (int i = 0; i < count; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }

    t = clock() - t;
	cout << "Costs" << ((float)t) / CLOCKS_PER_SEC << "seconds" << endl;
    
    return 0;
}