#
# @lc app=leetcode id=216 lang=python3
#
# [216] Combination Sum III
#
# https://leetcode.com/problems/combination-sum-iii/description/
#
# algorithms
# Medium (55.80%)
# Likes:    1057
# Dislikes: 51
# Total Accepted:    166.8K
# Total Submissions: 296.5K
# Testcase Example:  '3\n7'
#
# 
# Find all possible combinations of k numbers that add up to a number n, given
# that only numbers from 1 to 9 can be used and each combination should be a
# unique set of numbers.
# 
# Note:
# 
# 
# All numbers will be positive integers.
# The solution set must not contain duplicate combinations.
# 
# 
# Example 1:
# 
# 
# Input: k = 3, n = 7
# Output: [[1,2,4]]
# 
# 
# Example 2:
# 
# 
# Input: k = 3, n = 9
# Output: [[1,2,6], [1,3,5], [2,3,4]]
# 
# 
#

# @lc code=start
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def func(start, end, target, depth):
            if target < depth*start or target > depth*9:
                return []
            if not depth:
                return [[]]
            results = []
            for i in range(start, end+1):
                results.extend([j + [i] for j in func(i+1, end, target-i, depth-1)])
            return results
        return func(1, 9, n, k)
        
# @lc code=end

