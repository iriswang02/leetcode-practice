
/**********************************************************************************
*
* You are given two non-empty linked lists representing two non-negative integers.
*
* The digits are stored in reverse order, and each of their nodes contains a single digit.
* Add the two numbers and return the sum as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
* Input: l1 = [2,4,3], l2 = [5,6,4]
* Output: [7,0,8]
*
*
**********************************************************************************/

class Solution {

  /*
  *   [Elementary Math]
  *
  *   Time complexity : O(max(m,n)). Assume that mm and nn represents the length of l1 and l2 respectively,
  *   the algorithm above iterates at most max(m,n) times.
  *
  *   Space complexity : O(max(m,n)). The length of the new list is at most max(m,n)+1.
  */

public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* head = NULL;
    ListNode* result = NULL;
    int carry = 0;
    int sumOfDigit = 0;
    while(l1 != NULL || l2 != NULL) {

        if(l1 != NULL) {
            sumOfDigit += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sumOfDigit += l2->val;
            l2 = l2->next;
        }
        sumOfDigit += carry;
        if(sumOfDigit >= 10) {
            carry = 1;
            sumOfDigit %= 10;
        } else {
            carry = 0;
        }

        ListNode* newNode = new ListNode(sumOfDigit);
        if (head) {
            head->next = newNode;
            head = head->next;
        } else {
            head = newNode;
            result = head;
        }
        sumOfDigit = 0;
    }

    if (carry != 0) {
        ListNode* firstDigit = new ListNode(1);
        head->next = firstDigit;
        head = head->next;
    }
    return result;
  }

};
