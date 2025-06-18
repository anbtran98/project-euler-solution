#include <iostream>

/*
 * Project Euler: Prolem #5
 * DESCRIPTION: What is the smallest positive number that is EVELY DIVISIBLE by all of the numbers from 1 to 20
 */

int main () {

  int endFlag = false;
  int count = 0, x = 0;
  int limit = 20;

  while ( !endFlag ) {
    x++;

    for ( int i = 1; i <= limit; i++) {
      if ( (x % i == 0) && (x % 2 == 0) )
        count++;
      else
        break;
    }

    if ( count == limit )
      endFlag = true;
    else
      count = 0;
  }

  std::cout << "Solution: " << x << "\n";

  return 0;
}
