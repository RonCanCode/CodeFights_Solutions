// Ticket numbers usually consist of an even number of digits. 
// A ticket number is considered lucky if the sum of the first 
// half of the digits is equal to the sum of the second half.
// 
// Given a ticket number n, determine if it's lucky or not.
// 
// Example
// 
// For n = 1230, the output should be
// isLucky(n) = true;
// For n = 239017, the output should be
// isLucky(n) = false.
// 
// C++ Solution:

bool isLucky(int n) {

    string nStr = to_string(n);
    
    // Store each half:
    string lStr;
    string rStr;
    for (int i = 0; i < nStr.length()/2; i++) {
        lStr += nStr[i];
    }
    for (int j = nStr.length()/2; j < nStr.length(); j ++) {
        rStr += nStr[j];
    }
    
    // Calculate each half:
    int lNum = 0;
    int rNum = 0;
    for (int i = 0; i < lStr.length(); i++) {
        lNum += (int)(lStr[i]) - 48;
    }
    for (int j = 0; j < rStr.length(); j++) {
        rNum += (int)(rStr[j]) - 48;
    }
    
    // Check if equal:
    if (lNum == rNum) {
        return true;
    }
    else return false;
}

