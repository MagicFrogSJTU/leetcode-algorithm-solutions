#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#
# https://leetcode.com/problems/validate-binary-search-tree/description/
#
# algorithms
# Medium (27.28%)
# Likes:    3661
# Dislikes: 520
# Total Accepted:    669K
# Total Submissions: 2.4M
# Testcase Example:  '[2,1,3]'
#
# Given a binary tree, determine if it is a valid binary search tree (BST).
#
# Assume a BST is defined as follows:
#
#
# The left subtree of a node contains only nodes with keys less than the node's
# key.
# The right subtree of a node contains only nodes with keys greater than the
# node's key.
# Both the left and right subtrees must also be binary search trees.
#
#
#
#
# Example 1:
#
#
# ⁠   2
# ⁠  / \
# ⁠ 1   3
#
# Input: [2,1,3]
# Output: true
#
#
# Example 2:
#
#
# ⁠   5
# ⁠  / \
# ⁠ 1   4
# / \
# 3   6
#
# Input: [5,1,4,null,null,3,6]
# Output: false
# Explanation: The root node's value is 5 but its right child's value is 4.
#
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
    def isValidBST(self, root: TreeNode) -> bool:
        last = -float("inf")
        stack = []
        while True:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                break
            node = stack.pop()
            if node.val <= last:
                return False
            last = node.val
            root = node.right
        return True



# @lc code=end


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def func(root):
            if root:
                if root.left and root.right:
                    flag, max1, min1 = func(root.left)
                    if flag:
                        flag, max2, min2 = func(root.right)
                        if flag and max1 < root.val < min2:
                            return True, max2, min1
                elif root.left:
                    flag, max1, min1 = func(root.left)
                    if flag and max1 < root.val:
                        return True, root.val, min1
                elif root.right:
                    flag, max2, min2 = func(root.right)
                    if flag and root.val < min2:
                        return True, max2, root.val
                else:
                    return True, root.val, root.val
                return False, None, None
            else:
                return True, None, None
        result, _, _ = func(root)
        return result
