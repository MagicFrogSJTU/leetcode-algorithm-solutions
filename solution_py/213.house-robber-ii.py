#
# @lc app=leetcode id=213 lang=python3
#
# [213] House Robber II
#
# https://leetcode.com/problems/house-robber-ii/description/
#
# algorithms
# Medium (36.23%)
# Likes:    1726
# Dislikes: 49
# Total Accepted:    172.8K
# Total Submissions: 475.5K
# Testcase Example:  '[2,3,2]'
#
# You are a professional robber planning to rob houses along a street. Each
# house has a certain amount of money stashed. All houses at this place are
# arranged in a circle. That means the first house is the neighbor of the last
# one. Meanwhile, adjacent houses have security system connected and it will
# automatically contact the police if two adjacent houses were broken into on
# the same night.
# 
# Given a list of non-negative integers representing the amount of money of
# each house, determine the maximum amount of money you can rob tonight without
# alerting the police.
# 
# Example 1:
# 
# 
# Input: [2,3,2]
# Output: 3
# Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money =
# 2),
# because they are adjacent houses.
# 
# 
# Example 2:
# 
# 
# Input: [1,2,3,1]
# Output: 4
# Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
# 3).
# Total amount you can rob = 1 + 3 = 4.
# 
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        if not len(nums):
            return 0
        if len(nums) < 3:
            return max(nums)

        def rob_once(nums):
            yes, no = 0, 0
            for num in nums:
                yes, no = no + num, max(yes, no)
            return max(yes, no)
        return max(rob_once(nums[1:]), rob_once(nums[:-1]))
        
# @lc code=end

