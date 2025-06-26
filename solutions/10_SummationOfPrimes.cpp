#include <iostream>
#include <vector>

/*
 * Project Euler: Prolem #10
 * NAME: Summation of Primes
 * DESCRIPTION: Find the sum of all the primes below 2 million
 */

/*
 * Solution: 142913828922
 * Takes a long time to complete (last run: 8m 17.752s)
 */

#define LIMIT 2000000

bool isPrime(long long int n);
long long int vectorSum( std::vector <long long int> inV );
void solve();

int main () {
    solve();
    return 0;
}

void solve(){
    long long int sum = 0, x = 0, i=0;
    std::vector<long long int> temp;

    while (x <= LIMIT) {
        if (isPrime(x)){
            temp.insert(temp.end(), x);
            if (temp.size() == 100){
                // calculate the sum of the current numbers in the vector
                long long int tempSum = vectorSum(temp);
                // remove all number from the vector
                temp.clear();
                // add the new number to the end of the vector
                temp.insert(temp.end(), tempSum);
            }
        }
        x++;
    }

    std::cout << "The sum of primes below "<< LIMIT << ": " << vectorSum(temp) << "\n";
}

long long int vectorSum( std::vector <long long int> inV ){
    long long int sum = 0;
    for ( int i = 0; i < inV.size(); i++ ) {
        sum += inV[i];
    }
    return sum;
}

bool isPrime(long long int n){
    // 1 & 0 are not prime
    if ( n <= 1 )
        return false;
    else if (n < 0) {
        std::cout << "n is a NEGATIVE number!!!\n";
        return false;
    }
    // check if it's not prime
    for ( long long int i = 1; i <= n; ++i ) {
        if ( (n % i == 0 ) && (i != 1) && (i < n) )
            return false;
    }
    // after loop means it's prime
    return true;
}
