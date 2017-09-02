// Given the string, check if it is a palindrome.
//
// Example
//
// For inputString = "aabaa", the output should be
// checkPalindrome(inputString) = true;
// For inputString = "abac", the output should be
// checkPalindrome(inputString) = false;
// For inputString = "a", the output should be
// checkPalindrome(inputString) = true.

bool checkPalindrome(std::string inputString) {

    // Reverse the string:
    std::string copy(inputString);
    std::reverse(copy.begin(), copy.end());
    
    // Check char by char for match:
    if (copy == inputString) {
         return true;
    }
    
    else return false;
    
}
