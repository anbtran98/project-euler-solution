/*
 * Project Euler:
 * Prolem #12
 * Title: Highly Divisible Triangular Number
 * DESCRIPTION: What is the value of the first triangle number to have over 500 divisors (factors)?
 */

#include <iostream>
#include <vector>

bool isPrime (const int& n) {
  int primeCounter = 0;
  if ( n <= 1 ) // 1 is not prime
    return false;
  for ( long long int i = 1; i <= n; ++i ) {
    if ( n % i == 0 )
        primeCounter++;
    if (primeCounter > 2)
        return false;
  }
  return true;
}

int get_largest_divisible_prime(const int& n) {
    int result{-1};
    for (int i = n; i > 0; i--) {
        if (isPrime(i) && n % i == 0) {
            result = i;
            break;
        }
    }
    return result;
}

bool isExist (const int& n, const std::vector<int>& vInt) {
    return false;
}

int main () {

    int limit {10};
    st::cout << "Triangular numbers:" ::std::endl;
    for (int i = 1; i <= limit; i++) {
        std::vector<int> factorMem{};
        int triangularN{get_triangular_number(i)};
        std::cout << "[" << triangularN << "]";
        int factor, result;
        // Get the factors
        do {
            factor = get_largest_divisible_prime(i);
            if (!isExist(factor))
                factorMem.push_back();
            result = i / factor;
            if (!isExist(result))
                factorMem.push_back();
        } while (!isPrime(result));
        // print the factors
        for (const auto& i : factorMem) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
        factorMem.clear();
    }

    return 0;
}
