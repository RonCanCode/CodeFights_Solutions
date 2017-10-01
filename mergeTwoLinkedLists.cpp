// Given two singly linked lists sorted in non-decreasing order, 
// your task is to merge them. In other words, return a singly 
// linked list, also sorted in non-decreasing order, that contains 
// the elements from both original lists.
// 
// Example
// 
// For l1 = [1, 2, 3] and l2 = [4, 5, 6], the output should be
// mergeTwoLinkedLists(l1, l2) = [1, 2, 3, 4, 5, 6];
// For l1 = [1, 1, 2, 4] and l2 = [0, 3, 5], the output should be
// mergeTwoLinkedLists(l1, l2) = [0, 1, 1, 2, 3, 4, 5].
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
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {

    // Dummy first node to build resultList:
    struct ListNode<int> dummyNode;
    // Tail points to last resultNode
    struct ListNode<int> * tail = &dummyNode;
    // tail->next is where new result nodes go:
    dummyNode.next = nullptr;
    
    while (true) {
        // List one is done:
        if (l1 == nullptr) {
            tail->next = l2;
            break;
        }
        
        // List two is done:
        else if (l2 == nullptr) {
            tail->next = l1;
            break;
        }
        
        // Normal case:
        if (l1->value <= l2->value) {
            // Mode l1 to results
            struct ListNode<int> * newNode = l1;
            l1 = newNode->next;
            newNode->next = tail->next;
            tail->next = newNode;
        }
        else {
            // Move l2 to results
            struct ListNode<int> * newNode = l2;
            l2 = newNode->next;
            newNode->next = tail->next;
            tail->next = newNode;
        }
        
        // Increment tail:
        tail = tail->next;
        
    }
    
    // Return node * after dummy:
    return (dummyNode.next);
}

