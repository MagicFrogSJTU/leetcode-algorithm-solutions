#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#
# https://leetcode.com/problems/longest-consecutive-sequence/description/
#
# algorithms
# Hard (44.65%)
# Likes:    3137
# Dislikes: 173
# Total Accepted:    293.5K
# Total Submissions: 657.3K
# Testcase Example:  '[100,4,200,1,3,2]'
#
# Given an unsorted array of integers, find the length of the longest
# consecutive elements sequence.
# 
# Your algorithm should run in O(n) complexity.
# 
# Example:
# 
# 
# Input: [100, 4, 200, 1, 3, 2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
# Therefore its length is 4.
# 
# 
#

# @lc code=start
class Solution:
    def longestConsecutive(self, num: List[int]) -> int:
        num=set(num)
        maxLen=0
        while num:
            n=num.pop()
            i=n+1
            l1=0
            l2=0
            while i in num:
                num.remove(i)
                i+=1
                l1+=1
            i=n-1
            while i in num:
                num.remove(i)
                i-=1
                l2+=1
            maxLen=max(maxLen,l1+l2+1)
        return maxLen


        
# @lc code=end

