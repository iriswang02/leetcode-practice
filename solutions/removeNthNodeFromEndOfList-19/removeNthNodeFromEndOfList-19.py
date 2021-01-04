# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:

        curr = head
        l = 0
        while curr:
            curr = curr.next
            l += 1
        if l == 1:
            return None

        steps = l-n-1
        if steps == -1:
            head = head.next
            return head
        curr = head
        while steps>0:
            curr = curr.next
            steps -= 1

        to_delete_node = curr.next
        curr.next = to_delete_node.next

        return head
