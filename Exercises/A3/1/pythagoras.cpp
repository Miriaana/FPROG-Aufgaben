#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <tuple>

using namespace std;

auto printSomething = [](const string text) -> void
{
  cout << text;
};

// function<int(int)> square
auto square = [](const int e) -> int
{
  int dummy = e; // result
  int dummy2 = e;
  for (int i = 1; i < dummy2; i++)
  {
    dummy = dummy + dummy2;
  }
  return dummy;
};

auto squareroot = [](const double x) -> double
{
  /* computes the square root of x */

  if (x == 0)
    return 0;

  /* the sqrt must be between xhi and xlo */
  double xhi = x;
  double xlo = 0;
  double guess = x / 2;

  /* We stop when guess*guess-x is very small */

  while (abs(guess * guess - x) > 0.00001)
  {
    if (guess * guess > x)
    {
      xhi = guess;
    }

    else
    {
      xlo = guess;
    }

    guess = (xhi + xlo) / 2;
  }
  return guess;
};

auto pythagoras = [](const int x, const int y) -> tuple<double, string>
{
  stringstream output;

  auto xSquared = square(x);
  output << "square:" << xSquared << endl;

  auto ySquared = square(y);
  output << "square:" << ySquared << endl;

  auto result = squareroot(xSquared + ySquared);
  output << "euklid:" << result << endl;

  return make_tuple(result, output.str());

  /*auto resultXSquared = square(x);
  output << get<1>(resultXSquared);

  auto [resultYSquared, YSquaredOutput] = square(y);
  output << YSquaredOutput;*/
};

auto curryPythagoras = [](const int x)
{
  return [x](const int y)
  {
    return pythagoras(x, y);
  };
};

int main(int argc, char *argv[])
{
  stringstream output;
  const int x = 3;
  const int y = 4;

  auto [z, pythagorasOutput] = curryPythagoras(x)(y);
  output << pythagorasOutput;
  output << z << endl;

  printSomething(output.str());

  return 0;
}

/*
auto simpleCurry3 = [](auto f)
{
  return [f](auto x, auto y){return bind(f,x,y,_1)};
};
*/