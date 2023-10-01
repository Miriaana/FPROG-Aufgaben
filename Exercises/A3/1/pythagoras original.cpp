#include <iostream>

using namespace std;

int x = 0;
int y = 0;
int z = 0;  // double ?


int
square (int e)
{
	int dummy=e;
	int dummy2=e;
  for (int i=1;i<dummy2;i++)
  	{
  		e=e+dummy;
  		cout << "i: " << i << " dummy:" << dummy << " e:" << e << endl;
  	}
  cout << "square:" << e << endl;
  return e;
}

double
squareroot (double x)
{				/* computes the square root of x */

  if (x == 0)
    return 0;

/* the sqrt must be between xhi and xlo */
  double xhi = x;
  double xlo = 0;
  double guess = x / 2;

/* We stop when guess*guess-x is very small */

  while (abs (guess * guess - x) > 0.00001)
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
  cout << "guess:" << guess << endl;;
  return guess;
}


void
pythagoras ()
{
  z = squareroot (square (x) + square (y));
  cout << "euklid:" << z << endl;
}


int
main (int argc, char *argv[])
{
  x = 3;
  y = 4;
  pythagoras ();
  cout << z << endl;
  return 0;
}
