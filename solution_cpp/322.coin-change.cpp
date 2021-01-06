/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (36.60%)
 * Likes:    5639
 * Dislikes: 169
 * Total Accepted:    530.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: coins = [1], amount = 1
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: coins = [1], amount = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
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
#include <cstring>
using namespace std;

// @lc code=start
class Solution {
public:
    int dps[10001];
    Solution(){
        for (int i=0; i<10001; i++){
            dps[i] = -2;
        }
        dps[0]=0;
    }

    int coinChange(vector<int>& coins, int amount) {
        if (dps[amount] == -2){
            int num = INT_MAX;
            for (int coin : coins){
                if (coin <= amount){
                    int result = coinChange(coins, amount - coin);
                    if (result!=-1) num=min(num, result);
                }
            }
            if (num==INT_MAX) dps[amount]=-1;
            else dps[amount]=num+1;
        }
        return dps[amount];
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> p = {1,2,5};
    cout << Solution().coinChange(p, 11) << endl;
    p = {125,146,125,252,226,25,24,308,50};
    cout << Solution().coinChange(p, 8402) << endl;
    return 0;
}
