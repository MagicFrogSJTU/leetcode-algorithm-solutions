#
# @lc app=leetcode id=86 lang=python3
#
# [86] Partition List
#
# https://leetcode.com/problems/partition-list/description/
#
# algorithms
# Medium (40.19%)
# Likes:    1182
# Dislikes: 288
# Total Accepted:    209.3K
# Total Submissions: 513.9K
# Testcase Example:  '[1,4,3,2,5,2]\n3'
#
# Given a linked list and a value x, partition it such that all nodes less than
# x come before nodes greater than or equal to x.
#
# You should preserve the original relative order of the nodes in each of the
# two partitions.
#
# Example:
#
#
# Input: head = 1->4->3->2->5->2, x = 3
# Output: 1->2->2->4->3->5
#
#
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# @lc code=start
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        small_head = small_end = ListNode(None)
        big_head = big_end = ListNode(None)
        while head is not None:
            if head.val < x:
                small_end.next = head
                small_end = small_end.next
            else:
                big_end.next = head
                big_end = big_end.next
            head = head.next
        small_end.next = big_head.next
        big_end.next = None
        return small_head.next



# @lc code=end
def get_list(nums):
    null_head = ListNode()
    end = null_head
    for n in nums:
        end.next = ListNode(n)
        end = end.next
    return null_head.next
def print_list(head):
    i = 0
    while head:
        if i > 20:
            break
        i += 1
        print(head.val)
        head = head.next

inputs = [1,4,3,2,5,2]
a = Solution().partition(get_list(inputs), 3)
print_list(a)

