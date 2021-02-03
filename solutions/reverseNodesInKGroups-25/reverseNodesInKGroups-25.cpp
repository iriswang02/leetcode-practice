
/**********************************************************************************
*
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
* Input: head = [1,2,3,4,5], k = 3
* Output: [3,2,1,4,5]
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
  *   [Recursion]
  *
  *   Time complexity : O(n). 
  *
  *   Space Complexity: O(logN). 
  */

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* a = head;
        ListNode* b = head;
        for (int i=0; i<k; i++) {
            if (b==NULL) {
                return head;
            }
            b = b->next;
        }
        
        ListNode* newHead = reverse(a, b);
        
        a->next = reverseKGroup(b, k);
        return newHead;
        
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;
        
        while(curr != tail) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
};