#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double f(double x);
double f(double x){
    double a = x * x - 4.0;
    return a;
}

int main(){
    cout.precision(5);
    cout.setf(ios::fixed);
    double a, b, c, e, fa, fb, fc;
    
a:
    cout << "Enter the initial guesses:\n a=";
    cin >> a;
    cout << "\n b=";
    cin >> b;
    cout << "\n Enter the desired accuracy: ";
    cin >> e;
    
    int iter = 0;
    
    // Check if the initial guesses have opposite signs
    if (f(a) * f(b) > 0) {
        cout << "Please return different numbers where the function changes signs." << endl;
        goto a;
    }
    else {
        // Corrected the missing semicolon
        cout << "iter" << setw(14) << "a" << setw(18) << "b" << setw(18) << "c" << setw(18) << "f(c)" << setw(18) << "|a-b|" << endl;
        
        // Corrected the missing '<<' for the separator line
        cout << "--------------------------------------------------------------------------------------------" << endl;
        
        while (fabs(a - b) >= e) {  // while the difference between a and b is greater than the accuracy e
            c = (a + b) / 2.0;
            fa = f(a);
            fb = f(b);
            fc = f(c);
            iter++;
            
            // Printing the values of the iteration
            cout << setw(4) << iter << setw(14) << a << setw(18) << b << setw(18) << c << setw(18) << fc << setw(18) << fabs(a - b) << endl;
            
            if (fabs(fc) < e) {  // If fc is close enough to 0
                cout << "The root of the equation is " << c << endl;
                return 0;
            }
            if (fa * fc > 0) {
                a = c;  // Update a
            }
            else {
                b = c;  // Update b
            }
        }
    }
    
    cout << "The root of the equation is " << c << endl;
    return 0;
}

