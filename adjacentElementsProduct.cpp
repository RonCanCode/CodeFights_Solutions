// Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.
// 
// Example
//
// For inputArray = [3, 6, -2, -5, 7, 3], the output should be
// adjacentElementsProduct(inputArray) = 21.
// 
// 7 and 3 produce the largest product.
// 
// C++ Solution:

int adjacentElementsProduct(std::vector<int> inputArray) {

    // Store the winner:
    int biggestElementProduct = -1001;
    
    // Get array length and loop through array:
    for (int i = 0; i < inputArray.size() - 1; i++) {
        int firstNum = inputArray[i];
        int secondNum = inputArray[i+1];
        int currentProd = firstNum * secondNum;
        
        // Check if current product is biggest:
        if (currentProd > biggestElementProduct) {
            biggestElementProduct = currentProd;
        }
    }
    
    return biggestElementProduct;
    
}

