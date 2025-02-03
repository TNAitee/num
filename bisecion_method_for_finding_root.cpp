#include<bits/stdc++.h>
using namespace std;

#define ub 10
#define lb -10
#define e 2.718

class Bisection{
    public:

        double f(double x){
        return x*x*x - 2*x - 5;
        //return x* pow(e,x) - 1;
        }

        void bisection(double a, double b, double tolerance, int maxIterations){
            if(f(a)*f(b) >= 0){
                cout<<"Wrong assumption of a and b"<<endl;
                return;
        }

        double c = a;
        for(int i = 1; i <= maxIterations; i++){
            c = (a+b)/2;

            cout<<i<<"    a="<<a<<"   b="<<b<<"   c="<<c<<"   f(a)="<<f(a)<<"   f(b)="<<f(b)<<endl;

            if(fabs(f(c)) < tolerance) {
                cout<<"Root found at x = "<<c<<" after "<<i<<" iterations."<<endl;
                return;
        }

            if(f(a)*f(c) < 0) b = c;
            else a = c;
        }
    }
};


int main(){
    cout<<fixed<<setprecision(4);
    srand(time(0));

    double tolerance = 0.0001;
    int maxIterations = 100;

    double a, b;
    Bisection bisec;

    do{
        a = (rand() % (ub-lb+1)) + lb;
    }while (bisec.f(a) > 0);

    do{
        b = (rand() % (ub-lb+1)) + lb;
    }while (bisec.f(b) < 0);

    bisec.bisection(a, b, tolerance, maxIterations);

    return 0;
}
