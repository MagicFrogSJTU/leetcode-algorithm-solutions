#
# @lc app=leetcode id=148 lang=python3
#
# [148] Sort List
#
# https://leetcode.com/problems/sort-list/description/
#
# algorithms
# Medium (41.32%)
# Likes:    2612
# Dislikes: 127
# Total Accepted:    259.4K
# Total Submissions: 626.1K
# Testcase Example:  '[4,2,1,3]'
#
# Sort a linked list in O(n log n) time using constant space complexity.
# 
# Example 1:
# 
# 
# Input: 4->2->1->3
# Output: 1->2->3->4
# 
# 
# Example 2:
# 
# 
# Input: -1->5->3->4->0
# Output: -1->0->3->4->5
# 
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        def func(head):
            if not head.next:
                return head, head

            small_head = small = ListNode()
            big_head = big = ListNode()
            node = head.next
            head.next = None
            end = head
            while node:
                if node.val < head.val: 
                    small.next = node
                    small = node
                elif node.val > head.val:
                    big.next = node
                    big = node
                else:
                    end.next = node
                    end = node
                
                node = node.next
            small.next = None
            big.next = None


            if small_head.next:
                h, e = func(small_head.next)
                e.next = head
                head = h
            if big_head.next:
                h, e = func(big_head.next)
                end.next = h
                end = e
            return head, end
        if not head:
            return None
        return func(head)[0]
        
# @lc code=end

