#include <bits/stdc++.h>
using namespace std;

#define ub 10
#define lb 0
#define e 2.718

class NewtonRaphson{
public:
    double f(double x){
        return 3*x*x - 10*x + 7;
        //return x*sin(x) + cos(x);
        //return x* pow(e,x) - 1;
    }

    double df(double x){
       return 6*x - 10;
        //return x*cos(x);
        //return x* pow(e,x) + pow(e,x);
    }

    void newtonRaphson(double initial, double tolerance, int maxIterations){
        double x0 = initial;
        double x1 = x0-f(x0)/df(x0);

        for(int i=1; i <= maxIterations; i++){
            cout<<i<<"   x0="<<x0<<"   f(x0)="<<f(x0)<<"   f'(x)="<<df(x0)<<"  x1="<<x1<<endl;

            if(fabs(x1-x0) < tolerance){
                cout<<"Root found at x = "<<x1<<" after "<<i<<" iterations."<<endl;
                return;
            }

            x0 = x1;
            x1 = x0-f(x0)/df(x0);
        }
    }
};

int main(){
    cout<<fixed<<setprecision(4);
    srand(time(0));

    double tolerance = 0.0001;
    int maxIterations = 100;

    double a;
    NewtonRaphson newton;

    do{
        a = (rand() % (ub-lb+1)) + lb;
    }while(newton.f(a) == 0);

    newton.newtonRaphson(a,  tolerance, maxIterations);

    return 0;
}
