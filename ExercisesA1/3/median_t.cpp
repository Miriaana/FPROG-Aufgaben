#include <iostream>
#include <sstream>

using namespace std;

auto printSomething = [](const string text){
  cout << text;
};

// Silly square function that is not immutable and not pure
auto silly_square = [](const double x) -> double {
    //std::cout << "Calculating the silly square of " << x << "\n";
    double result = 0;
    for (int i = 0; i < x; ++i) {
        result += x;
        //std::cout << "Iteration " << i + 1 << ": Current result = " << result << "\n";
    }
    return result;
};

// Helper function to calculate square root without using std::sqrt()
auto square_root = [](const double x, const double epsilon = 1e-10, const int max_iterations = 1000) -> double{
    //std::cout << "Calculating the square root of " << x << "\n";
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
        //std::cout << "Iteration " << i + 1 << ": Midpoint = " << mid << ", Midpoint squared = " << mid_square << "\n";

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
};

auto curry_square_root = [](const double x){
    return [x](const double epsilon){
        return [x,epsilon](const int max_iterations){
            return square_root(x,epsilon,max_iterations);
        };
    };
};

auto calculate_median = [](const double a, const double b, const double c) -> double{
    //std::cout << "Calculating the median of a triangle with sides a = " << a << ", b = " << b << ", c = " << c << "\n";
    double result = 0.5 * square_root(2 * silly_square(b) + 2 * silly_square(c) - silly_square(a));
    return result;
};

auto curry_calculate_median = [](const double a){
    return [a](const double b){
        return [a,b](const double c){
            return calculate_median(a,b,c);
        };
    };
};

int main() {
    std::stringstream output;
    const double a=3;
    const double b=4;
    const double c=5;
    output << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    double median_a = curry_calculate_median(a)(b)(c);
    double median_b = curry_calculate_median(b)(a)(c);
    double median_c = curry_calculate_median(c)(a)(b);

    output << "Medians:\n";
    output << "Median from vertex A: " << median_a << "\n";
    output << "Median from vertex B: " << median_b << "\n";
    output << "Median from vertex C: " << median_c << "\n";

    printSomething(output.str());
    return 0;
}
