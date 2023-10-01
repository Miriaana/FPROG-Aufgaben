#include <iostream>
#include <sstream>
#include <tuple>

auto printSomething = [](const std::string text){
  std::cout << text;
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

auto calculate_area_and_radii =[](const double a, const double b, const double c) -> std::tuple<double, double, double> {
    const double s = (a + b + c) / 2;
    const double area = square_root(s * (s - a) * (s - b) * (s - c));
    const double inradius = area / s;
    const double circumradius = (a * b * c) / (4 * area);
    return std::make_tuple(area, inradius, circumradius);
};

auto curry_calculate_area_and_radii = [](const double a){
    return [a](const double b){
        return [a,b](const double c){
            return calculate_area_and_radii(a,b,c);
        };
    };
};

auto calculate_distance = [](const double circumradius, const double inradius) -> double {
    return square_root(circumradius * circumradius - 2 * circumradius * inradius);
};

auto curry_calculate_distance = [](const double circumradius){
    return [circumradius](const double inradius){
        return calculate_distance(circumradius,inradius);
    };
};

int main() {
    std::stringstream output;

    const double a=3, b=4, c=5;
    //double area, circumradius, inradius, distance;
    output << "Triangle sides: a = " << a << ", b = " << b << ", c = " << c << "\n";

    
    auto [area, inradius, circumradius] = curry_calculate_area_and_radii(a)(b)(c);
    output << "Inradius: " << inradius << "\n";
    output << "Circumradius: " << circumradius << "\n";

    const double distance = curry_calculate_distance(circumradius)(inradius);
    output << "Distance between circumcenter and incenter: " << distance << "\n";
    printSomething(output.str());

    return 0;
}
