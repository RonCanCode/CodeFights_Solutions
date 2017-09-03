// Given an array a that contains only numbers in the range from 1 to a.length, 
// find the first duplicate number for which the second occurrence has the 
// minimal index. In other words, if there are more than 1 duplicated numbers, 
// return the number for which the second occurrence has a smaller index than 
// the second occurrence of the other number does. If there are no such elements, 
// return -1.
// 
// Example
// 
// For a = [2, 3, 3, 1, 5, 2], the output should be
// firstDuplicate(a) = 3.
// 
// There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller 
// index than than second occurrence of 2 does, so the answer is 3.
// 
// For a = [2, 4, 3, 5, 1], the output should be
// firstDuplicate(a) = -1.

int firstDuplicate(std::vector<int> a) {
    
    int duplicate = -1;
    int numHops = 10^5 + 1;
    
    // iterate through array and test for duplicates:
    for (int i = 0; i < a.size(); i++) {
        int currentNum = a[i];
        
        // inner loop:
        for (int n = i + 1; n < a.size(); n++) {
            int nextNum = a[n];
            
            // check for match:
            if ( (nextNum == currentNum) && (n < numHops) ) {
                duplicate = nextNum;
                numHops = n;
            }
        }
    }

    return duplicate;
}

