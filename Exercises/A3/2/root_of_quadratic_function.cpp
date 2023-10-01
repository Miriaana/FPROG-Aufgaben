#include <iostream>
#include <utility>
#include <complex>

typedef std::complex<double> complex;

auto square = [](const double e) -> double
{
  double result = e;
  for (int i = 1; i < e; i++)
  {
    result += e;
    //std::cout << "i: " << i << " dummy:" << dummy << " e:" << e << std::endl;
  }
  //std::cout << "square:" << result << std::endl;
  return result;
};

inline auto squareroot = [](const float number) -> float
{
  union Conv
  {
    float f;
    uint32_t i;
  };
  Conv conv;
  conv.f = number;
  conv.i = 0x5f3759df - (conv.i >> 1);
  conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
  return 1 / conv.f;
};


auto solve_quadratic_equation = [](const double a, const double b, const double c) -> std::pair<complex, complex>
{
  double bDiv = b/a;
  double cDiv = c/a;

  double discriminant = square(bDiv) - 4 * cDiv;
  if (discriminant < 0)
    return std::make_pair(complex(-bDiv / 2, squareroot(-discriminant) / 2),
                          complex(-bDiv / 2, -squareroot(-discriminant) / 2));

  double root = std::sqrt(discriminant);
  double solution1 = (bDiv > 0) ? (-bDiv - root) / 2
                             : (-bDiv + root) / 2;

  return std::make_pair(solution1, cDiv / solution1);
};

auto curry_solve_quadratic_equation = [](const double a){
  return [a](const double b){
    return [a,b](const double c){
      return solve_quadratic_equation(a,b,c);
    };
  };
};

int main()
{
  std::pair<complex, complex> result = curry_solve_quadratic_equation(3)(4)(5);
  std::cout << result.first << ", " << result.second << std::endl;
}