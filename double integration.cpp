#include <iostream>

using namespace std;

// Define the function to be integrated
double f(double x, double y) {
    return x * x + y * y; // Example function: f(x, y) = x^2 + y^2
}

// Function to evaluate double integral using Trapezoidal Rule
double trapezoidalDoubleIntegration(double a, double b, double c, double d, int nx, int ny) {
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;
    double sum = 0.0;
    
    for (int i = 0; i <= nx; i++) {
        double x = a + i * hx;
        for (int j = 0; j <= ny; j++) {
            double y = c + j * hy;
            double coefficient = 1.0;
if (i == 0 || i == nx) coefficient *= 0.5;  // Half weight for x-boundary points
if (j == 0 || j == ny) coefficient *= 0.5;  // Half weight for y-boundary points

            sum += coefficient * f(x, y);
        }
    }
    
    return sum * hx * hy;
}

int main() {
    double a = 0, b = 1; // Limits for x
    double c = 0, d = 1; // Limits for y
    int nx = 10, ny = 10; // Number of intervals in x and y directions

    double result = trapezoidalDoubleIntegration(a, b, c, d, nx, ny);
    cout << "The approximate value of the double integral is: " << result << endl;

    return 0;
}

