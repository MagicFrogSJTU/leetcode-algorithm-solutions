#
# @lc app=leetcode id=204 lang=python3
#
# [204] Count Primes
#
# https://leetcode.com/problems/count-primes/description/
#
# algorithms
# Easy (31.21%)
# Likes:    1975
# Dislikes: 607
# Total Accepted:    358.9K
# Total Submissions: 1.1M
# Testcase Example:  '10'
#
# Count the number of prime numbers less than a non-negative number, n.
# 
# Example:
# 
# 
# Input: 10
# Output: 4
# Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
# 
# 
#

# @lc code=start
class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        nums = [True] * n
        nums[0] = nums[1] = False
        for i in range(2, n):
            if nums[i]:
                for j in range(2, (n-1)//i+1):
                    nums[i*j] = False
        return sum(nums)
        
# @lc code=end

