// You are given a two-digit integer n. 
// Return the sum of its digits.
// 
// Example
// 
// For n = 29, the output should be
// addTwoDigits(n) = 11.
// 
// C++ Solution:

int addTwoDigits(int n) {
    int tensPlace = n/10;
    int onesPlace = n%10;
    return tensPlace + onesPlace;
}

