#
# @lc app=leetcode id=221 lang=python3
#
# [221] Maximal Square
#
# https://leetcode.com/problems/maximal-square/description/
#
# algorithms
# Medium (37.35%)
# Likes:    3124
# Dislikes: 79
# Total Accepted:    267.4K
# Total Submissions: 711.2K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# Given a 2D binary matrix filled with 0's and 1's, find the largest square
# containing only 1's and return its area.
# 
# Example:
# 
# 
# Input: 
# 
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
# 
# Output: 4
# 
#
from typing import List

# @lc code=start
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        import copy
        if not matrix or not matrix[0]:
            return 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = int(matrix[i][j])
        square_lens = copy.copy(matrix[0])
        result = max(square_lens)
        for x in range(1, len(matrix)):
            square_lens[0] = matrix[x][0]
            for y in range(1, len(square_lens)):
                if matrix[x][y]:
                    min_len = min(square_lens[y-1], square_lens[y])
                    if min_len:
                        if matrix[x-min_len][y-min_len]:
                            square_lens[y] = min_len + 1
                        else:
                            square_lens[y] = min_len
                    else:
                        square_lens[y] = 1
                else:
                    square_lens[y] = 0
            result = max(result, max(square_lens))
        return result**2
                    

        
# @lc code=end
a = Solution().maximalSquare([["0","1","0","1","0","0"],["0","0","1","1","0","1"]])
print(a)

