#include <bits/stdc++.h>
using namespace std;

class Euler {
public:
    double f(double x, double y) {
        return x * x + y;
    }

    void eulerM(double x0, double y0, double h, double n){
        double y = y0;
        double x=x0;

        for(int i=1; i<n; i++){
            y=y+h*f(x,y);
            x=x+h;

            cout<<"after step"<<i<<"x= "<<x<<"y= "<<y<<endl;
        }

    }
};


int main() {

    double x0, y0, h, n;
    cout<<"initial value of x0, y0, step size h, end x, n:"<<endl;
    cin>>x0>>y0>>h>>n;

    Euler euler;
    euler.eulerM(x0, y0, h, n);
    return 0;
}
