#
# @lc app=leetcode id=131 lang=python3
#
# [131] Palindrome Partitioning
#
# https://leetcode.com/problems/palindrome-partitioning/description/
#
# algorithms
# Medium (46.44%)
# Likes:    1719
# Dislikes: 64
# Total Accepted:    221.6K
# Total Submissions: 477.3K
# Testcase Example:  '"aab"'
#
# Given a string s, partition s such that every substring of the partition is a
# palindrome.
# 
# Return all possible palindrome partitioning of s.
# 
# Example:
# 
# 
# Input: "aab"
# Output:
# [
# ⁠ ["aa","b"],
# ⁠ ["a","a","b"]
# ]
# 
# 
#

# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not len(s):
            return []

        def is_palindrome(s):
            return s == s[::-1]

        def func(string, dps):
            if string in dps:
                return dps[string]
            if not len(string):
                return [[]]
            results = []
            for i in range(len(string)):
                if is_palindrome(string[:i+1]):
                    results.extend([[string[:i+1]] + post for post in func(string[i+1:], dps)])
            dps[string] = results
            return results

        DPS = {}
        return func(s, DPS)
        
# @lc code=end

