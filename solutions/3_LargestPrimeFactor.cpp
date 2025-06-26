#include <iostream>
#include <cmath>

/*
 * Project Euler: Prolem #3
 * DESCRIPTION: Find the LARGEST PRIME FACTOR of a number
 */

bool isPrime(long long int n);
bool isFactor(long long int n, long long int f);

int main () {

  long long int number = 600851475143;
  long long int max = 2;
  long long int x = 1;
  
  std::cout << "The largest prime factor of " << number << ": ";

  while ( x * x < number){
    if (isFactor(number, x) && ( x > max ))
      if (isPrime(x))
        max = x;
    x++;
  }

  std::cout << max << "\n";

  return 0;
}

bool isPrime(long long int n){

  int primeCounter = 0;

  if ( n <= 1 ) // 1 is not prime
    return false;

  for (long long int i = 2; i <= n; ++i ) {
    if ( n % i == 0 )
        primeCounter++;
  }

  if (primeCounter > 2)
    return false;

  return true;
}

bool isFactor(long long int n, long long int f){
  if (n % f == 0)
    return true;
  return false;
}
