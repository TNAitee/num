#include <iostream>
using namespace std;

void gaussElimination(float m[10][10], int n){
    for(int i=0; i<n; i++){
        if(m[i][i] == 0.0){
            cout<<"Mathematical Error!"<<endl;
            return;
        }

        for(int j=i+1; j<n; j++){
            float ratio = m[j][i] / m[i][i];
            for (int k=0; k<=n; k++){
                m[j][k] = m[j][k] - ratio * m[i][k];
            }
        }
    }


    float x[10];
    for(int i=n-1; i>=0; i--){
        x[i] = m[i][n];
        for(int j=i+1; j<n; j++){
            x[i] =  x[i] - m[i][j] * x[j];
        }
        x[i] /= m[i][i];
    }

    cout<<"Solution: "<< endl;
    for(int i=0; i<n; i++){
        cout<<"x"<<i+1<<" = "<<x[i]<<endl;
    }
}

int main() {
    float m[10][10];
    int n;

    cout<<"Enter the number of variables: ";
    cin>>n;

    cout<<"Enter the augmented matrix coefficients row-wise:"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            cin>>m[i][j];
        }
    }

    gaussElimination(m, n);

    return 0;
}
