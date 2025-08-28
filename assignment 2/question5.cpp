#include <iostream>
using namespace std;

int main() {
    int choice, n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    cout << "\nChoose Matrix Type:\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Tri-diagonal Matrix\n";
    cout << "3. Lower Triangular Matrix\n";
    cout << "4. Upper Triangular Matrix\n";
    cout << "5. Symmetric Matrix\n";
    cin >> choice;

    if (choice == 1) {
        int A[n]; 
        cout << "Enter diagonal elements:\n";
        for (int i = 0; i < n; i++) cin >> A[i];

        cout << "Diagonal Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 2) {
        int A[3*n - 2];
        cout << "Enter " << 3*n-2 << " elements (lower, main, upper):\n";
        for (int i = 0; i < 3*n-2; i++) cin >> A[i];

        cout << "Tri-diagonal Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << A[n-1+i] << " ";
                else if (i == j+1) cout << A[i-1] << " ";
                else if (i+1 == j) cout << A[2*n-1+i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 3) {
        int size = n*(n+1)/2;
        int A[size];
        cout << "Enter " << size << " elements (row-wise):\n";
        for (int i = 0; i < size; i++) cin >> A[i];

        cout << "Lower Triangular Matrix:\n";
        int k = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) cout << A[k++] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 4) {
        int size = n*(n+1)/2;
        int A[size];
        cout << "Enter " << size << " elements (row-wise):\n";
        for (int i = 0; i < size; i++) cin >> A[i];

        cout << "Upper Triangular Matrix:\n";
        int k = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i <= j) cout << A[k++] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    else if (choice == 5) {
        int size = n*(n+1)/2;
        int A[size];
        cout << "Enter " << size << " elements (lower triangle row-wise):\n";
        for (int i = 0; i < size; i++) cin >> A[i];

        cout << "Symmetric Matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i >= j) cout << A[(i*(i-1))/2 + (j-1)] << " ";
                else cout << A[(j*(j-1))/2 + (i-1)] << " "; 
            }
            cout << endl;
        }
    }

    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
