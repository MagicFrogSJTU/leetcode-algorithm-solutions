#
# @lc app=leetcode id=120 lang=python3
#
# [120] Triangle
#
# https://leetcode.com/problems/triangle/description/
#
# algorithms
# Medium (42.79%)
# Likes:    1882
# Dislikes: 227
# Total Accepted:    241.2K
# Total Submissions: 555.2K
# Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
#
# Given a triangle, find the minimum path sum from top to bottom. Each step you
# may move to adjacent numbers on the row below.
# 
# For example, given the following triangle
# 
# 
# [
# ⁠    [2],
# ⁠   [3,4],
# ⁠  [6,5,7],
# ⁠ [4,1,8,3]
# ]
# 
# 
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
# 
# Note:
# 
# Bonus point if you are able to do this using only O(n) extra space, where n
# is the total number of rows in the triangle.
# 
#

# @lc code=start
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not len(triangle):
            return 0
        sumlist = [0] * len(triangle)
        sumlist[0] = triangle[0][0]
        for i in range(1, len(triangle)):
            line = triangle[i]
            sumlist[len(line)-1] = sumlist[len(line)-2] + line[-1]
            for j in range(len(line)-2, 0, -1):
                sumlist[j] = min(sumlist[j-1], sumlist[j]) + line[j]
            sumlist[0] = sumlist[0] + line[0]
        return min(sumlist)


        
# @lc code=end

