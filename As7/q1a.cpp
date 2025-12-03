// a) Selection sort

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {12, 10, 22, 29, 25};
    int n = 5;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; 

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}