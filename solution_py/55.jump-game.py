#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#
from typing import List

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        start = 0
        end = 0
        while True:
            last_end = end
            for i in range(start, end+1):
                end = max(i + nums[i], end)
            if end >= len(nums) - 1:
                return True
            if last_end == end:
                return False
            start = last_end + 1

# @lc code=end

