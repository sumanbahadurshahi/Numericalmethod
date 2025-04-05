#include <iostream>
#include <iomanip>
#include <cmath>
#define h 0.25
using namespace std;

double f(double x, double y) {
    return x +  2*y;
}

int main() {
    cout.precision(2);
    cout.setf(ios::fixed);
    
    double Xn, Yn;
    int S_No = 1;
    double a = 2;
    
    cout << "Enter the initial values of x and y:" << endl;
    cin >> Xn >> Yn;
    
    cout << "S.No" << setw(10) << "Xn" << setw(10) << "Yn" << endl;
    cout << "______________________________________" << endl;
    
    do {
        cout << S_No << setw(10) << Xn << setw(10) << Yn << endl;
       
      double y_n = Yn + h * f(Xn, Yn); // Updating Yn in every iteration
        Xn += h;
         Yn=y_n;
        S_No++;
    } while (Xn <= a);
    
    return 0;
}

