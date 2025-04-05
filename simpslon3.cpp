#include <iostream>
#include <cmath>
using namespace std;

double simpson(double a, double b) {
    double h = (b - a) / 2.0; // Single interval (n=2)
    return (h / 3.0) * (sin(a) + 4 * sin((a + b) / 2) + sin(b)); // Simpson's Rule formula
}

int main() {
    double a, b, res;
    
    cout << "Enter the values of a and b: ";
    cin >> a >> b;
    
    res = simpson(a, b); // Using Simpson's Rule
    cout << "The integration using Simpson's Rule is: " << res << endl;

    return 0;
}

