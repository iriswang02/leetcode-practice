
/**********************************************************************************
*
* Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.is valid.
*
* Input: l1 = [1,2,4], l2 = [1,3,4]
* Output: [1,1,2,3,4,4]
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
  *   [Stacks]
  *
  *   Time complexity : O(n) where n is the number of nodes.
  *
  *   Space Complexity: O(1). We only used constant extra space.
  */

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        //ListNode* dummy;
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        }

        if (l2) {
            curr->next = l2;
        }

        return dummy.next;
    }
};
