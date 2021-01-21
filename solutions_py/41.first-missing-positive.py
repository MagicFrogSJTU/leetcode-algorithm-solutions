#
# @lc app=leetcode id=41 lang=python3
#
# [41] First Missing Positive
#
# https://leetcode.com/problems/first-missing-positive/description/
#
# algorithms
# Hard (31.06%)
# Likes:    3221
# Dislikes: 767
# Total Accepted:    320.5K
# Total Submissions: 1M
# Testcase Example:  '[1,2,0]'
#
# Given an unsorted integer array, find the smallest missing positive integer.
# 
# Example 1:
# 
# 
# Input: [1,2,0]
# Output: 3
# 
# 
# Example 2:
# 
# 
# Input: [3,4,-1,1]
# Output: 2
# 
# 
# Example 3:
# 
# 
# Input: [7,8,9,11,12]
# Output: 1
# 
# 
# Note:
# 
# Your algorithm should run in O(n) time and uses constant extra space.
# 
#

# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        length = len(nums)
        for i in range(length):
            while nums[i] != i+1 and 0 < nums[i] < length + 1 and nums[nums[i]-1] != nums[i]:
                tmp = nums[i] 
                nums[i] = nums[tmp-1]
                nums[tmp-1] = tmp
        for i in range(length):
            if nums[i] != i+1:
                return i+1
        return length + 1

        
# @lc code=end

