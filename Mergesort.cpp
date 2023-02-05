#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
    int lenL = mid - left + 1;
	int lenR = right - mid;
	int L[lenL],R[lenR];

	for(int i = 0; i < lenL; i++)
		L[i] = A[left + i];
	
    for(int j = 0; j < lenR; j++)
		R[j] = A[mid + 1 + j];
	
    int idxLeft = 0, idxRight = 0, pos = left;

    while (idxLeft < lenL && idxRight < lenR)
    {
        if (L[idxLeft] <= R[idxRight] )
        {
            A[pos] = L[idxLeft];
            idxLeft++;
        }
        else
        {
            A[pos] = R[idxRight];
            idxRight++;
        }
        pos++;
    }
    while (idxLeft < lenL)
    { 
        A[pos] = L[idxLeft];
        idxLeft++;
        pos++;
    }
    while(idxRight < lenR)
    {
        A[pos] = R[idxRight];
        idxRight++;
        pos++;
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left < right)
    {                   
        int mid = (left + right)/2;         
        mergeSort(A, left, mid);    
        mergeSort(A, mid + 1, right);    
        merge(A, left, mid, right);   
    }
}

int main()
{
    clock_t t;
	t = clock();

    int n, i ,data[100] = {0};
    while(1)
    {
        cin >> n;

        if (n == 0)
            break;

        for (i = 0; i < n; i++)
            cin >> data[i];

        mergeSort(data, 0, n - 1);
        for (i = 0; i < n; i++)
            cout << data[i] << " ";

        cout << endl;
    }
   
    t = clock() - t;
	cout << "Costs" << ((float)t) / CLOCKS_PER_SEC << "seconds" << endl;
    
    return 0;
}