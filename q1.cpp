// Menu Driven Program -- Stacks

#include <iostream>
using namespace std;
#define MAX 50

bool isEmpty(int arr[], int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isFull(int arr[], int n)
{
    if (n == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}

void push(int arr[], int n)
{
    int ele;
    cout << "Enter element to push: ";
    cin >> ele;
    arr[n] = ele;
    n++;
    cout << "Modified array: (after pushing)";
    display(arr, n);
}

void pop(int arr[], int n)
{
    int last;
    last = arr[n - 1];
    cout << "popped element: " << last << endl;
    n--;
    cout << "Modified array: (after popping)" << endl;
    display(arr, n);
}

void peek(int arr[], int n)
{
    int last;
    last = arr[n - 1];
    cout << "Topmost element:  " << last;
}

int main()
{
    int len, A[MAX];
    cout << "Enter length";
    cin >> len;

    // input array
    for (int i = 0; i < len; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> A[i];
    }
    cout << "---- Menu Driven Program ----";
    cout << "1.  Push\n";
    cout << "2.  Pop\n";
    cout << "3.  isEmpty\n";
    cout << "4.  isFull\n";
    cout << "5.  Display\n";
    cout << "6.  Peek\n";
    cout << "0.  Quit\n";

    while (true)
    {
        int opt;
        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt)
        {
        case 1: // push
            push(A, len);
            cout << endl;
            break;

        case 2: // pop
            pop(A, len);
            cout << endl;
            break;

        case 3: // isEmpty
            cout << isEmpty(A, len);
            cout << endl;
            break;

        case 4: // isFull
            cout << isFull(A, len);
            cout << endl;
            break;

        case 5: // display
            display(A, len);
            cout << endl;
            break;

        case 6: // peek
            peek(A, len);
            cout << endl;
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid input... Enter Again";
            break;
        }
    }
}
