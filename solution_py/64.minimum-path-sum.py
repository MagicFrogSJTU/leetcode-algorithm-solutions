#
# @lc app=leetcode id=64 lang=python3
#
# [64] Minimum Path Sum
#
# https://leetcode.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (51.55%)
# Likes:    2558
# Dislikes: 54
# Total Accepted:    379.2K
# Total Submissions: 715.7K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# Given a m x n grid filled with non-negative numbers, find a path from top
# left to bottom right which minimizes the sum of all numbers along its path.
# 
# Note: You can only move either down or right at any point in time.
# 
# Example:
# 
# 
# Input:
# [
# [1,3,1],
# ⁠ [1,5,1],
# ⁠ [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.
# 
# 
#
from typing import List

# @lc code=start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not len(grid) or not len(grid[0]):
            return -1
        dp = [0] * len(grid[0])
        dp[0] = grid[0][0]
        for j in range(1, len(grid[0])):
            dp[j] = dp[j - 1] + grid[0][j]
        for i in range(1, len(grid)):
            dp[0] += grid[i][0]
            for j in range(1, len(grid[0])):
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j] 
        return dp[-1]

        
# @lc code=end

