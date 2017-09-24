// Given a sequence of integers as an array, determine whether it is 
// possible to obtain a strictly increasing sequence by removing no 
// more than one element from the array.
// 
// Example
// 
// For sequence = [1, 3, 2, 1], the output should be
// almostIncreasingSequence(sequence) = false;
// 
// There is no one element in this array that can be removed in order 
// to get a strictly increasing sequence.
// 
// For sequence = [1, 3, 2], the output should be
// almostIncreasingSequence(sequence) = true.
// 
// You can remove 3 from the array to get the strictly increasing 
// sequence [1, 2]. Alternately, you can remove 2 to get the strictly 
// increasing sequence [1, 3].
// 
// C++ Solution:

bool almostIncreasingSequence(std::vector<int> sequence) {

    // Iterate through sequence.size():
    for (int i = 0; i < sequence.size(); i++) {
        std::vector<int> temporary;
        temporary = sequence;
        temporary.erase(temporary.begin() + i);
        
        // Special edge case:
        if (temporary.size() == 1) {
            return true;
        }
        
        // Normal check:
        for (int j = 1; j < temporary.size(); j++) {
            bool tempFlag = true;
            if (temporary[j] <= temporary[j - 1]) {
                tempFlag = false;
            }
            if (tempFlag == false) {
                j = temporary.size() + 100;
            }
            if ( tempFlag == true && j == temporary.size() - 1) {
                return true;
            }
        }
    }
    return false;
}

