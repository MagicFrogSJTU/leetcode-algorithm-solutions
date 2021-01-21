#
# @lc app=leetcode id=147 lang=python3
#
# [147] Insertion Sort List
#
# https://leetcode.com/problems/insertion-sort-list/description/
#
# algorithms
# Medium (40.55%)
# Likes:    582
# Dislikes: 567
# Total Accepted:    181.3K
# Total Submissions: 446.5K
# Testcase Example:  '[4,2,1,3]'
#
# Sort a linked list using insertion sort.
# 
# 
# 
# 
# 
# A graphical example of insertion sort. The partial sorted list (black)
# initially contains only the first element in the list.
# With each iteration one element (red) is removed from the input data and
# inserted in-place into the sorted list
# 
# 
# 
# 
# 
# Algorithm of Insertion Sort:
# 
# 
# Insertion sort iterates, consuming one input element each repetition, and
# growing a sorted output list.
# At each iteration, insertion sort removes one element from the input data,
# finds the location it belongs within the sorted list, and inserts it
# there.
# It repeats until no input elements remain.
# 
# 
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
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        null_head = ListNode(float("-inf"), next=head)
        res = head.next
        head.next = None
        while res is not None:
            node = res
            res = res.next
            work = null_head
            while work.next is not None:
                if work.next.val >= node.val:
                    node.next = work.next
                    work.next = node
                    break
                work = work.next
            if work.next is None:
                work.next = node
                node.next = None
        return null_head.next
        
# @lc code=end

