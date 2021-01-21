/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (44.59%)
 * Likes:    3798
 * Dislikes: 86
 * Total Accepted:    249K
 * Total Submissions: 556.9K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 * 
 * 
 */
#include <iostream>
#include <climits>
#include <map>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1) return false;

        sum /= 2;
        int dp[n+1][sum+1]; // why this grammar works? https://stackoverflow.com/a/25474295/11118777

        for(int i=0; i<=n; i++)
            dp[i][0] = 0;

        for(int i=0; i<=sum; i++)
            dp[0][i] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                if(j-nums[i-1] >= 0)
                    dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum] == sum;

        
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}
