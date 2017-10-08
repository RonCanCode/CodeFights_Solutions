// Given two strings, find the number of common characters between them.
// 
// Example
// 
// For s1 = "aabcc" and s2 = "adcaa", the output should be
// commonCharacterCount(s1, s2) = 3.
// 
// Strings have 3 common characters - 2 "a"s and 1 "c".
//
// C++ Solution:

int commonCharacterCount(std::string s1, std::string s2) {

    std::vector<int> countVec;
    for (int n = 0; n < 256; n++) {
        countVec.push_back(0);
    }
    
    int returnNum = 0;
    
    for (int i = 0; i < s1.length(); i++) {
        countVec[( (int)s1.at(i) )] += 1;
    }
    
    for (int j = 0; j < s2.length(); j++) {
        if (countVec[((int)s2.at(j) )] > 0) {
            returnNum += 1;
            countVec[((int)s2.at(j))] -= 1;
        }
    }
    
    return returnNum;
}

