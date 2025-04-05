#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter Order of Matrix: ";
    cin >> n;

    float a[n][n], x[n], y[n], k, prev_k = 0;

    cout << "Enter Coefficient Matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter Initial Guess Vector: \n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int step = 1;
    do {
        // Multiply matrix A with vector x
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            for (int j = 0; j < n; j++) {
                y[i] += a[i][j] * x[j];
            }
        }

        // Find maximum absolute value in y[] as eigenvalue
        k = fabs(y[0]);
        for (int i = 1; i < n; i++) {
            if (fabs(y[i]) > k) {
                k = fabs(y[i]);
            }
        }

        // Normalize y[] to obtain the next eigenvector approximation
        cout << "Eigen Vector (Step " << step << "): ";
        for (int i = 0; i < n; i++) {
            x[i] = y[i] / k;
            cout << x[i] << " ";
        }
        cout << "\nEigen Value Approximation: " << k << "\n";

        // Check for convergence with a precision of 3 decimal places
        if (fabs(k - prev_k) < 0.001) {
            break;
        }

        prev_k = k;
        step++;
    } while (true);

    return 0;
}

