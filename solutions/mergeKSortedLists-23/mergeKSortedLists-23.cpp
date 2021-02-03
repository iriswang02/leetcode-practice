
/**********************************************************************************
*
* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
*
* Input: lists = [[1,4,5],[1,3,4],[2,6]]
* Output: [1,1,2,3,4,4,5,6]
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
    *   [Merge with Divide And Conquer]
    *
    *   Time complexity : O(Nlogk) where \text{k}k is the number of linked lists
    *
    *   Space Complexity: O(1).
    */

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if (n == 0) {
            return nullptr;
        // } else if (n == 1) {
        //     return lists[0];
        } else {
            // ListNode* head = mergeTwoLists(lists[0], lists[1]);
            // for (int i=2; i<n; i++) {
            //     head = mergeTwoLists(lists[i], head);
            // }
            int interval = 1;
            while (interval < n) {
                for (int i=0; i<n-interval; i+=interval*2) {
                    lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
                }
                interval *= 2;
            }
            return lists[0];
        }
    }
    
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