// Given a string s, find and return the first instance of a non-repeating 
// character in it. If there is no such character, return '_'.
// 
// Example
// 
// For s = "abacabad", the output should be
// firstNotRepeatingCharacter(s) = 'c'.
// 
// There are 2 non-repeating characters in the string: 'c' and 'd'. 
// Return c since it appears in the string first.
// 
// For s = "abacabaabacaba", the output should be
// firstNotRepeatingCharacter(s) = '_'.
// 
// There are no characters in this string that do not repeat.

char firstNotRepeatingCharacter(std::string s) {

    // Character array:
    int arr[128];

    // Fill array (only lower-case):
    for(int i=97; i<128; i++) {
        arr[i] = -1;
    }

    // Cast s[i] as int and account for it:
    for(int i=0; i < s.length(); i++) {

        arr[ (int)s[i] ] += 1;
    }

    // Return first instance of non-repeat:
    for(int i=0; i < s.length(); i++) {

        if( arr[ (int)s[i] ] == 0) {

            return s[i];
        }

    }
    
return '_';
    
}


