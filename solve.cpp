/*
 * Project Euler:
 * Prolem #12
 * Title: Highly Divisible Triangular Number
 * DESCRIPTION: What is the value of the first triangle number to have over 500 divisors (factors)?
 */

#include <iostream>
#include <vector>
#include <map>

int getTriNum (int n) {
    return (n * (n + 1)) / 2;
}

bool foundTNum{false};
int ans{0};

bool checkExistenceMap (const int& inNum, const std::map<int, std::vector<int>>& inMap) {
    if (inMap.find(inNum) != inMap.end()) {
        return true;
    }
    return false;
}

bool checkExistenceVector (const int& inNum, const std::vector<int>& inVector) {
    bool result{false};
    for (auto i : inVector) {
        if (i == inNum) {
            result = true;
            break;
        }
    }
    return result;
}

std::vector<int> getVector (const int& n, const std::map<int, std::vector<int>>& inMap) {
    std::vector<int> result{};
    for (int i = 1; i <= n; i++) {
        // Check if the key exist in the map
        // If it is, save into result
        if (checkExistenceMap(i, inMap) && !checkExistenceVector(i, result) && n % i == 0) { // check the map
            auto valueIterator = inMap.find(i);
            for (const auto& l : valueIterator->second ) {
                result.push_back(l);
            }
            continue;
        }
        // Check if i is in result
        bool inVec{false};
        for (const auto& j : result) {
            if (i == j) {
                inVec = true;
                break;
            }
        }
        // if i is in result skip
        if (inVec)
            continue;
        // else save into result
        if (n % i == 0) {
            result.push_back(i);
        }
    }
    // for (int i = n ; i > 0; i--) {
    //     // Check if the key exist in the map
    //     // If it is, save into result
    //     if (checkExistenceMap(i, inMap) && !checkExistenceVector(i, result) && n % i == 0) { // check the map
    //         auto valueIterator = inMap.find(i);
    //         for (const auto& l : valueIterator->second ) {
    //             result.push_back(l);
    //         }
    //         // if (checkExistenceVector(i, valueIterator->second)) { // check the vector

    //         // }
    //         continue;
    //     }
    //     // Check if i is in result
    //     bool inVec{false};
    //     for (const auto& j : result) {
    //         if (i == j) {
    //             inVec = true;
    //             break;
    //         }
    //     }
    //     // if i is in result skip
    //     if (inVec)
    //         continue;
    //     // else save into result
    //     if (n % i == 0) {
    //         result.push_back(i);
    //     }
    // }
    return result;
}

void procedure(const int& inNum, std::map<int, std::vector<int>>& inMap) {
    std::vector<int> tempVec{};
    tempVec = {};
    // inNum = getTriNum(j);
    if (!checkExistenceMap(inNum, inMap)) {
        tempVec = getVector(inNum, inMap);
        // std::cout << tempVec.size() << std::endl;
        if ((int)tempVec.size() == 500) {
            foundTNum = true;
            ans = inNum;
            return;
        }
        inMap[inNum] = tempVec;
    }
}

int main () {


    // for (int i = 1; i <= limit; i++) {
    //     int currentTriNum{getTriNum(i)};
    //     map_triNum_factorArray[currentTriNum] = getVector(currentTriNum);
    // }

    // for (int i = 1, j = limit / 2 + 1; i <= limit / 2; i++, j++) {
    //     int triNum1stHalf{getTriNum(i)};
    //     int triNum2ndHalf{getTriNum(j)};
    //     map_triNum_factorArray[triNum1stHalf] = getVector(triNum1stHalf);
    //     map_triNum_factorArray[triNum2ndHalf] = getVector(triNum2ndHalf);
    // }

    std::cout << "Finding triangular numbers and their factors..." << std::endl;

    int limit{10};
    std::map<int, std::vector<int>> map_triNum_factorArray;
    std::map<int, int> vectorSizesMap;
    int map_key_with_largest_size{0};
    bool resultFound(false);
    int mmm{1};
    while (!resultFound) {
        std::cout << "Current limit: " << limit << std::endl;
        /*Fill the vector map*/
        // Find the largest factor of limit
        // int factorLimit = 1;
        // for (int i = 1; i <= limit; i++) {
        //     if (limit % i == 0 && i % 2 == 0 && i != limit && i > factorLimit)
        //         factorLimit = i;
        // }
        // std::cout << factorLimit << std::endl;
        int totalProcedures = 10 * mmm;
        // if (limit > 1000)
        //     totalProcedures = 10 * 2;
        int totalIteration = limit / totalProcedures;

        std::vector<int> startingIndices;
        for (int i = 1; i <= totalProcedures; i++) {
            int temp = totalProcedures * (i - 1) + 1;
            startingIndices.push_back(temp);
        }
        for (int i = 0; i < totalIteration; i++) {
            std::cout << i;
            int ccc{0};
            for (auto& j : startingIndices) {
                ccc++;
                std::cout << " " << ccc;
                int tempTriNum;
                tempTriNum = getTriNum(j);
                procedure(tempTriNum, map_triNum_factorArray);
                if (foundTNum)
                    break;
                j++;
            }
            std::cout << std::endl;
            if (foundTNum)
                break;
        }
        // int halfLimit = limit / 2;
        // int j;
        // for (int i = 1, j = i + halfLimit; i <= halfLimit; i++, j++) {
        //     int triNum1, triNum2;
        //     triNum1 = getTriNum(i);
        //     procedure(triNum1, map_triNum_factorArray);
        //     triNum2 = getTriNum(j);
        //     procedure(triNum2, map_triNum_factorArray);
        //     if (foundTNum) {
        //         break;
        //     }
        // }
        if (foundTNum) {
            break;
        }
        // // Fill the Vector sizes map
        // for (const auto& i : map_triNum_factorArray) {
        //     bool exist{false};
        //     for (const auto& j : vectorSizesMap) {
        //         if (i.second.size() == j.second) {
        //             exist = true;
        //             break;
        //         }
        //     }
        //     if (!(vectorSizesMap.find(i.first) != vectorSizesMap.end()) && !exist) {
        //         vectorSizesMap[i.first] = (int)i.second.size();
        //     }
        // }
        // int max{vectorSizesMap[1]};
        // int tNum;
        // for (const auto& i : vectorSizesMap) {
        //     if (i.second > max) {
        //         tNum = i.first;
        //         max = i.second;
        //     }
        // }

        // if (max >= 500) {
        //     std::cout << "1st Triangular number with largest size: " << tNum << std::endl;
        //     std::cout << "size: " << max << std::endl;
        //     break;
        // }
        limit *= 10;
        mmm++;
    }

    std::cout << "Found the Numbers!!!" << std::endl;

    if (foundTNum) {
        std::cout << "Ans: " << ans << std::endl;
    }
    // std::cout << "Print map:\n";
    // for (const auto& i : map_triNum_factorArray) {
    //     std::cout << "[" << i.first << "] =";
    //     for (const auto& j : i.second) {
    //         std::cout << " " << j;
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "vectorSizesMap's sizes:\n";

    return 0;
}
