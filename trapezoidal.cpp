#include<bits/stdc++.h>
using namespace std;

class Trapizoidal{
    public:
    double f(double x){
        return x*x*x-2*x-5;
    }

    void trapi(double a, double b, double n){
        double h=(b-a)/n;
        double sum = (f(a)+f(b))*0.5;

        for(int i=1; i<n; i++){
            sum = sum+ f(a+i *h);
        }
       cout<<"results= "<<sum*h<<endl;

    }
};

int main(){

    double a, b, n;
    cin>>a>>b>>n;

    Trapizoidal trapiz;

    trapiz.trapi(a, b, n);

    return 0;
}
