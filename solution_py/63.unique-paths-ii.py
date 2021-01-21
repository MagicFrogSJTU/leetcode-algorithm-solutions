#
# @lc app=leetcode id=63 lang=python3
#
# [63] Unique Paths II
#
# https://leetcode.com/problems/unique-paths-ii/description/
#
# algorithms
# Medium (33.98%)
# Likes:    1447
# Dislikes: 223
# Total Accepted:    271.9K
# Total Submissions: 799.9K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# A robot is located at the top-left corner of a m x n grid (marked 'Start' in
# the diagram below).
# 
# The robot can only move either down or right at any point in time. The robot
# is trying to reach the bottom-right corner of the grid (marked 'Finish' in
# the diagram below).
# 
# Now consider if some obstacles are added to the grids. How many unique paths
# would there be?
# 
# 
# 
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
# 
# Note: m and n will be at most 100.
# 
# Example 1:
# 
# 
# Input:
# [
# [0,0,0],
# [0,1,0],
# [0,0,0]
# ]
# Output: 2
# Explanation:
# There is one obstacle in the middle of the 3x3 grid above.
# There are two ways to reach the bottom-right corner:
# 1. Right -> Right -> Down -> Down
# 2. Down -> Down -> Right -> Right
# 
# 
#

from typing import List
# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if len(obstacleGrid) == 0:
            return 0
        solutions = [[0 for i in range(len(obstacleGrid[0]))] for i in range(len(obstacleGrid))]
        if not obstacleGrid[0][0]:
            solutions[0][0] = 1
        for x in range(len(obstacleGrid)):
            for y in range(len(obstacleGrid[0])):
                if not obstacleGrid[x][y]:
                    if x and not obstacleGrid[x-1][y]:
                        solutions[x][y] += solutions[x-1][y]
                    if y and not obstacleGrid[x][y-1]:
                        solutions[x][y] += solutions[x][y-1]
        print(solutions)
        return solutions[-1][-1]

        
# @lc code=end

inputs = [
[0,0,0],
[0,1,0],
[0,0,0]
]
s =Solution()
print(s.uniquePathsWithObstacles(inputs))

