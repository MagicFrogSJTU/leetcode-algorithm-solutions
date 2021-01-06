/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (47.91%)
 * Likes:    3227
 * Dislikes: 103
 * Total Accepted:    176.9K
 * Total Submissions: 368.9K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */
#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int buy = -prices[0];
        int sell=0, cooldown=0;

        for (int i=1; i<prices.size(); ++i){
            int new_buy = max(buy, cooldown-prices[i]);
            int new_sell = max(sell, buy+prices[i]);
            int new_cooldown = max(cooldown, sell);
            buy = new_buy; sell = new_sell; cooldown = new_cooldown;
        }
        return max(sell, cooldown);
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> prices = {1,2,3,0,2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
