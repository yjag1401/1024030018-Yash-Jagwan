#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find;

    cout << "Enter element to search: ";
    cin >> find;

    int low = 0, high = n - 1, result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == find)
        {
            result = mid; 
            break;
        }
        else if (arr[mid] < find)
        {
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

