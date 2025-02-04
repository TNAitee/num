#include <iostream>
#include <vector>

using namespace std;

double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double X) {
    int n = x.size();
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (X - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    vector<double> x = {2, 2.5, 3};
    vector<double> y = {0.69315, 0.91629, 1.09861};

    double X = 2.7;

    double result = lagrangeInterpolation(x, y, X);

    cout << "Interpolated value at x = " << X << " is: " << result << endl;

    return 0;
}
