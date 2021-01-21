#
# @lc app=leetcode id=132 lang=python3
#
# [132] Palindrome Partitioning II
#
# https://leetcode.com/problems/palindrome-partitioning-ii/description/
#
# algorithms
# Hard (29.90%)
# Likes:    1032
# Dislikes: 32
# Total Accepted:    128.8K
# Total Submissions: 430.8K
# Testcase Example:  '"aab"'
#
# Given a string s, partition s such that every substring of the partition is a
# palindrome.
#
# Return the minimum cuts needed for a palindrome partitioning of s.
#
# Example:
#
#
# Input: "aab"
# Output: 1
# Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
# cut.
#
#
#

# @lc code=start
class Solution:
    def minCut(self, s: str) -> int:
        # acceleration
        if s == s[::-1]: return 0
        for i in range(1, len(s)):
            if s[:i] == s[:i][::-1] and s[i:] == s[i:][::-1]:
                return 1
        # algorithm
        cut = [x for x in range(-1,len(s))]  # cut numbers in worst case (no palindrome)
        for i in range(len(s)):
            r1, r2 = 0, 0
            # use i as origin, and gradually enlarge radius if a palindrome exists
            # odd palindrome
            while i-r1 >= 0 and i+r1 < len(s) and s[i-r1] == s[i+r1]:
                cut[i+r1+1] = min(cut[i+r1+1], cut[i-r1]+1)
                r1 += 1
            # even palindrome
            while i-r2 >= 0 and i+r2+1 < len(s) and s[i-r2] == s[i+r2+1]:
                cut[i+r2+2] = min(cut[i+r2+2], cut[i-r2]+1)
                r2 += 1
        return cut[-1]

# @lc code=end

