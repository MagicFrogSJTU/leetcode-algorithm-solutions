#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#
# https://leetcode.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (50.76%)
# Likes:    1346
# Dislikes: 104
# Total Accepted:    368.2K
# Total Submissions: 714.3K
# Testcase Example:  '5'
#
# Given a non-negative integer numRows, generate the first numRows of Pascal's
# triangle.
# 
# 
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
# 
# Example:
# 
# 
# Input: 5
# Output:
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
# 
# 
#

# @lc code=start
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if not numRows:
            return []
        if numRows == 1:
            return [[1]]
        results = self.generate(numRows-1)
        new_row = [1]
        new_row += [x+y for x,y in zip(results[-1], results[-1][1:])]
        new_row.append(1)
        results.append(new_row)
        return results
        
# @lc code=end

