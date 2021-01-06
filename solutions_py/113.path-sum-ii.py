#
# @lc app=leetcode id=113 lang=python3
#
# [113] Path Sum II
#
# https://leetcode.com/problems/path-sum-ii/description/
#
# algorithms
# Medium (44.94%)
# Likes:    1645
# Dislikes: 62
# Total Accepted:    320.8K
# Total Submissions: 701.3K
# Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
#
# Given a binary tree and a sum, find all root-to-leaf paths where each path's
# sum equals the given sum.
# 
# Note: A leaf is a node with no children.
# 
# Example:
# 
# Given the below binary tree and sum = 22,
# 
# 
# ⁠     5
# ⁠    / \
# ⁠   4   8
# ⁠  /   / \
# ⁠ 11  13  4
# ⁠/  \    / \
# 7    2  5   1
# 
# 
# Return:
# 
# 
# [
# ⁠  [5,4,11,2],
# ⁠  [5,8,4,5]
# ]
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
import copy
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        succs = []
        def func(root, path, pre_sum):
            if root is None:
                return
            path.append(root.val)
            pre_sum += root.val
            if not root.left and not root.right:
                if pre_sum == sum:
                    succs.append(copy.deepcopy(path))
            func(root.left, path, pre_sum)
            func(root.right, path, pre_sum)
            path.pop()
            pre_sum -= root.val
        func(root, [], 0)
        return succs



            
        
# @lc code=end

