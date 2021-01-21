/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (38.09%)
 * Likes:    1660
 * Dislikes: 85
 * Total Accepted:    105.7K
 * Total Submissions: 277K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers nums, return the largest subset
 * answer such that every pair (answer[i], answer[j]) of elements in this
 * subset satisfies:
 * 
 * 
 * answer[i] % answer[j] == 0, or
 * answer[j] % answer[i] == 0
 * 
 * 
 * If there are multiple solutions, return any of them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [1,2]
 * Explanation: [1,3] is also accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,4,8]
 * Output: [1,2,4,8]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 2 * 10^9
 * All the integers in nums are unique.
 * 
 * 
 */
#include <iostream>
#include <climits>
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
    // O(n^2);
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size()<2) return nums;

        sort(nums.begin(), nums.end());

        vector<int> dps(nums.size(), 1);
        vector<int> pos(nums.size());
        for (int i=0; i<nums.size(); ++i) pos[i] = i;

        for (int i=1; i<nums.size(); ++i){
            for (int j=0; j<i; ++j){
                if (nums[i] % nums[j] == 0){
                    if (dps[i] < dps[j]+1)
                    {
                        dps[i] = dps[j]+1;
                        pos[i] = j;
                    }
                }
            }
        }
        int i = max_element(dps.begin(), dps.end()) - dps.begin();
        vector<int> results;
        results.push_back(nums[i]);
        while (pos[i] != i){
            i = pos[i];
            results.push_back(nums[i]);
        }
        return results;

    }
};
// @lc code=end

int main(int argc, char **argv)
{
    vector<int> nums = {1,2,4,8};
    for (auto i : Solution().largestDivisibleSubset(nums)) cout<<i<<",";
    cout<<endl;
    nums = {1,2,3};
    for (auto i : Solution().largestDivisibleSubset(nums)) cout<<i<<",";
    cout<<endl;
    return 0;
}

