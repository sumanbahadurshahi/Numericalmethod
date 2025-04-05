#include <iostream>
#include <iomanip>
#define h 0.25  // Step size

using namespace std;

// Function defining dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;
}

int main() {
    cout.precision(2);
    cout.setf(ios::fixed);

    double Xn, Yn;
    int S_No = 1;
    double a = 2;  // Final value of x

    cout << "Enter the initial values of x and y:" << endl;
    cin >> Xn >> Yn;

    cout << "S.No" << setw(10) << "Xn" << setw(10) << "Yn" << endl;
    cout << "______________________________________" << endl;

    do {
        cout << S_No << setw(10) << Xn << setw(10) << Yn << endl;

        // Predictor step (Euler's method)
        double Y_pred = Yn + h * f(Xn, Yn);

        // Corrector step (Average of slopes)
        double Y_corr = Yn + (h / 2) * (f(Xn, Yn) + f(Xn + h, Y_pred));

        // Update values
        Xn += h;
        Yn = Y_corr;
        S_No++;

    } while (Xn <= a);

    return 0;
}

