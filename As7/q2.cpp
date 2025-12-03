#include <bits/stdc++.h>
using namespace std;

void selectionSortImp(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        int minIndex = i;
        int maxIndex = i;

        for (int j = i + 1; j < n - i; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        swap(arr[i], arr[minIndex]);
        if (maxIndex == i)
            maxIndex = minIndex;
        swap(arr[n - i - 1], arr[maxIndex]);
    }
}