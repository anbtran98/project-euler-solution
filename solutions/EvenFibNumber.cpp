#include <iostream>
#define LIMIT 4000000

/*
 * Project Euler: Prolem #2
 * DESCRIPTION: Find the SUM of the EVEN-VALUED terms of a fibonacci sequence whose values DON'T exceed 4 million
 */

int fib(int n);

int main () {

  int n = 1;
  int m = fib(n);
  int sum = 0;

  do{
    ++n;
    m = fib(n);
    std::cout << m << " ";
    if (m % 2 == 0)
      sum += m;
  }while(m < LIMIT);
  
  std::cout << "\n" << "Sum of even fib numbers: " << sum << "\n";

  return 0;
}

int fib( int n ) {
  if (n == 0)
    return 0;
  if ((n == 1) || (n == 2))
    return 1;

  return fib(n - 1) + fib(n - 2);
}
