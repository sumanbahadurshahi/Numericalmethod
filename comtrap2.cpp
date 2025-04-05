//Write a program to calculate integration using composite Trapezoidal rule
//kati tukra pareraa jodhna milxa

#include <iostream>
#include <cmath>
using namespace std;
double comtrap(double b,double a ,double n){
double h=(b-a)/n;
double sum=(sin(a/2)+sin(b/2));
for(int i=0;1<n;i++){
    sum+=2*sin((a/2)+i*h);
}
return sum*h/2.0;
}
int main() {
    int a,b,n;
    double res;
    cout<<"Enter the value a,b and n:"<<endl;
    cin>>a>>b>>n;
    res=comtrap(b,a,n);
    cout<<"the integration of trap is:"<<res<<endl;
    

    return 0;
}
