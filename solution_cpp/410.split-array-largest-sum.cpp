/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (45.77%)
 * Likes:    2273
 * Dislikes: 84
 * Total Accepted:    109.9K
 * Total Submissions: 238.9K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array nums which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays.
 * 
 * Write an algorithm to minimize the largest sum among these m subarrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [7,2,5,10,8], m = 2
 * Output: 18
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,5], m = 2
 * Output: 9
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,4,4], m = 3
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= m <= min(50, nums.length)
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
// O(n^2 * m)
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<vector<int>>> dps(nums.size(), vector<vector<int>>(nums.size(), vector<int>(m, -1)));

        return func(0, nums.size()-1, m-1, nums, dps);
    }

    int func(int lower, int upper, int splits, const vector<int> &nums, vector<vector<vector<int>>> &dps) {
        auto &target = dps[lower][upper-1][splits];
        if (target == -1){
            if (splits == 0) {
                target = accumulate(nums.begin()+lower, nums.begin()+upper+1, 0);
            }else {
                int left_sum = 0, right_sum;
                int res = INT_MAX;
                for (int i=lower; i<upper; ++i) {
                    left_sum += nums[i];
                    right_sum = func(i+1, upper, splits-1, nums, dps);
                    if (left_sum < right_sum) res = min(res, right_sum);
                    else {
                        res = min(res, left_sum);
                        break;
                    }
                }
                target = res;
            }
        }
        return target;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> vec = {7,2,5,10,8};
    cout << Solution().splitArray(vec, 2) << endl;
    vec = {1,4,4};
    cout << Solution().splitArray(vec, 3) << endl;
    return 0;
}
