#
# @lc app=leetcode id=110 lang=python3
#
# [110] Balanced Binary Tree
#
# https://leetcode.com/problems/balanced-binary-tree/description/
#
# algorithms
# Easy (42.79%)
# Likes:    2108
# Dislikes: 160
# Total Accepted:    437.1K
# Total Submissions: 1M
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, determine if it is height-balanced.
# 
# For this problem, a height-balanced binary tree is defined as:
# 
# 
# a binary tree in which the left and right subtrees of every node differ in
# height by no more than 1.
# 
# 
# 
# 
# Example 1:
# 
# Given the following tree [3,9,20,null,null,15,7]:
# 
# 
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
# 
# Return true.
# 
# Example 2:
# 
# Given the following tree [1,2,2,3,3,null,null,4,4]:
# 
# 
# ⁠      1
# ⁠     / \
# ⁠    2   2
# ⁠   / \
# ⁠  3   3
# ⁠ / \
# ⁠4   4
# 
# 
# Return false.
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
    def isBalanced(self, root: TreeNode) -> bool:
        def func(node):
            if node is None:
                return True, 0
            flag, l1 = func(node.left)
            if not flag:
                return False, None
            flag, l2 = func(node.right)
            if not flag:
                return False, None
            if abs(l1-l2) <= 1:
                return True, max(l1, l2) + 1
            else:
                return False, None
        flag, height = func(root)
        return flag
        
# @lc code=end

