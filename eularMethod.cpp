#include <iostream>
using namespace std;

double f(double x, double y){
    return x + y;
}

void eulerMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    for (int i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;

        cout << "After step " << i + 1 << ": x = " << x << ", y = " << y << endl;
    }
}

int main() {
    double x0, y0, h;
    int n;

    cout << "Enter initial value of x (x0): ";
    cin >> x0;
    cout << "Enter initial value of y (y0): ";
    cin >> y0;
    cout << "Enter step size (h): ";
    cin >> h;
    cout << "Enter number of steps (n): ";
    cin >> n;

    eulerMethod(x0, y0, h, n);

    return 0;
}
