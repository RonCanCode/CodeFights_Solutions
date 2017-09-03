// Below we will define an n-interesting polygon. 
// Your task is to find the area of a polygon for a given n.
// 
// A 1-interesting polygon is just a square with a side of length 1. 
// An n-interesting polygon is obtained by taking the n - 1-interesting 
// polygon and appending 1-interesting polygons to its rim, side by side. 
// You can see the 1-, 2-, 3- and 4-interesting polygons in the picture below.

// Recursive process:
// n = 1 —> 1
// n = 2 —> 1 + 4 = 5
// n = 3 —> 5 + 8 = 13 = ([f(n - 1)] + ( ((n)*2) + ((n-2)*2) ) = 5 + 6 + 2 = 13
// n = 4 —> 13 + 12 = 25 = ([f(n - 1)] + ( ((n)*2) + ((n-2)*2) ) = 13 + 8 + 4 = 25
// n = 5 —> 25 + 16 = 41 = ([f(n - 1)] + ( ((n)*2) + ((n-2)*2) ) = 25 + 10 + 6 =  41
// n = 6 —> etc…

// ([f(n - 1)] + ( ((n)*2) + ((n-2)*2) )

// C++ Solution:

int shapeArea(int n) {
    
    int area = 0;
    
    // Recursive base case:
    if ( n == 1 ) {
        area = 1;
        return area;
    }
    else {
        area = shapeArea(n - 1) + (n*2) + ((n-2)*2);
        return area;
    }
}

