// Given a singly linked list of integers l and an integer k, 
// remove all elements from list l that have a value equal to k.
// 
// Example
// 
// For l = [3, 1, 2, 3, 4, 5] and k = 3, the output should be
// removeKFromList(l, k) = [1, 2, 4, 5];
// For l = [1, 2, 3, 4, 5, 6, 7] and k = 10, the output should be
// removeKFromList(l, k) = [1, 2, 3, 4, 5, 6, 7].
// 
// C++ Solution:

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {

    // Store the previous node's next value:
    ListNode<int> ** previousNodesNext = &l;
    
    // Iterate through the linked list:
    for ( ListNode<int> * currentNode = l;
        currentNode != nullptr;
        currentNode = currentNode -> next) {
        
        if (currentNode -> value == k) {
            *previousNodesNext = currentNode -> next;
        }
        else {
            previousNodesNext = &currentNode -> next;
        }
        
    }
    
    return l;
}


