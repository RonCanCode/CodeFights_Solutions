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

ListNode<int> * removeKFromList(ListNode<int> * l, int k) {

    // *1 is a pointer to start of list.
    // **previousNextVal is a pointer
    // pointing to the address of that pointer.
    ListNode<int> ** previousNextVal = &l;
    
    for( ListNode<int> * current = l;
        current != nullptr; 
        current = current -> next ) {
        
            if( current -> value == k ) {
                // Replace pointer of previous node:
                *previousNextVal = current -> next;
            }
            else {
                // Change address of variable '* current'
                previousNextVal = &current -> next;
        }
    }
    
    return l;
}

