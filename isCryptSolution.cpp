// A cryptarithm is a mathematical puzzle for which the goal is to 
// find the correspondence between letters and digits, such that the 
// given arithmetic equation consisting of letters holds true when 
// the letters are converted to digits.
// 
// You have an array of strings crypt, the cryptarithm, and an an 
// array containing the mapping of letters and digits, solution. The 
// array crypt will contain three non-empty strings that follow the 
// structure: [word1, word2, word3], which should be interpreted as 
// the word1 + word2 = word3 cryptarithm.
// 
// If crypt, when it is decoded by replacing all of the letters in 
// the cryptarithm with digits using the mapping in solution, becomes 
// a valid arithmetic equation containing no numbers with leading 
// zeroes, the answer is true. If it does not become a valid arithmetic 
// solution, the answer is false.
// 
// Example
// 
// For crypt = ["SEND", "MORE", "MONEY"] and
// 
// solution = [['O', '0'],
//             ['M', '1'],
//             ['Y', '2'],
//             ['E', '5'],
//             ['N', '6'],
//             ['D', '7'],
//             ['R', '8'],
//             ['S', '9']]
// the output should be
// isCryptSolution(crypt, solution) = true.
// 
// When you decrypt "SEND", "MORE", and "MONEY" using the mapping given 
// in crypt, you get 9567 + 1085 = 10652 which is correct and a valid 
// arithmetic equation.
// 
// For crypt = ["TEN", "TWO", "ONE"] and
// 
// solution = [['O', '1'],
//             ['T', '0'],
//             ['W', '9'],
//             ['E', '5'],
//             ['N', '4']]
// the output should be
// isCryptSolution(crypt, solution) = false.
// 
// Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, 
// meaning that this is not a valid solution.
// 
// C++ Solution:

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    
    // Convert NumberA:
    int numberA = 0;
    // Leading zero check:
    bool isFirstCharA = true;
    
    for (std::string::size_type i = 0; i < crypt[0].size(); i++) {
        char a = crypt[0][i];
        
        // Iterate through solution:
        for (int j = 0; j < solution.size(); j++) {
        
            if (a == solution[j][0]) {
                numberA = (int)numberA*10 + (int)solution[j][1] - 48;

                if (isFirstCharA && crypt[0].size() != 1) {
                    if (solution[j][1] == '0') {
                        
                        return false;
                    }
                }
                isFirstCharA = false;
            }
        }
    }
    
    // Convert NumberB:
    int numberB = 0;
    // Leading zero check:
    bool isFirstCharB = true;
    for (std::string::size_type i = 0; i < crypt[1].size(); i++) {
        
        char b = crypt[1][i];
        // Iterate through solution:
        for (int j = 0; j < solution.size(); j++) {
            if (b == solution[j][0]) {
                numberB = (int)numberB*10 + (int)solution[j][1] - 48;
                
                if (isFirstCharB && crypt[1].size() != 1) {
                    if (solution[j][1] == '0') {
                     
                        return false;
                    }
                }
                isFirstCharB = false;
            }
        }
    }
    
    // Convert NumberC:
    int numberC = 0;
    // Leading zero check:
    bool isFirstCharC = true;
    for (std::string::size_type i = 0; i < crypt[2].size(); i++) {
        
        char c = crypt[2][i];
        // cout << c;
        // Iterate through solution:
        for (int j = 0; j < solution.size(); j++) {
            if (c == solution[j][0]) {
                numberC = (int)numberC*10 + (int)solution[j][1] - 48;
                
                if (isFirstCharC && crypt[2].size() != 1) {
                    if (solution[j][1] == '0') {
                        
                        return false;
                    }
                }
                isFirstCharC = false;
            }
        }
    }
    
    // Test if A + B = C
    if (numberA + numberB == numberC) {
        return true;
    }
    
    else return false;
}

