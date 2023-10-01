#include <iostream>
#include <sstream>

using namespace std;

auto printSomething = [](const string text){
  cout << text;
};

// Helper function to calculate square root without using std::sqrt()
auto square_root = [](const double x, const double epsilon = 1e-10, const int max_iterations = 1000) -> double {
    //std::cout << "Calculating square root of " << x << "\n";
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

        //std::cout << "Iteration: " << i + 1 << ", mid: " << mid << ", mid_square: " << mid_square << "\n";

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

auto calculate_circumradius = [](const double a, const double b, const double c) -> double {
    const double s = (a + b + c) / 2;
    const double area = square_root(s * (s - a) * (s - b) * (s - c));
    return (a * b * c) / (4 * area);
};

auto curry_calculate_circumradius = [](const double a){
    return [a](const double b){
        return [a,b](const double c){
            return calculate_circumradius(a,b,c);
        };
    };
};

int main() {
    std::stringstream output;
    
    const double a=3, b=4, c=5;
    output << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    const double circumradius = curry_calculate_circumradius(a)(b)(c);

    output << "Circumradius: " << circumradius << "\n";

    printSomething(output.str());
    return 0;
}
