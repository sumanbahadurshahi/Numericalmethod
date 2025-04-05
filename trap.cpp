//write a program to calculate integration using trapezoidal rule.
#include <iostream>
#include <cmath>
using namespace std;
double trap(double b,double a){
    return (b-a)/2*(sin(a/2)+sin(b/2));
}
int main() {
    int a,b;
    double res;
    cout<<"Enter the value:"<<endl;
    cin>>a>>b;
    res=trap(-b,-a);
    cout<<"the integration of trap is:"<<res<<endl;
    

    return 0;
}
