/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 *
 * https://leetcode.com/problems/burst-balloons/description/
 *
 * algorithms
 * Hard (53.03%)
 * Likes:    3227
 * Dislikes: 90
 * Total Accepted:    123.9K
 * Total Submissions: 231.2K
 * Testcase Example:  '[3,1,5,8]'
 *
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted
 * with a number on it represented by an array nums. You are asked to burst all
 * the balloons.
 * 
 * If you burst the i^th balloon, you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 * 
 * Return the maximum coins you can collect by bursting the balloons wisely.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,1,5,8]
 * Output: 167
 * Explanation:
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,5]
 * Output: 10
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 500
 * 0 <= nums[i] <= 100
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
    int dp[502][502];
    int solve(vector<int>& nums,int i,int j)
    {
        if(dp[i][j]==-1)
        {
            int ans = 0;
            for(int k = i+1;k<j;k++)
                ans = max(ans,solve(nums,i,k)+solve(nums,k,j)+nums[i]*nums[k]*nums[j]);
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& _nums) {
        vector<int> nums(_nums.size()+2);
        nums[0] = 1;
        for (int i=0; i<_nums.size(); ++i) nums[i+1] = _nums[i];
        nums[nums.size()-1] = 1;
        memset(dp,-1,sizeof(dp));
        cout << endl;
        return solve(nums,0,nums.size()-1);
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> q = {3,1,5,8};
    cout << Solution().maxCoins(q) << endl;
    return 0;
}
