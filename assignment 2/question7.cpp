#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 4, 1, 5};
    int inversioncount = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - 1; j++)
        {
            if (arr[i] > arr[j + 1])
            {
                inversioncount++;
            }
        }
    }
    cout << "no of inversions are: " << inversioncount;
}