#
# @lc app=leetcode id=115 lang=python3
#
# [115] Distinct Subsequences
#
# https://leetcode.com/problems/distinct-subsequences/description/
#
# algorithms
# Hard (37.18%)
# Likes:    1152
# Dislikes: 53
# Total Accepted:    133K
# Total Submissions: 352.9K
# Testcase Example:  '"rabbbit"\n"rabbit"'
#
# Given a string S and a string T, count the number of distinct subsequences of
# S which equals T.
# 
# A subsequence of a string is a new string which is formed from the original
# string by deleting some (can be none) of the characters without disturbing
# the relative positions of the remaining characters. (ie, "ACE" is a
# subsequence of "ABCDE" while "AEC" is not).
# 
# It's guaranteed the answer fits on a 32-bit signed integer.
# 
# Example 1:
# 
# 
# Input: S = "rabbbit", T = "rabbit"
# Output: 3
# Explanation:
# As shown below, there are 3 ways you can generate "rabbit" from S.
# (The caret symbol ^ means the chosen letters)
# 
# rabbbit
# ^^^^ ^^
# rabbbit
# ^^ ^^^^
# rabbbit
# ^^^ ^^^
# 
# 
# Example 2:
# 
# 
# Input: S = "babgbag", T = "bag"
# Output: 5
# Explanation:
# As shown below, there are 5 ways you can generate "bag" from S.
# (The caret symbol ^ means the chosen letters)
# 
# babgbag
# ^^ ^
# babgbag
# ^^    ^
# babgbag
# ^    ^^
# babgbag
# ⁠ ^  ^^
# babgbag
# ⁠   ^^^
# 
# 
#

# @lc code=start
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        if len(t) > len(s):
            return 0
        dps = [[0 for i in range(len(s)+1)] for j in range(len(t)+1)]
        dps[0] = [1]*(len(s) + 1)
        for i in range(1, len(t)+1):
            for j in range(i, len(s)+1):
                if t[i-1] == s[j-1]:
                    dps[i][j] = dps[i-1][j-1]
                dps[i][j] += dps[i][j-1]
        return dps[-1][-1]
                
        
# @lc code=end

