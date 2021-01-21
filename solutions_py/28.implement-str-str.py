#
# @lc app=leetcode id=28 lang=python3
#
# [28] Implement strStr()
#
# https://leetcode.com/problems/implement-strstr/description/
#
# algorithms
# Easy (34.25%)
# Likes:    1602
# Dislikes: 1914
# Total Accepted:    674.5K
# Total Submissions: 2M
# Testcase Example:  '"hello"\n"ll"'
#
# Implement strStr().
# 
# Return the index of the first occurrence of needle in haystack, or -1 if
# needle is not part of haystack.
# 
# Example 1:
# 
# 
# Input: haystack = "hello", needle = "ll"
# Output: 2
# 
# 
# Example 2:
# 
# 
# Input: haystack = "aaaaa", needle = "bba"
# Output: -1
# 
# 
# Clarification:
# 
# What should we return when needle is an empty string? This is a great
# question to ask during an interview.
# 
# For the purpose of this problem, we will return 0 when needle is an empty
# string. This is consistent to C's strstr() and Java's indexOf().
# 
#

# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not len(needle):
            return 0
        if len(needle) > len(haystack):
            return -1

        kmp = [0] * len(needle)
        kmp[0] = -1
        i = 2
        j = 0
        while i < len(needle):
            # 本质上，如果needle[i:i+j] = needle[:j]，那么kmp[i+j] = j
            if needle[i-1] == needle[j]:
                j += 1
                kmp[i] = j
                i += 1
            else:
                j = kmp[j]
                if j == -1:
                    j = 0
                    i += 1
        # 加速
        for i in range(1, len(needle)):
            if kmp[i] != 0:
               if needle[i] == needle[kmp[i]]:
                    kmp[i] = kmp[kmp[i]]

        i = 0
        j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
                if j == len(needle):
                    return i - len(needle)
            else:
                j = kmp[j]
                if j == -1:
                    j = 0
                    i += 1
        return -1


        
# @lc code=end

print(Solution().strStr("hello", "ll"))
print(Solution().strStr("aabaaabaaac", "aabaaac"))
print(Solution().strStr("aaaaa", "bba"))
print(Solution().strStr("mississippi", "pi"))

class Solution2:
    def strStr(self, haystack: str, needle: str) -> int:
        if not len(needle):
            return 0
        if len(needle) > len(haystack):
            return -1

        # KMP核心，在对比时，当i位置不符合要求时，回去看kmp[i]位置符不符合要求
        kmp = [0] * len(needle)
        j = 0
        for i in range(1, len(needle)-1):
            # 迭代地回去看kmp,直到没得回去，或者找到匹配
            while j != 0 and needle[i] != needle[j]:
                j = kmp[j]
            if needle[i] == needle[j]:
                kmp[i+1] = j+1
                j += 1
         
        # 加速
        for i in range(1, len(needle)):
            if kmp[i] != 0:
               if needle[i] == needle[kmp[i]]:
                    kmp[i] = kmp[kmp[i]]



        j = 0
        for i in range(len(haystack)):
            while j != 0 and haystack[i] != needle[j]:
                j = kmp[j]
            if haystack[i] == needle[j]:
                j += 1
                if j == len(needle):
                    return i - len(needle) + 1
        return -1