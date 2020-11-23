class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        head = None
        carry = 0
        sumOfDigit = 0

        while l1 or l2:

            if l1:
                sumOfDigit += l1.val
                l1 = l1.next
            if l2:
                sumOfDigit += l2.val
                l2 = l2.next
            sumOfDigit += carry
            if sumOfDigit >= 10:
                carry = 1
                sumOfDigit %= 10
            else:
                carry = 0

            if head:
                head.next = ListNode(sumOfDigit)
                head = head.next
            else:
                head = ListNode(sumOfDigit)
                result = head;
            sumOfDigit = 0

        if carry:
            head.next = ListNode(carry)
            head = head.next
        return result
