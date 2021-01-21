#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#
# https://leetcode.com/problems/decode-ways/description/
#
# algorithms
# Medium (23.90%)
# Likes:    2480
# Dislikes: 2682
# Total Accepted:    383.3K
# Total Submissions: 1.6M
# Testcase Example:  '"12"'
#
# A message containing letters from A-Z is being encoded to numbers using the
# following mapping:
# 
# 
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# 
# 
# Given a non-empty string containing only digits, determine the total number
# of ways to decode it.
# 
# Example 1:
# 
# 
# Input: "12"
# Output: 2
# Explanation: It could be decoded as "AB" (1 2) or "L" (12).
# 
# 
# Example 2:
# 
# 
# Input: "226"
# Output: 3
# Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
# 6).
# 
#

# @lc code=start
class Solution:
    def numDecodings(self, s: str) -> int:
        dps = {}

        def func(s, dps):
            if s in dps:
                return dps[s]
            if not len(s) or s[0] == "0":
                return 0
            if len(s) == 1:
                return 1
            
            b = func(s[1:], dps)
            if int(s[:2]) <= 26:
                a = func(s[2:], dps) if len(s)>2 else 1
                dps[s] = a + b
                return a + b
            else:
                dps[s] = b
                return b
        return func(s, dps)


        
# @lc code=end

