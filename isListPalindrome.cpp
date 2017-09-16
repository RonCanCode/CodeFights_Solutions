// Given a singly linked list of integers, 
// determine whether or not it's a palindrome.
// 
// Example
// 
// For l = [0, 1, 0], the output should be
// isListPalindrome(l) = true;
// For l = [1, 2, 2, 3], the output should be
// isListPalindrome(l) = false.
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
bool isListPalindrome(ListNode<int> * l) {

    // Edge case:
    if (l == nullptr) {
        return true;
    }
    
    // Store values in a stack:
    std::stack<int> storageStack;
    
    // Fill the stack with values:
    for (ListNode<int> * currentNode = l;
        currentNode != nullptr;
        currentNode = currentNode -> next) {
        
        storageStack.push(currentNode -> value);
            
    }
    
    // Pop the stack and compare values:
    for (ListNode<int> * currentNode = l;
        currentNode != nullptr;
        currentNode = currentNode -> next) {
        
        int currentValue1 = storageStack.top();
        storageStack.pop();
        int currentValue2 = currentNode -> value;
        
        if (currentValue1 != currentValue2) {
            return false;
        }
            
    }
    
    return true;
}


