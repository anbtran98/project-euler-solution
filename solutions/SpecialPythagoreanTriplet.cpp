#include <iostream>

/*
 * Project Euler: Prolem #9
 * DESCRIPTION: There exists exactly 1 Pythagorean triplet for which a + b + c = 1000.
 *              Find the product abc.
 * NOTE: Mistake made; I didn't validate a,b and c. This return wrong answers
 */

int sqr(int n) { return n * n; }
bool isPrime(long long int n);
bool validation(int a, int b, int c);
int solve();

int main () {

  solve();

  return 0;
}
int solve(){
  // Euclid's Formula
  int a, b, c;
  int sum;

  for ( int n = 1; n < 1000; n++ ) {
    for ( int m = 1; m < 1000; m++ ) {
      if (m > n){
        a = sqr(m) - sqr(n);
        b = 2 * m * n;
        c = sqr(m) + sqr(n);

        if ( validation(a,b,c) ){
          sum = a + b + c;
          if (sum == 1000){
            std::cout <<
              "The triplet: \n" <<
              "a: " << a << "\n" <<
              "b: " << b << "\n" <<
              "c: " << c << "\n" <<
              "The sum: " << sum << "\n" <<
              "The product: " << a * b * c << "\n";
            return sum;
          }
        }
      }
    }
  }
  return sum;
}

bool validation(int a, int b, int c) {

  int temp = sqr(a) + sqr(b);

  return temp == sqr(c);
}

bool isPrime(long long int n){

  int primeCounter = 0;

  if ( n <= 1 ) // 1 is not prime
    return false;

  for ( long long int i = 1; i <= n; ++i ) {
    if ( n % i == 0 )
        primeCounter++;
    if (primeCounter > 2)
      break;
  }

  if (primeCounter > 2)
    return false;

  return true;
}
