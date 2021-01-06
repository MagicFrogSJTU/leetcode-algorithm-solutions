#
# @lc app=leetcode id=43 lang=python3
#
# [43] Multiply Strings
#
# https://leetcode.com/problems/multiply-strings/description/
#
# algorithms
# Medium (32.99%)
# Likes:    1652
# Dislikes: 754
# Total Accepted:    283.7K
# Total Submissions: 850.2K
# Testcase Example:  '"2"\n"3"'
#
# Given two non-negative integers num1 and num2 represented as strings, return
# the product of num1 and num2, also represented as a string.
# 
# Example 1:
# 
# 
# Input: num1 = "2", num2 = "3"
# Output: "6"
# 
# Example 2:
# 
# 
# Input: num1 = "123", num2 = "456"
# Output: "56088"
# 
# 
# Note:
# 
# 
# The length of both num1 and num2 is < 110.
# Both num1 and num2 contain only digits 0-9.
# Both num1 and num2 do not contain any leading zero, except the number 0
# itself.
# You must not use any built-in BigInteger library or convert the inputs to
# integer directly.
# 
# 
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        res = [0] * (len(num1) + len(num2))
        for i, unit1 in enumerate(num1[::-1]):
            carry = 0
            for j, unit2 in enumerate(num2[::-1]):
                tmp = int(unit1) * int(unit2) + carry 
                # take care of the order of the next two lines
                carry, res[i+j] = divmod((res[i+j] + tmp), 10)
            res[i+len(num2)] += carry
        res = "".join(map(str, res[::-1]))
        return '0' if not res.lstrip("0") else res.lstrip("0")


                
        
# @lc code=end

a = Solution().multiply("33", "33")
print(a)