// Given an array of strings, return another array containing 
// all of its longest strings.
// 
// Example
// 
// For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the 
// output should be
// allLongestStrings(inputArray) = ["aba", "vcd", "aba"].
// 
// C++ Solution:

std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {

    int longestLength = 0;
    
    for (int i = 0; i < inputArray.size(); i++) {
        string currentStr = inputArray[i];
        int currentLng = currentStr.length();
        if (currentLng > longestLength) {
            longestLength = currentLng;
        }
    }
    
    vector<string> returnVec;
    
    for (int j = 0; j < inputArray.size(); j++) {
        string currentStr = inputArray[j];
        if (currentStr.length() == longestLength) {
            returnVec.push_back(currentStr);
        }
    }
    
    return returnVec;
    
}

