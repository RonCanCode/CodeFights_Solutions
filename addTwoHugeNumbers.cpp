// You're given 2 huge integers represented by linked lists. Each linked 
// list element is a number from 0 to 9999 that represents a number with 
// exactly 4 digits. The represented number might have leading zeros. 
// Your task is to add up these huge integers and return the result in 
// the same format.
// 
// Example
// 
// For a = [9876, 5432, 1999] and b = [1, 8001], the output should be
// addTwoHugeNumbers(a, b) = [9876, 5434, 0].
// 
// Explanation: 987654321999 + 18001 = 987654340000.
// 
// For a = [123, 4, 5] and b = [100, 100, 100], the output should be
// addTwoHugeNumbers(a, b) = [223, 104, 105].
// 
// Explanation: 12300040005 + 10001000100 = 22301040105.
// 
// C++ Solution:


// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {

    // Store 1st list in a stack:
    std::stack<int> firstStack;
    for ( ListNode<int> * currentNode = a;
         currentNode != nullptr;
         currentNode = currentNode -> next) {

        firstStack.push(currentNode -> value);
        
    }
    
    // Store 2nd list in a stack:
    std::stack<int> secondStack;
    for ( ListNode<int> * currentNode = b;
         currentNode != nullptr;
         currentNode = currentNode -> next) {

        secondStack.push(currentNode -> value);
        
    }
    
    // Pop both, add and keep track of carries.
    // Store result in another stack...
    int carry = 0;
    std::stack<int> resultStack;
    while (!firstStack.empty() && !secondStack.empty()) {
        int currentNum = firstStack.top() + secondStack.top();
        firstStack.pop(); secondStack.pop();
        currentNum += carry;
        carry = 0;
        if (currentNum > 9999) {
            currentNum -= 10000;
            carry = 1;
        }
        resultStack.push(currentNum);
        // Test Print:
        cout << 'a' << currentNum;
        cout << '\n';
    }
    
    // Check if firstStack still has elements:
    while (!firstStack.empty()) {
        int currentNum = firstStack.top();
        firstStack.pop();
        currentNum += carry;
        carry = 0;
        if (currentNum > 9999) {
            currentNum -= 10000;
            carry = 1;
        }
        resultStack.push(currentNum);
        // Test Print:
        cout << 'x' << currentNum;
        cout << '\n';
    }
    
    // Check if secondStack still has elements:
    while (!secondStack.empty()) {
        int currentNum = secondStack.top();
        secondStack.pop();
        currentNum += carry;
        carry = 0;
        if (currentNum > 9999) {
            currentNum -= 10000;
            carry = 1;
        }
        resultStack.push(currentNum);
        // Test Print:
        cout << 'y' << currentNum;
        cout << '\n';
    }
    
    // Carry edge case:
    if (carry == 1) {
        int currentNum = 1;
        resultStack.push(currentNum);
        // Test Print:
        cout << 'e' << currentNum;
        cout << '\n';
    }
    
    // Built new linked list for return:
    ListNode<int> * currentNode = a;
    while (!resultStack.empty()) {
        if (currentNode -> next != nullptr) {
            currentNode -> value = resultStack.top();
            resultStack.pop();
            currentNode = currentNode -> next;
        }
        else {
            ListNode<int> * newNode;
            newNode = (struct ListNode<int>*)malloc(sizeof(struct ListNode<int>));
            currentNode -> next = newNode;
            newNode -> next = nullptr;
            currentNode -> value = resultStack.top();
            resultStack.pop();
            // Edge for end of list:
            if (resultStack.empty()) {
                currentNode -> next = nullptr;
            }
            currentNode = currentNode -> next;
        }
        
        // Return result at end:
        if (resultStack.empty()) {
            return a;
        }
    }
}

