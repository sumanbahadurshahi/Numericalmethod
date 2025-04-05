#include <iostream>
#include <cmath>
using namespace std;

double function(double x) {
    return sin(x); // Example function, modify as needed
}

double simpson_38(double a, double b, int n) {
    if (n % 3 != 0) {
        cout << "Error: n must be a multiple of 3 for Simpson's 3/8 Rule." << endl;
        return 0;
    }

    double h = (b - a) / n;
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * function(x); // Coefficient 2 for multiples of 3
        else
            sum += 3 * function(x); // Coefficient 3 for other terms
    }

    return (3 * h / 8) * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter the values of a, b and n (must be a multiple of 3): ";
    cin >> a >> b >> n;

    if (n % 3 != 0) {
        cout << "Error: n must be a multiple of 3." << endl;
        return 1;
    }

    double result = simpson_38(a, b, n);
    cout << "The integration using Simpson's 3/8 Rule is: " << result << endl;

    return 0;
}

