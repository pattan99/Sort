#include "SortAlgorithm.h"

vector<double> VectorSort;

/// QuickSort
void QSort(int low, int high)
{
	if (low <= high)
	{
		double pivot = VectorSort[low + ((high - low) >> 1)];

		int i = low;
		int j = high;

		while (i <= j)
		{
			while (VectorSort[i] < pivot)
				i++;
			while (VectorSort[j] > pivot)
				j--;

			if (i <= j)
			{
				swap(VectorSort[i], VectorSort[j]);
				i++;
				j--;
			}
		}

		if (low < j)
			QSort(low, j);
		if (high > i)
			QSort(i, high);
	}
}

/// MergeSort
void Merge(int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 =  high - mid;

    vector<double> L, R;

    for (i=0; i<n1; ++i)
        L.push_back(VectorSort[low + i]);
    for (j=0; j<n2; ++j)
        R.push_back(VectorSort[mid + 1 + j]);

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            VectorSort[k] = L[i];
            i++;
        }
        else
        {
            VectorSort[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        VectorSort[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        VectorSort[k] = R[j];
        j++;
        k++;
    }
}

void MSort(int low, int high)
{
    if (low < high)
    {
        int mid = low + ((high-low) >> 1);

        MSort(low, mid);
        MSort(mid+1, high);

        Merge(low, mid, high);
    }
}

/// HeapSort
void Heapify(int i, int n)
{
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && VectorSort[l] > VectorSort[mx])
        mx = l;
    if (r < n && VectorSort[r] > VectorSort[mx])
        mx = r;
    if (mx != i)
    {
        swap(VectorSort[i], VectorSort[mx]);
        Heapify(mx, n);
    }
}

void HSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(i, n);
    for (int i = n - 1; i >= 1; --i)
    {
        swap(VectorSort[0], VectorSort[i]);
        Heapify(0, i);
    }
}
