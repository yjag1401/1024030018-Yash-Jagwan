    // Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent
    // elements if they are in wrong order. Code the Bubble sort with the following elements:
    // 64 34 25 12 22 11 90

    #include <iostream>
    using namespace std;
    int main()
    {
        int arr[] = {64, 34, 25, 12, 22, 11, 90};
        int n = sizeof(arr) / sizeof(arr[0]);
        

        for (int i = 0; i < n - 1; i++)
        {
            bool swap = false;
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    bool swap = true;
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                if(swap = false){
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }