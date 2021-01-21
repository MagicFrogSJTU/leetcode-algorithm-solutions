#
# @lc app=leetcode id=188 lang=python3
#
# [188] Best Time to Buy and Sell Stock IV
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#
# algorithms
# Hard (27.75%)
# Likes:    1424
# Dislikes: 89
# Total Accepted:    127K
# Total Submissions: 456.4K
# Testcase Example:  '2\n[2,4,1]'
#
# Say you have an array for which the i-th element is the price of a given
# stock on day i.
# 
# Design an algorithm to find the maximum profit. You may complete at most k
# transactions.
# 
# Note:
# You may not engage in multiple transactions at the same time (ie, you must
# sell the stock before you buy again).
# 
# Example 1:
# 
# 
# Input: [2,4,1], k = 2
# Output: 2
# Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
# 4-2 = 2.
# 
# 
# Example 2:
# 
# 
# Input: [3,2,6,5,0,3], k = 2
# Output: 7
# Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
# 6-2 = 4.
# Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
# 3.
# 
# 
#

# @lc code=start
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if k == 0:
            return 0
        new_prices = prices[:2]
        for p in prices[2:]:
            if new_prices[-2] <= new_prices[-1] <= p or new_prices[-2] >= new_prices[-1] >= p:
                new_prices[-1] = p
            else:
                new_prices.append(p)
        prices = new_prices
        if len(prices) <= 1:
            return 0
        days = len(prices)
        if k >= days / 2:
            return sum(i - j for i, j in zip(prices[1:], prices[:-1]) if i - j > 0)

        states = [[float("-inf"), float("-inf")] for _ in range(k+1)]
        states[0][0] = 0
        states[0][1] = -prices[0]
        for day in range(1, days):
            states[0][1] = max(states[0][1], -prices[day])
            for trans_num in range(k, 0, -1):
                a = states[trans_num-1][1]
                states[trans_num][1] = max(states[trans_num][1], states[trans_num][0] - prices[day])
                states[trans_num][0] = max(states[trans_num][0], a + prices[day])
        return max(states[i][0] for i in range(k+1))
        
        
# @lc code=end

