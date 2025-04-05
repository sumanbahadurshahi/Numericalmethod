#include <iostream>
#include <cmath>
using namespace std;

double comtrap(double b, double a, double n) {
    double h = (b - a) / n;
    double sum = (sin(a) + sin(b)); // First and last terms
    double sum1 = 0, sum2 = 0;

    if (n % 2 == 0) { // Checking if n is even
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                sum2 += 2 * sin(a + i * h); // Even terms get multiplied by 2
            } else {
                sum1 += 4 * sin(a + i * h); // Odd terms get multiplied by 4
            }
        }
    }

    double result = (sum + sum1 + sum2) * h / 3.0;
    return result;
}

int main() {
    double a, b;
    int n;
    double res;
    
    cout << "Enter the value a, b and n: " << endl;
    cin >> a >> b >> n;

    if (n % 2 != 0) {
        cout << "n must be even for Simpson's Rule." << endl;
        return 1; // Exit if n is not even
    }

    res = comtrap(b, a, n);
    cout << "The integration of trap is: " << res << endl;

    return 0;
}

