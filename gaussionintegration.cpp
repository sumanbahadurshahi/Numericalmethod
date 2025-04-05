#include <iostream>
#include <cmath>

// Function to integrate
double f(double x) {
    return x * x;  // Example: f(x) = x^2
}

// Gauss-Legendre Quadrature (2-point method)
double gauss_legendre_2point(double a, double b) {
    // Gauss-Legendre nodes and weights for n=2
    double x1 = -1.0 / sqrt(3.0);
    double x2 =  1.0 / sqrt(3.0);
    double w1 = 1.0, w2 = 1.0;  // Weights

    // Transforming nodes from [-1,1] to [a,b]
    double x1_mapped = 0.5 * (b - a) * x1 + 0.5 * (b + a);
    double x2_mapped = 0.5 * (b - a) * x2 + 0.5 * (b + a);

    // Compute integral approximation
    double integral = 0.5 * (b - a) * (w1 * f(x1_mapped) + w2 * f(x2_mapped));

    return integral;
}

int main() {
    double a = 0, b = 1;  // Integration limits
    double result = gauss_legendre_2point(a, b);
    std::cout << "Approximate integral: " << result << std::endl;
    return 0;
}

