#
# @lc app=leetcode id=129 lang=python3
#
# [129] Sum Root to Leaf Numbers
#
# https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
#
# algorithms
# Medium (46.82%)
# Likes:    1225
# Dislikes: 39
# Total Accepted:    243.6K
# Total Submissions: 520.2K
# Testcase Example:  '[1,2,3]'
#
# Given a binary tree containing digits from 0-9 only, each root-to-leaf path
# could represent a number.
# 
# An example is the root-to-leaf path 1->2->3 which represents the number 123.
# 
# Find the total sum of all root-to-leaf numbers.
# 
# Note: A leaf is a node with no children.
# 
# Example:
# 
# 
# Input: [1,2,3]
# ⁠   1
# ⁠  / \
# ⁠ 2   3
# Output: 25
# Explanation:
# The root-to-leaf path 1->2 represents the number 12.
# The root-to-leaf path 1->3 represents the number 13.
# Therefore, sum = 12 + 13 = 25.
# 
# Example 2:
# 
# 
# Input: [4,9,0,5,1]
# ⁠   4
# ⁠  / \
# ⁠ 9   0
# / \
# 5   1
# Output: 1026
# Explanation:
# The root-to-leaf path 4->9->5 represents the number 495.
# The root-to-leaf path 4->9->1 represents the number 491.
# The root-to-leaf path 4->0 represents the number 40.
# Therefore, sum = 495 + 491 + 40 = 1026.
# 
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.result = 0
        def func(root, val):
            if not root:
                return
            current = val*10 + root.val
            if not (root.left or root.right):
                self.result += current
                return
            func(root.left, current) 
            func(root.right, current)
        func(root, 0)
        return self.result

        
# @lc code=end

