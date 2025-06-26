#include <iostream>

/*
 * Project Euler: Prolem # 7
 * DESCRIPTION: What is the 10,001st prime number
 */

bool isPrime(long long int n);
int nthPrimeNumber( int n );

int main () {

  int solution = nthPrimeNumber( 10001 );

  std::cout << "Solution: " << solution << "\n";

  return 0;
}

int nthPrimeNumber( int n ) {

  int i = 2, count = 0;
  bool endFlag = false;

  while ( !endFlag ) {
    if ( isPrime(i) )
      count++;

    if ( count == n )
      break;
    i++;
  }
  
  return i;
}

bool isPrime(long long int n){

  int primeCounter = 0;

  if ( n <= 1 ) // 1 is not prime
    return false;

  for ( long long int i = 1; i <= n; ++i ) {
    if ( n % i == 0 )
        primeCounter++;
  }

  if (primeCounter > 2)
    return false;

  return true;
}
