#include <iostream>
using namespace std;

int main() {
    int n = 3; // Number of equations
    float A[3][4]; // 3 equations, 3 variables + 1 column for constants
    float x[3]; // Solution array

    // Input Matrix
    cout << "Enter augmented matrix (coefficients + constants):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // Gaussian Elimination
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float c = A[j][i] / A[i][i];
            for (int k = 0; k <= n; k++) {
                A[j][k] -= c * A[i][k];
            }
        }
    }

    // Back Substitution
    x[2] = A[2][3] / A[2][2];
    x[1] = (A[1][3] - A[1][2] * x[2]) / A[1][1];
    x[0] = (A[0][3] - A[0][1] * x[1] - A[0][2] * x[2]) / A[0][0];

    // Output the solutions
    cout << "Solutions:\n";
    cout << "x = " << x[0] << "\n";
    cout << "y = " << x[1] << "\n";
    cout << "z = " << x[2] << "\n";

    return 0;
}

