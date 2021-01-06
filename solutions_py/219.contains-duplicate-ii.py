#
# @lc app=leetcode id=219 lang=python3
#
# [219] Contains Duplicate II
#
# https://leetcode.com/problems/contains-duplicate-ii/description/
#
# algorithms
# Easy (37.39%)
# Likes:    850
# Dislikes: 1024
# Total Accepted:    271.8K
# Total Submissions: 723.1K
# Testcase Example:  '[1,2,3,1]\n3'
#
# Given an array of integers and an integer k, find out whether there are two
# distinct indices i and j in the array such that nums[i] = nums[j] and the
# absolute difference between i and j is at most k.
# 
# 
# Example 1:
# 
# 
# Input: nums = [1,2,3,1], k = 3
# Output: true
# 
# 
# 
# Example 2:
# 
# 
# Input: nums = [1,0,1,1], k = 1
# Output: true
# 
# 
# 
# Example 3:
# 
# 
# Input: nums = [1,2,3,1,2,3], k = 2
# Output: false
# 
# 
# 
# 
# 
#

# @lc code=start
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if not len(nums):
            return False
        c = set()
        for i in range(len(nums)):
            if nums[i] in c:
                return True
            c.add(nums[i])
            if i >= k:
                c.remove(nums[i-k])
        return False
        
        

        
# @lc code=end

