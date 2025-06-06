#include <iostream>
#include <cmath>
#include <sstream>

/*
 * Project Euler: Prolem #4
 * DESCRIPTION: Find the LARGEST PALINDROME made from the PRODUCT of 2 3-digit numbers
 * NOTE: need to optimize palindrome function
 */

bool isPalindromic( int n );

int main () {

  int product, max = 0;

  for ( int i = 1; i < 1000; i++) {
    for ( int j = 1; j < 1000; j++) {
      product = j * i;

      if ( isPalindromic(product) && (product > max) ){
        max = product;
      }
    }
  }

  std::cout << "The largest palindrome number: " << max << "\n";

  return 0;
}

bool isPalindromic( int n ) {

  // Find the number of digits within the given number n
  int temp = n, i = 0;
  while (temp != 0) {
    temp = temp / 10;
    i++;
  }

  int ndigits = i;
  std::string str, str2;
  std::stringstream ss, ss2;
  int num1, num2, com;
  
  // Check if the number of digits is even of odd
  if (i % 2 == 0){ // even
    // turn the number to string
    str = std::to_string(n);

    // get half of the number
    for ( int i = 0; i < ndigits / 2; ++i) {
      str2.append( &str.back() ); // append last element to str2
      str.pop_back(); // pop last element from str
    }

    // turns the 2 string back to numbers
    ss << str;
    ss2 << str2;
           
    ss >> num1;
    ss2 >> num2;
    
    // then compare
    com = num1 - num2;
    if (com == 0)
      return true;
    else
      return false;
  }

  // If odd
  // Get the right digits
  str = std::to_string(n);
  //     loop through the string
  for ( int i = 0; i < (ndigits - 1) / 2; ++i) {
    str2.append( &str.back() );
    str.pop_back();
  }
  
  ss2 << str2;
  ss2 >> num2;
  
  // Get the left digits
  num1 = n / pow(10, (ndigits - 1) / 2 + 1);

  com = num1 - num2;
  if (com == 0)
    return true;
  else
    return false;

}

// find palindromic algorithm
// 
  // Find how many digits are in the number
  // check if the number has even or odd number of digits
  // if even
  //    separate left digits from right
  //    then, flip either of the numbers
  //    then, compare the 2 numbers
  // if odd
  //    find the middle digit
  //    then, separate left digits from right
  //    then, flip either of the numbers
  //    then, compare the 2 numbers
