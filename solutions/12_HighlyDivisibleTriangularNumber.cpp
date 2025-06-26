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

void getFactors (const unsigned int& n, std::vector<unsigned int>& v) {
    findFactorRecursive(n, v);
    std::sort(v.begin(), v.end());
    // Fill in the missing factors
    unsigned int max = v.back();
    int ll{0};
    std::vector<unsigned int> temp;
    for (int l = 0; l < (int)v.size(); l++) {
        std::sort(v.begin(), v.end());
        unsigned int prod;
        for (int m = l; m < (int)v.size(); m++) {
            prod = v[l] * v[m];
            if (prod <= max && max % prod == 0) {
                if (!isExist(prod, v) && !isExist(prod, temp)) {
                    v.push_back(prod);
                }
            }
        }
    }
    for (auto k : temp) {
        v.push_back(k);
    }
    // return temp;
}

int main () {
    unsigned int limit {50000};
    unsigned int halfLimit {limit / 2};
    int countNum = 0;
    int max = 0;
    int num;
    std::cout << "Triangular numbers:" << std::endl;
    for (unsigned int i = 1, u = halfLimit + i; i <= halfLimit; i++, u++) {
        std::vector<unsigned int> factorMem{};
        // Get triangular number
        unsigned long int triangularN{get_triangular_number(i)};
        unsigned long int triangularN2(get_triangular_number(u));
        std::cout << "[" << i << "] ";
        std::cout << "[" << triangularN << "]";
        /* Find the factor */
        getFactors(triangularN, factorMem);
        std::cout << " " << factorMem.size() << std::endl;
        if (max < factorMem.size()) {
            max = factorMem.size();
            num = triangularN;
            countNum = i;
        }
        if (factorMem.size() >= 500) {
            std::cout << "Answer: " << triangularN << std::endl;
            break;
        }
        factorMem.clear();

        /*
          NOTE: Attempt at improving speed by split find factor function call by 2
              - Result: failed, skipped over the real answer.
         */
        // std::cout << "[" << u << "] ";
        // std::cout << "[" << triangularN2 << "]";
        // getFactors(triangularN2, factorMem);
        // std::cout << " " << factorMem.size() << std::endl;
        // if (max < factorMem.size()) {
        //     max = factorMem.size();
        //     num = triangularN2;
        //     countNum = u;
        // }
        // if (factorMem.size() >= 500) {
        //     std::cout << "Answer: "<< triangularN2 << std::endl;
        //     break;
        // }
        // factorMem.clear();
    }

    std::cout << "Triangular Number with largest number of factors in this set: \n" << num
              << "\nSize: " << max
              << "\nInteger: " << countNum
              << std::endl;
    return 0;
}
