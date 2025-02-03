#include<bits/stdc++.h>
using namespace std;

double pCal(double p, int n){
	double temp=p;
	for(int i=1; i<n; i++)
		temp = temp*(p-i);
        return temp;
}

int fact(int n){
	int f=1;
	for(int i=2; i<=n; i++)
		f *= i;
        return f;
}

int main(){
	int n=5;
	double x[]={1891, 1901, 1911,1921, 1931};

	double y[n][n];
	y[0][0] = 46;
    y[1][0] = 66;
    y[2][0] = 81;
    y[3][0] = 93;
    y[4][0] = 101;

	for(int i=1; i<n; i++){
		for(int j=0; j<n-i; j++)
			y[j][i] = y[j+1][i-1] - y[j][i-1];
	}

	for (int i=0; i<n; i++){
		cout<<setw(4)<<x[i]<<" ";
		for(int j=0; j<n-i; j++)
			cout<<setw(4)<<y[i][j]<<" ";
		cout<<endl;
	}

	double value = 1895;

	double sum = y[0][0];
	double p = (value-x[0])/(x[1]-x[0]);
	for(int i=1; i<n; i++){
		sum = sum + (pCal(p,i)*y[0][i]) / fact(i);
	}

	cout<<"Value at "<<value<<" is "<<sum<<endl;
	return 0;
}
