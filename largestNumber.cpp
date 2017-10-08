// Given an integer n, return the largest 
// number that contains exactly n digits.
// 
// Example
// 
// For n = 2, the output should be
// largestNumber(n) = 99.
// 
// C++ Solution:

int largestNumber(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result*10 + 9;
    }
    return result;
}

