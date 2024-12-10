# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        upper = 0
        answer = ListNode()
        curNode = answer
        while l1 or l2 or upper:
            if l1:
                upper += l1.val
                l1 = l1.next
            if l2:
                upper += l2.val
                l2 = l2.next

            curNode.val = upper % 10
            upper //= 10
            if l1 or l2 or upper:
                curNode.next = ListNode()
                curNode = curNode.next
        
        return answer