#
# @lc app=leetcode id=209 lang=python3
#
# [209] Minimum Size Subarray Sum
#
# https://leetcode.com/problems/minimum-size-subarray-sum/description/
#
# algorithms
# Medium (37.64%)
# Likes:    2347
# Dislikes: 106
# Total Accepted:    268.3K
# Total Submissions: 708.2K
# Testcase Example:  '7\n[2,3,1,2,4,3]'
#
# Given an array of n positive integers and a positive integer s, find the
# minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
# one, return 0 instead.
# 
# Example: 
# 
# 
# Input: s = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: the subarray [4,3] has the minimal length under the problem
# constraint.
# 
# Follow up:
# 
# If you have figured out the O(n) solution, try coding another solution of
# which the time complexity is O(n log n). 
# 
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if not len(nums):
            return 0
        left = 0
        right = 0
        sums = 0
        min_length = float("inf")
        while right < len(nums):
            sums += nums[right]
            right += 1
            while sums >= s:
                min_length = min(min_length, right-left)
                sums -= nums[left]
                left += 1
        if min_length == float("inf"):
            return 0
        return min_length
            
        
# @lc code=end

