/*
 * Project Euler:
 * Prolem #13
 * Title: Large Sum
 * DESCRIPTION: Work out the first 10 digits of the sum of the following one-hundred 50-digit numbers.
 * Recursion solution
 */

#include <iostream>
#include <fstream>

std::string reverse_string (const std::string& inStr) {
    std::string temp{""};
    for (int i = inStr.size() - 1; i >= 0; i--) {
        temp += inStr[i];
    }
    return temp;
}

void sumStrings(std::string& sum,
         const std::string& n1, std::string::const_iterator& n1It,
         const std::string& n2, std::string::const_iterator& n2It,
         const int& carry,
         bool& flag)
{
    int number1{((int)(*n1It)) - 48}, number2{((int)(*n2It)) - 48};
    int sumN1N2;
    if (flag)
        sumN1N2 = number1 + 0 + carry;
    else
        sumN1N2 = number1 + number2 + carry;
    // std::cout << sumN1N2 << std::endl;
    int currentCarry = 0;
    if (sumN1N2 > 9)
        currentCarry = 1;
    char sumDigit;
    sumDigit = (char)(sumN1N2 % 10 + 48);
    sum += sumDigit;
    if (n1It == n1.begin()) {
        if (currentCarry) {
            sum += ((char)(currentCarry + 48));
        }
        return;
    }
    n1It--;
    if (n2It == n2.begin())
        flag = true;
    else
        n2It--;
    sumStrings(sum, n1, n1It, n2, n2It, currentCarry, flag);
}

int main () {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cout << "Couldn't open file!!!" << std::endl;
        return 1;
    }
    std::string line, previousLine;
    while (getline(inFile, line)) {
        if (previousLine == "") {
            previousLine += line;
            continue;
        }
        std::string sum;
        std::string::const_iterator prevLineIt = previousLine.end() - 1;
        std::string::const_iterator lineIt = line.end() - 1;
        bool short_str_stop_decrement_iterator = false;
        sumStrings(sum, previousLine, prevLineIt, line, lineIt, 0, short_str_stop_decrement_iterator);
        sum = reverse_string(sum);
        previousLine = "";
        previousLine += sum;
    }
    std::cout << previousLine << std::endl;
    std::cout << "Size of result string: " << previousLine.size() << std::endl;

    std::string ans;
    for (int i = 0; i < 10; i++) {
        ans += previousLine[i];
    }
    std::cout << "Answer: " << ans << std::endl;
    inFile.close();

  return 0;
}
