// Sudoku is a number-placement puzzle. The objective is to fill 
// a 9 × 9 grid with numbers in such a way that each column, each 
// row, and each of the nine 3 × 3 sub-grids that compose the grid 
// all contain all of the numbers from 1 to 9 one time.
// 
// Implement an algorithm that will check whether the given grid 
// of numbers represents a valid Sudoku puzzle according to the 
// layout rules described above. Note that the puzzle represented 
// by grid does not have to be solvable.
//
// Example
// 
// For
// 
// grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
//         ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
//         ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
//         ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
//         ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
//         ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
//         ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
// the output should be
// sudoku2(grid) = true;
// 
// For
// 
// grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
//         ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
//         ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
//         ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
//         ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
//         ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
//         ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
//         ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
// the output should be
// sudoku2(grid) = false.
// 
// The given grid is not correct because there are two 1s in the 
// second column. Each column, each row, and each 3 × 3 subgrid 
// can only contain the numbers 1 through 9 one time.
// 
// C++ Solution:

bool sudoku2(std::vector<std::vector<char>> grid) {

    // Always 9 x 9
    int size = 9;
    
    // FIRST, CHECK EACH ROW:

    for (int r1 = 0; r1 < size ; r1++) {
        
        // Store whether a #'s been seen:
        std::vector<int> beenSeen1(256,0);
        
        // Iterate through cols:
        for (int c1 = 0; c1 < size - 1; c1++) {
            
            if (grid[r1][c1] != '.') {
                beenSeen1[(int)grid[r1][c1]] += 1;
            }
        }
        
        // Check for duplicates:
        for (int i1 = 0; i1 < beenSeen1.size(); i1++) {
            if (beenSeen1[i1] > 1) {
                return false;
            }
        }
        
    }
    
    // THEN CHECK EACH COL:

      for ( int c2 = 0; c2 < size ; c2++) {
        
        // Store whether #'s been seen:
        std::vector<int> beenSeen2(256,0);
        
        // Iterate through cols:
        for (int r2 = 0; r2 < size - 1; r2++) {
            
            if (grid[r2][c2] != '.') {
                beenSeen2[(int)grid[r2][c2]] += 1;
            }
        }
        
        // Check for duplicates:
        for (int i2 = 0; i2 < beenSeen2.size(); i2++) {
            if (beenSeen2[i2] > 1) {
                return false;
            }
        }
        
    }
    
    // THEN CHECK EACH QUADRANT:
    
    // Outer loops:
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            // index r = r + x*3
            // index c = c + y*3
            
            // Inner loops:
            std::vector<int> beenSeen3(256,0);
            
            for (int r3 = 0; r3 < 3; r3++) {
                for (int c3 = 0; c3 < 3; c3++) {
                    if (grid[r3 + x*3][c3 + y*3] != '.') {
                        beenSeen3[(int)grid[r3 + x*3][c3 + y*3]] += 1;
                    }
                }
            }
            
            // Check for duplicates:
            for (int i3 = 0; i3 < beenSeen3.size(); i3++) {
                if (beenSeen3[i3] > 1) {
                return false;
                }
            }
        }
    }

    
    return true;
}


