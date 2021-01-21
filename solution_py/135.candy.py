#
# @lc app=leetcode id=135 lang=python3
#
# [135] Candy
#
# https://leetcode.com/problems/candy/description/
#
# algorithms
# Hard (31.16%)
# Likes:    886
# Dislikes: 161
# Total Accepted:    128.6K
# Total Submissions: 412.6K
# Testcase Example:  '[1,0,2]'
#
# There are N children standing in a line. Each child is assigned a rating
# value.
#
# You are giving candies to these children subjected to the following
# requirements:
#
#
# Each child must have at least one candy.
# Children with a higher rating get more candies than their neighbors.
#
#
# What is the minimum candies you must give?
#
# Example 1:
#
#
# Input: [1,0,2]
# Output: 5
# Explanation: You can allocate to the first, second and third child with 2, 1,
# 2 candies respectively.
#
#
# Example 2:
#
#
# Input: [1,2,2]
# Output: 4
# Explanation: You can allocate to the first, second and third child with 1, 2,
# 1 candies respectively.
# ⁠            The third child gets 1 candy because it satisfies the above two
# conditions.
#
#
#
from typing import List

# @lc code=start
class Solution:
    def candy(self, ratings: List[int]) -> int:
        length = len(ratings)
        candies = [1] * length
        for i, rating in sorted([(i, rating) for i, rating in enumerate(ratings)], key=lambda x: x[1]):
            print(i, rating)
            if 0 <= i-1 and rating > ratings[i-1]:
                candies[i] = candies[i-1] + 1
            if i+1 < length and rating > ratings[i+1]:
                candies[i] = max(candies[i], candies[i+1] + 1)
        return sum(candies)



# @lc code=end
print(Solution().candy([1,0,2]))

