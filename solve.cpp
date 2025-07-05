/*
 * Project Euler:
 * Prolem #13
 * Title: Large Sum
 * DESCRIPTION: Work out the first 10 digits of the sum of the following one-hundred 50-digit numbers.
 */

#include <iostream>
#include <fstream>

// #define NOCARRY ""
// #define CARRY "1"

enum carry {
    NOCARRY,
    CARRY
};

struct sumOP{
    int cNum;
    std::string result;
};

sumOP add_digit(const std::string& n1, const std::string& n2, const int& carry) {
    int num1{n1[0] - '0'}, num2{n2[0] - '0'}, c{0}, result{0};
    result = num1 + num2 + carry;
    // std::string result_str;
    // std::string finalResult;
    // int finalInt = result;
    // unsigned int carryNum {NOCARRY};
    // result_str = std::to_string(result);
    if (result > 9) {
        c = result / 10;
        result = result % 10;
        // carryNum = result_str[0];
        // finalInt = result_str[1] - '0';
    }
    // finalResult = std::to_string(finalInt);
    sumOP ans = {
        c,
        std::to_string(result)
    };
    return ans;
}

std::string reverse_string (const std::string& inStr) {
    std::string temp{""};
    for (int i = inStr.size() - 1; i >= 0; i--) {
        temp += inStr[i];
    }
    return temp;
}

int main () {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        std::cout << "Couldn't open file!!!" << std::endl;
        return 1;
    }

    // std::string line, sum;
    // while (getline(inFile, line)) {
    //     if (sum == "") { // For first iteration, initialize sum
    //         sum += line;
    //         std::cout << sum << std::endl;
    //         continue;
    //     }
    //     int carryNum = 0;
    //     std::string temp{""};
    //     for (int i = sum.size() - 1; i >= 0; i--) {
    //         sumOP currentSumReturn{carryNum, ""};
    //         std::string num1, num2;
    //         num1 = sum[i];
    //         num2 = line[i];
    //         currentSumReturn = add_digit(num1, num2, carryNum);
    //         carrayNum = currentSumReturn.cNum;
    //         temp += currentSumReturn.result;
    //         if (i - 1 < 0 && currentSumReturn.cNum == 1) {
    //             temp += std::to_string(currentSumReturn.cNum);
    //         }
    //     }
    //     temp = reverse_string(temp);
    //     sum.clear();
    //     sum += temp;
    //     std::cout << sum << std::endl;
    // }

    int inNum1;
    std::cin >> inNum1;
    int inNum2;
    std::cin >> inNum2;

    std::string number1{std::to_string(inNum1)}, number2{std::to_string(inNum2)};
    std::cout << "Sum of:" << std::endl;
    std::cout << "number 1: " << number1 << std::endl;
    std::cout << "number 2: "<< number2 << std::endl;
    std::string currentSum{""};
    int carry{0};
    int i = number1.size() - 1;
    int n1, n2{number2[0] - '0'};
    do {
        n1 = number1[i] - '0';
        int sum = n1 + n2 + carry;
        int remainder = sum % 10;
        n2 = remainder;
        std::string remainderStr = std::to_string(remainder);
        // std::cout << remainderStr << std::endl;
        currentSum.insert(0, remainderStr);
        if (sum > 9)
            carry = 1;
        else
            carry = 0;
        i--;
        if (i == -1 && carry == 1) {
            currentSum.insert(0, std::to_string(1));
            break;
        }
    } while (carry);
    for (int l = i; l >= 0; l--) {
        currentSum.insert(0, std::to_string(number1[l] - '0'));
    }
    std::cout << "Sum: " << currentSum << std::endl;;
    // for (int i = number1.size() - 1; i >= 0; i--) {
    //     int n1{number1[i] - '0'}, n2{number2[0] - '0'};
    //     int sum{n1 + n2 + carry};
    //     std::string sumStr = {std::to_string(sum)};
    // }

    // std::cout << "File opened !!!" << std::endl;
    // std::string n1, n2, sum;
    // n1 = "1";
    // n2 = "1";
    // // sum = add_digit(n1, n2, NOCARRY);
    // sum = add_digit(n1, n2, std::to_string(CARRY));

    // std::cout << "String integer addition:" << std::endl;
    // std::cout << "number 1: " << n1 << std::endl;
    // std::cout << "number 2: " << n2 << std::endl;
    // std::cout << "Sum: " << sum << std::endl;

    inFile.close();

  return 0;
}
