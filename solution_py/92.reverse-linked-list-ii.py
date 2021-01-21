#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#
# https://leetcode.com/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (37.68%)
# Likes:    2170
# Dislikes: 137
# Total Accepted:    263.7K
# Total Submissions: 690.6K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# Reverse a linked list from position m to n. Do it in one-pass.
#
# Note: 1 ≤ m ≤ n ≤ length of list.
#
# Example:
#
#
# Input: 1->2->3->4->5->NULL, m = 2, n = 4
# Output: 1->4->3->2->5->NULL
#
#
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        e1 = dummy_node = ListNode()
        dummy_node.next = head
        for i in range(m-1):
            e1 = e1.next
        left = e1.next
        right = left.next
        for i in range(n - m):
            buf = right.next
            right.next = left
            left = right
            right = buf
        e1.next.next = right
        e1.next = left
        return .next




# @lc code=end

