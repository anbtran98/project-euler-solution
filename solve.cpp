/*
 * Project Euler:
 * Prolem #12
 * Title: Highly Divisible Triangular Number
 * DESCRIPTION: What is the value of the first triangle number to have over 500 divisors (factors)?
 */

#include <iostream>
#include <vector>
#include <algorithm>

unsigned int get_triangular_number(const unsigned int& n) {
    return n * (n + 1) / 2;
}

bool isPrime (const unsigned int& n) {
  unsigned int primeCounter = 0;
  if ( n <= 1 ) // 1 is not prime
    return false;
  for ( long long unsigned int i = 1; i <= n; ++i ) {
    if ( n % i == 0 )
        primeCounter++;
    if (primeCounter > 2)
        return false;
  }

  return true;
}

unsigned int get_largest_prime_factor(const unsigned int& n) {
    unsigned int result{1};
    for (unsigned int i = n; i > 0; i--) {
        if (isPrime(i) && n % i == 0) {
            result = i;
            break;
        }
    }
    return result;
}

unsigned int get_smallest_prime_factor (const unsigned int& n) {
    for (unsigned int i = 2; i < n; i++) {
        if (n % i == 0)
            return i;
    }
    return 1;
}

bool isExist (const unsigned int& n, const std::vector<unsigned int>& vInt) {
    for (auto i : vInt)
        if (n == i)
            return true;
    return false;
}

void store(unsigned int& n, std::vector<unsigned int>& vInt) {
    if (!isExist(n, vInt))
        vInt.push_back(n);
}

std::vector<unsigned int> getFactors (const unsigned int& n,
                                      void (*fooPtr)(const unsigned int&, unsigned int, std::vector<unsigned int>&))
{
    std::vector<unsigned int> temp{};
    unsigned int factor, product, currentNumber{n};
    bool repeat{false};
    // temp.push_back(n);
    for (unsigned int i = 1; i <= n; i++) {
        if (isPrime(i) && n % i == 0) {
            factor = i;
            if (!isExist(factor, temp))
                temp.push_back(factor);
            product = n / i;
            if (!isExist(product, temp))
                temp.push_back(product);
        }
    }
    fooPtr(2, 1, temp);
    // do {
    //     repeat = false;
    //     factor = get_smallest_prime_factor(currentNumber);
    //     if (!isExist(factor, temp))
    //         temp.push_back(factor);
    //     product = currentNumber / factor;
    //     if (!isExist(product, temp))
    //         temp.push_back(product);
    //     if (!isPrime(product) && product != 1) {
    //         currentNumber = factor;
    //         repeat = true;
    //     }
    // } while (repeat) 
    if (!isExist(1, temp))
        temp.push_back(1);
    return temp;
}

void findFactorRecursive(const unsigned int& n, std::vector<unsigned int>& v) {
    if (n == 1) {
        unsigned int t = 1;
        store(t, v);
        return;
    }
    unsigned int factor;
    unsigned int limit{n};
    store(limit, v);
    for (unsigned int i = 1; i <= limit; i++) {
        if (i == 1)
            store(i, v);
        if (n % i == 0 && isPrime(i)) {
            factor = i;
            store(factor, v);
            break;
        }
    }

    unsigned int product {n / factor};
    store(product, v);
    if (!isPrime(product))
        findFactorRecursive( product, v);
    else
        return;
}

int main () {
    unsigned int limit {100000};
    std::cout << "Triangular numbers:" << std::endl;
    for (unsigned int i = 1; i <= limit; i++) {
        std::vector<unsigned int> factorMem{};
        // Get triangular number
        unsigned long int triangularN{get_triangular_number(i)};
        std::cout << "[" << i << "] ";
        std::cout << "[" << triangularN << "]";
        // Find the factor
        findFactorRecursive(triangularN, factorMem);
        std::sort(factorMem.begin(), factorMem.end());
        // Fill in the missing factors
        unsigned int max = factorMem.back();
        int ll{0};
        std::vector<unsigned int> temp;
        for (int l = 0; l < (int)factorMem.size(); l++) {
            std::sort(factorMem.begin(), factorMem.end());
            unsigned int prod;
            for (int m = l; m < (int)factorMem.size(); m++) {
                prod = factorMem[l] * factorMem[m];
                if (prod <= max && max % prod == 0) {
                    if (!isExist(prod, factorMem) && !isExist(prod, temp)) {
                        factorMem.push_back(prod);
                    }
                }
            }
        }
        for (auto k : temp) {
            factorMem.push_back(k);
        }
        // Print the result
        std::cout << " " << factorMem.size() << std::endl;
        if (factorMem.size() == 500) {
            std::cout << "Answer: triangularN" << std::endl;
            break;
        }
        // for (const auto& k : factorMem) {
        //     std::cout << " " << k;
        // }
        // std::cout << std::endl;
        factorMem.clear();
    }

    return 0;
}
