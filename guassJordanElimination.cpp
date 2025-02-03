#include <iostream>
using namespace std;

void gaussJordanElimination(float mat[10][11], int n) {
    for (int i = 0; i < n; i++) {
        // Make the diagonal element 1 and adjust the rest of the row
        float diag = mat[i][i];
        for (int j = 0; j <= n; j++) {
            mat[i][j] /= diag;
        }

        // Make all elements in current column 0 except for the pivot
        for (int j = 0; j < n; j++) {
            if (i != j) {
                float ratio = mat[j][i];
                for (int k = 0; k <= n; k++) {
                    mat[j][k] -= ratio * mat[i][k];
                }
            }
        }
    }

    cout << "The solution is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << mat[i][n] << endl;
    }
}

int main() {
    float mat[10][11];
    int n;

    cout << "Enter the number of variables: ";
    cin >> n;

    cout << "Enter the augmented matrix coefficients row-wise:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    gaussJordanElimination(mat, n);

    return 0;
}
