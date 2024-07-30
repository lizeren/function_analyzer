#include <iostream>
#include <vector>
#include "add.h"
#include "basicblock.h"

// Function with multiple conditional branches
int maxOfThree(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b > c) {
            return b;
        } else {
            return c;
        }
    }
}

// Function with a loop and early exit
int findFirstNegative(const std::vector<int>& vec) {
    for (std::vector<int>::size_type i = 0; i < vec.size(); ++i) {  // Changed 'int' to 'std::vector<int>::size_type'
        if (vec[i] < 0) {
            return i; // Early exit
        }
    }
    return -1; // Indicate not found
}


// Function with nested loops
int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
        }
    }
    return count;
}

// Main function to execute the above functions
int main() {
    int result = maxOfThree(10, 20, 30);
    std::cout << "Max of 10, 20, 30 is: " << result << std::endl;

    std::vector<int> numbers = {1, 2, 3, -4, 5};
    int firstNegativeIndex = findFirstNegative(numbers);
    std::cout << "First negative index: " << firstNegativeIndex << std::endl;

    int primeCount = countPrimes(10);
    std::cout << "Number of primes up to 10: " << primeCount << std::endl;

    add(1,2);

    return 0;
}

