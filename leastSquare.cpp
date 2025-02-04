#include <iostream>
#include <numeric>  // for std::accumulate

// Function to calculate the coefficients a0 (intercept) and a1 (slope) of the line y = a0 + a1x
void leastSquaresMethod(const double x[], const double y[], int n, double& a0, double& a1) {
    // Calculate sums
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;

    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate a1 (slope) and a0 (intercept)
    a1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a0 = (sumY - a1 * sumX) / n;
}

int main() {
    // Example data points (x, y) in arrays
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2, 3, 5, 6, 5};

    int n = sizeof(x) / sizeof(x[0]); // Number of data points

    double a0, a1;

    // Calculate the line of best fit
    leastSquaresMethod(x, y, n, a0, a1);

    // Output the results
    std::cout << "The line of best fit is: y = " << a0 << " + " << a1 << "x" << std::endl;

    return 0;
}
