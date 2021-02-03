
/**********************************************************************************
*
* Given a linked list, swap every two adjacent nodes and return its head.
*
* Input: head = [1,2,3,4]
* Output: [2,1,4,3]
*
*
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {

  /*
  *   [Normal LinkedList Operation]
  *
  *   Time complexity : O(n).
  *
  *   Space Complexity: O(1).
  */

public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode dummy;
        dummy.next = head;
        
        ListNode* curr = &dummy;
        while(curr->next && curr->next->next) {
            
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            
            first->next = second->next;
            second->next = first;
            curr->next = second;
            curr = first;
        }
        
        return dummy.next;
    }
};