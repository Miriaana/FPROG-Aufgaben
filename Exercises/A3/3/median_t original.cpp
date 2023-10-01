#include <iostream>

// Global variables
double a, b, c;

// Silly square function that is not immutable and not pure
double silly_square(double x) {
    std::cout << "Calculating the silly square of " << x << "\n";
    double result = 0;
    for (int i = 0; i < x; ++i) {
        result += x;
        std::cout << "Iteration " << i + 1 << ": Current result = " << result << "\n";
    }
    return result;
}

// Helper function to calculate square root without using std::sqrt()
double square_root(double x, double epsilon = 1e-10, int max_iterations = 1000) {
    std::cout << "Calculating the square root of " << x << "\n";
    if (x < 0) {
        return -1; // Invalid input
    }
    if (x == 0) {
        return 0;
    }

    double low = 0, high = x;
    double mid;
    for (int i = 0; i < max_iterations; ++i) {
        mid = (low + high) / 2.0;
        double mid_square = mid * mid;
        std::cout << "Iteration " << i + 1 << ": Midpoint = " << mid << ", Midpoint squared = " << mid_square << "\n";

        if (mid_square > x) {
            high = mid;
        } else if (mid_square < x) {
            low = mid;
        }

        if (high - low < epsilon) {
            break;
        }
    }

    return mid;
}

double calculate_median() {
    std::cout << "Calculating the median of a triangle with sides a = " << a << ", b = " << b << ", c = " << c << "\n";
    double result = 0.5 * square_root(2 * silly_square(b) + 2 * silly_square(c) - silly_square(a));
    return result;
}

int main() {
    a = 3;
    b = 4;
    c = 5;
    std::cout << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    double median_a = calculate_median();
    a = 4, b = 3, c = 5;
    double median_b = calculate_median();
    a = 5, b = 3, c = 4;
    double median_c = calculate_median();

    std::cout << "Medians:\n";
    std::cout << "Median from vertex A: " << median_a << "\n";
    std::cout << "Median from vertex B: " << median_b << "\n";
    std::cout << "Median from vertex C: " << median_c << "\n";

    return 0;
}
