#include<bits/stdc++.h>
using namespace std;

class Simpson{
    public:
    double f(double x){
        return x*x*x-2*x-5;
    }

    void simpson(double a, double b, double n){
        double h=(b-a)/n;
        double sum = (f(a)+f(b));

        for(int i=1; i<n; i++){
            double x = a+i *h;

            if(i%2==0){
                sum=sum+f(x)*2;
            }
            else{
                sum=sum+f(x)*4;
            }
        }
       cout<<"results= "<<(sum*h)/3<<endl;

    }
};

int main(){

    double a, b, n;
    cin>>a>>b>>n;

    Simpson simp;

    simp.simpson(a, b, n);

    return 0;
}

