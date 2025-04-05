#include <iostream>
#include <cmath>
using namespace std;

// Function to integrate: sin(x/2)
double f(double x) {
    return sin(x / 2);
}

// Composite Trapezoidal Rule
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    
    return sum * h;
}

// Romberg Integration for fixed set of integration 2,4,8 only but for other code is need for 2power n;
double romberg(double a, double b) {
    double I1 = trapezoidal_rule(a, b, 2);
    double I2 = trapezoidal_rule(a, b, 4);
    double I3 = trapezoidal_rule(a, b, 8);
    
    double I4 = I2 + (I2 - I1) / 3.0;
    double I5 = I3 + (I3 - I2) / 3.0;
    double I6 = I5 + (I5 - I4) / 3.0;
    
    return I6;
}

int main() {
    double a, b;
    cout << "Enter the values for a and b: ";
    cin >> a >> b;
    
    double result = romberg(a, b);
    cout << "Approximated integral using Romberg Integration: " << result << endl;
    
    return 0;
}

