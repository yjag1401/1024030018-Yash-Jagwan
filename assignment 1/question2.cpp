#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    int temp[100];
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            temp[newSize] = arr[i];
            newSize++;
        }
    }

    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
    }

    n = newSize;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    display(arr, n);
    removeDuplicates(arr, n);
    display(arr, n);

    return 0;
}
