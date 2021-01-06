#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#
# https://leetcode.com/problems/group-anagrams/description/
#
# algorithms
# Medium (55.09%)
# Likes:    3328
# Dislikes: 174
# Total Accepted:    659K
# Total Submissions: 1.2M
# Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
#
# Given an array of strings, group anagrams together.
# 
# Example:
# 
# 
# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
# ⁠ ["ate","eat","tea"],
# ⁠ ["nat","tan"],
# ⁠ ["bat"]
# ]
# 
# Note:
# 
# 
# All inputs will be in lowercase.
# The order of your output does not matter.
# 
# 
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        results = {}
        for one in strs:
            results.setdefault("".join(sorted(one)), []).append(one)
        return results.values()
        
# @lc code=end

