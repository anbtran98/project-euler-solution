#include <iostream>
#include <cmath>

/*
 * Project Euler: Prolem #6
 * DESCRIPTION: Find the difference between the sum of the squares of the 1st 100 natural numbers
 *                   and the square of the sum.
 */

int sqr ( int n ) { return n * n;}

int main () {

  int limit = 100;
  int sumOfSquares = 0, squareOfSum = 0;
  int solution;

  // sum of squares of the 1st 100 natural numbers
  for ( int i = 1; i <= limit; i++ )
    sumOfSquares += sqr(i);

  // square of the sum
  for ( int i = 1; i <= limit; i++ )
    squareOfSum += i;
  squareOfSum = sqr(squareOfSum);

  solution = squareOfSum - sumOfSquares;

  std::cout << "Sum of Square: " << sumOfSquares << "\n";
  std::cout << "Square of Sum: " << squareOfSum << "\n";
  std::cout << "\033[4mSolution\033[0m: " << solution << "\n";

  return 0;
}
