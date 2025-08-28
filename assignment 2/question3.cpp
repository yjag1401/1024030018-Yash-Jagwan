#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int missing = -1;

    int diff = arr[0] - 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            missing = i + diff;
            break;
        }
    }

    if (missing != -1)
        cout << "Missing number is: " << missing << endl;
    else
        cout << "No missing number" << endl;

    return 0;
}
