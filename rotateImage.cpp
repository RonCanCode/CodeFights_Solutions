// Note: Try to solve this task in-place (with O(1) additional memory), 
// since this is what you'll be asked to do during an interview.
// 
// You are given an n x n 2D matrix that represents an image. 
// Rotate the image by 90 degrees (clockwise).
// 
// Example
// 
// For
// 
// a = [[1, 2, 3],
//      [4, 5, 6],
//      [7, 8, 9]]
// the output should be
// 
// rotateImage(a) =
//     [[7, 4, 1],
//      [8, 5, 2],
//      [9, 6, 3]]
// 
// C++ Solution:

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    
    // Guaranteed to be square, 
    // so row.size and col.size
    // both == vectSize:
    int vectSize = a.size();
    
    // Create new 'return' vector:
    std::vector<std::vector<int>> returnVec;
    
    // Allocate memory for return vector:
    returnVec = a;
    
    // Outer loop for 'cols' of input:
    for (int c = 0; c < vectSize; c++) {
        
        // Incrementing output vec index ++:
        int colCount = 0;
        
        // Inner loop for 'rows' of input:
        for (int r = vectSize - 1; r > -1; r--) {
            // Get current value:
            int current = a[r][c];
            // Put it into new vec:
            returnVec[c][colCount] = current;
            // Increment output col index:
            colCount++;
        }
    }
    
    return returnVec;
  
}

