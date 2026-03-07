#include <stdio.h>
#include <math.h>

// Function to evaluate polynomial at x
double polynomial(double x, double coeffs[], int degree) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coeffs[i] * pow(x, degree - i); // Calculate a*x^n
    }
    return result;
}

// Function to evaluate derivative of polynomial at x
double derivative(double x, double coeffs[], int degree) {
    double result = 0;
    for (int i = 0; i < degree; i++) {
        result += coeffs[i] * (degree - i) * pow(x, degree - i - 1); // Calculate a*n*x^(n-1)
    }
    return result;
}

int main() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    double coeffs[degree+1];
    printf("Enter the coefficients (from highest degree to constant):\n");
    for (int i = 0; i <= degree; i++) {
        scanf("%lf", &coeffs[i]);
    }

    double x0;
    printf("Enter an initial guess for the root: ");
    scanf("%lf", &x0);

    double tolerance;
    printf("Enter the tolerance for convergence: ");
    scanf("%lf", &tolerance);

    int max_iterations = 1000;
    int iter = 0;
    double x1;

    // Newton's Method Iteration
    do {
        double fx0 = polynomial(x0, coeffs, degree);
        double dfx0 = derivative(x0, coeffs, degree);
        
        if (dfx0 == 0) {
            printf("Derivative is zero. No solution found.\n");
            return 1; // Exit if derivative is zero
        }
        
        x1 = x0 - (fx0 / dfx0); // Newton's formula
        iter++;

        printf("Iteration %d: x = %.6lf\n", iter, x1);

        if (fabs(x1 - x0) < tolerance) {
            break; // Stop if within tolerance
        }
        
        x0 = x1; // Update x0 for next iteration
    } while (iter < max_iterations);

    if (iter == max_iterations) {
        printf("Maximum iterations reached. Approximate root: %.6lf\n", x1);
    } else {
        printf("Found root: %.6lf in %d iterations.\n", x1, iter);
    }

    return 0;
}
