#include <bits/stdc++.h>
using namespace std;

#define ub 10
#define lb 0
#define e 2.718

class Secant{
public:
    double f(double x){
        return x*x*x - 2*x - 5;
       // return x* pow(e,x) - 1;
    }

    void secantMethod(double x0, double x1, double tolerance, int maxIterations) {
        double x2;

        for(int i=1; i <= maxIterations; i++){
            x2 = x1-(f(x1)*(x1 - x0))/(f(x1)-f(x0));

            cout<<i<<"   x0="<<x0<<"   x1="<<x1<<"   f(x0)="<<f(x0)<<"   f(x1)="<<f(x1)<<"   x2="<<x2<<"   f(x2)"<<f(x2)<<endl;

            if(fabs(x2-x1) < tolerance){
                cout<<"Root found at x = "<<x2<<" after "<<i<<" iterations."<< endl;
                return;
            }

            x0 = x1;
            x1 = x2;
        }
    }
};

int main(){
    cout<<fixed<<setprecision(4);
    srand(time(0));

    double tolerance = 0.001;
    int maxIterations = 100;

    double a, b;
    Secant secant;

    do{
        a = (rand() % (ub-lb+1)) + lb;
    }while(secant.f(a) > 0);

    do{
        b = (rand() % (ub-lb+1)) + lb;
    }while(secant.f(b) < 0);

    secant.secantMethod(a, b, tolerance, maxIterations);

    return 0;
}

