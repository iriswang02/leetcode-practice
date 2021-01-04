
/**********************************************************************************
*
* Given the head of a linked list, remove the nth node from the end of the list and return its head.
*
* Input: head = [1,2,3,4,5], n = 2
* Output: [1,2,3,5]
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
  *   [Two Pointers One Pass]
  *
  *   Time complexity : O(L). The algorithm makes one traversal of the list of L nodes.
  *
  *   Space Complexity: O(1). We only used constant extra space.
  */

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head->next) {
            return nullptr;
        }

        ListNode* first = head, *second = head;
        while (n--) {
            first = first->next;
        }
        if (!first) {
            head = head->next;
        } else {
            while (first->next) {
                first = first->next;
                second = second->next;
            }
            second->next = second->next->next;
        }
        return head;
    }
};
