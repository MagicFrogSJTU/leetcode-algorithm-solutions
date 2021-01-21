#
# @lc app=leetcode id=233 lang=python
#
# [233] Number of Digit One
#
# https://leetcode.com/problems/number-of-digit-one/description/
#
# algorithms
# Hard (31.18%)
# Total Accepted:    48.5K
# Total Submissions: 155K
# Testcase Example:  '13'
#
# Given an integer n, count the total number of digit 1 appearing in all
# non-negative integers less than or equal to n.
#
# Example:
#
#
# Input: 13
# Output: 6
# Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
#
#
#


class Solution(object):
    def countDigitOne(self, n):
        ones = 0
        m = 1
        while m <= n:
            # Consider position current_num:   n = concat[left_a, current_num, b]
            a, b = divmod(n, m)
            left_a, current_num = divmod(a, 10)
            ones += left_a * m
            if current_num == 1:
                ones += b + 1
            elif current_num > 1:
                ones += m
            m *= 10
        return ones


"""
class Solution(object):
    def countDigitOne(self, n):
        if n < 10:
            if n >= 1:
                return 1
            return 0
        n_str = str(n)
        rank = len(n_str)
        num_one = [0] * (rank - 1)
        num_one[0] = 1
        for i in range(1, rank-1):
            num_one[i] = 10**i + 10 * num_one[i-1]

        res = 0
        for i, letter in enumerate(n_str[:-1]):
            letter = int(letter)
            res += num_one[rank-2-i] * letter
            if letter > 1:
                res += 10 ** (rank-1-i)
            elif letter == 1:
                res += int(n_str[i+1:]) + 1
        if int(n_str[-1]) >= 1:
            res += 1
        return res
"""


print(Solution().countDigitOne(0))
print(Solution().countDigitOne(1))
print(Solution().countDigitOne(2))
print(Solution().countDigitOne(13))
print(Solution().countDigitOne(100))
