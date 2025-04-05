#include <iostream>
#include <iomanip>
#include <cmath>
#define h 0.2
using namespace std;

// Function representing the differential equation y'(x) = x^2 + y^2
double f(double x, double y) {
    return x * x + y * y;
}

int main() {
    cout.precision(4);  // Adjusted precision for more detailed output
    cout.setf(ios::fixed);  // Fixed point formatting for consistent decimal output
    
    double Xn = 0, Yn = 0;  // Initial values (x0 = 0, y0 = 0)
    double Xmax = 0.4;       // Maximum X value (we want to find y at x = 0.4)
    int S_No = 1;
    
    // Output Header
    cout << "S.No" << setw(10) << "Xn" << setw(15) << "Yn" << endl;
    cout << "_____________________________________________" << endl;
    
    // Iterating until we reach the desired value of x (Xmax = 0.4)
    while (Xn <= Xmax) {
        cout << S_No << setw(10) << Xn << setw(15) << Yn << endl;
        
        // Runge-Kutta 4th Order Method
        
        // Calculate m1, m2, m3, and m4
        double m1 = f(Xn, Yn);  // First slope
        double m2 = f(Xn + h / 2, Yn + m1 * h / 2);  // Second slope
        double m3 = f(Xn + h / 2, Yn + m2 * h / 2);  // Third slope
        double m4 = f(Xn + h, Yn + m3 * h);  // Fourth slope
        
        // Update Yn using the Runge-Kutta formula
        double Ynext = Yn + (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4);
        Yn = Ynext;  // Update Yn
        
        // Update Xn
        Xn += h;
        S_No++;
    }
    
    // Final output
    cout << "\nFinal value of y at x = " << Xn << " is: " << Yn << endl;
    
    return 0;
}

