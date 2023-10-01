#include <iostream>
#include <utility>
#include <complex>

typedef std::complex<double> complex;

double
square (double e)
{
	double dummy=e;
	double dummy2=e;
  for (int i=1;i<dummy2;i++)
  	{
  		e=e+dummy;
  		std::cout << "i: " << i << " dummy:" << dummy << " e:" << e << std::endl;
  	}
  std::cout << "square:" << e << std::endl;
  return e;
}

inline float squareroot(float number)
{
    union Conv {
        float    f;
        uint32_t i;
    };
    Conv conv;
    conv.f= number;
    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
    return 1/conv.f;
}

std::pair<complex, complex>
 solve_quadratic_equation(double a, double b, double c)
{
  b /= a;
  c /= a;
  double discriminant = square(b)-4*c;
  if (discriminant < 0)
    return std::make_pair(complex(-b/2, squareroot(-discriminant)/2),
                          complex(-b/2, -squareroot(-discriminant)/2));

  double root = std::sqrt(discriminant);
  double solution1 = (b > 0)? (-b - root)/2
                            : (-b + root)/2;

  return std::make_pair(solution1, c/solution1);
}

int main()
{
  std::pair<complex, complex> result = solve_quadratic_equation(3, 4, 5);
  std::cout << result.first << ", " << result.second << std::endl;
}