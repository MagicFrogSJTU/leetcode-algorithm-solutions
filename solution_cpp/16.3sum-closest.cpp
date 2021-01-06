/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.86%)
 * Likes:    2593
 * Dislikes: 157
 * Total Accepted:    519.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=INT_MAX;
        std::sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); i++)
        {
            int front = i+1;
            int back = nums.size()-1;
            while (front<back){
                int abtract = target - nums[i] - nums[front] - nums[back];
                if (abtract>0){
                    ++front;
                    while (front<back && nums[front]==nums[front-1]) ++front;
                }else if (abtract<0){
                    --back;
                    while (front<back && nums[back]==nums[back+1]) --back;
                }else{
                    return target;
                }
                if (abs(res) > abs(abtract)) res=abtract;
            }
            while (i<nums.size()-1 && nums[i]==nums[i+1]) ++i;
        }
        return target-res;
    }
};
// @lc code=end
