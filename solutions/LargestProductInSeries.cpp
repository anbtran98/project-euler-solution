#include <iostream>
#include <fstream>

/*
 * Project Euler: Prolem #8
 * DESCRIPTION: Find the thirtenn adjacent digits in the 1000-digit number that have the greatest product.
 *              What is the value of this product?
 *
 * NOTE: This program required a text file with the 1000-digit number
 *       - The text file is named "LargestProductinSeries_res.txt" in res folder
 *
 * NOTE: Couple failed attempts causes by setting data type for product, temp, and max
 *       as 1) int, 2) unsigned long int
 *       - This is because the solution is of a data type long long int (big number)
 *       - (int) and (long int) isn't big enough
  */

#define CHUNK_SIZE 13

int main () {

  std::string line,hugeLine;
  std::ifstream inputFile( "LargestProductinSeries_res.txt" );

  if ( inputFile.is_open() ) {
    while ( getline(inputFile, line) ) {
      hugeLine.append(line);
    }
    inputFile.close();
  } else std::cout << "Unable to open file\n";

  int limit = (int)hugeLine.length();
  long long int product, temp, max = 0;

  for ( int i = 0; i < limit; i++ ){
    product = 1;
    for ( int j = i; j < i + CHUNK_SIZE; j++ ){
      temp = (int)hugeLine[j] - 48;
      product *= temp;
    }

    if (max < product)
      max = product;
  }

  std::cout << "Result: " << max << "\n";

  return 0;
}
