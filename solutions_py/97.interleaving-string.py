#
# @lc app=leetcode id=97 lang=python3
#
# [97] Interleaving String
#
# https://leetcode.com/problems/interleaving-string/description/
#
# algorithms
# Hard (30.48%)
# Likes:    1327
# Dislikes: 81
# Total Accepted:    148.5K
# Total Submissions: 479.7K
# Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
#
# Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
# s2.
#
# Example 1:
#
#
# Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
# Output: true
#
#
# Example 2:
#
#
# Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
# Output: false
#
#
#

# @lc code=start

# O(2*n) space
class Solution:


# @lc code=end

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        r, c, l= len(s1), len(s2), len(s3)
        if r+c != l:
            return False
        dp = [[True for _ in range(c+1)] for _ in range(r+1)]
        for i in range(1, r+1):
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1]
        for j in range(1, c+1):
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1]
        for i in range(1, r+1):
            if_possible = dp[i][0]
            for j in range(1, c+1):
                dp[i][j] = (dp[i-1][j] and s1[i-1] == s3[i-1+j]) or \
                   (dp[i][j-1] and s2[j-1] == s3[i-1+j])
                if_possible = if_possible or dp[i][j]
            if not if_possible:
                return False
        return dp[-1][-1]




class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:

        def func(s1, s2, s3, dps):
            if (s1, s2, s3) in dps:
                return dps[(s1, s2, s3)]
            result = False
            if len(s1) + len(s2) != len(s3):
                result = False
            elif len(s1) == len(s2) == len(s3) == 0:
                result = True
            elif (len(s1) and s1[0] == s3[0] and func(s1[1:], s2, s3[1:], dps)) or \
                (len(s2) and s2[0] == s3[0] and func(s1, s2[1:], s3[1:], dps)):
                result = True
            dps[(s1, s2, s3)] = result
            return result
        dps = {}
        return func(s1, s2, s3, dps)
