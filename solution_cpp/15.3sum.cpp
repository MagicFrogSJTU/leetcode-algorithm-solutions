/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.29%)
 * Likes:    8484
 * Dislikes: 917
 * Total Accepted:    1.1M
 * Total Submissions: 4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); i++)
        {
            int front = i+1;
            int back = nums.size()-1;
            while (front<back){
                int sum = nums[front] + nums[back];
                if (sum>-nums[i]){
                    --back;
                }else if (sum<-nums[i]){
                    ++front;
                }else{
                    vector<int> piece = {nums[i], nums[front], nums[back]};
                    res.push_back(piece);
                    while (front<back && nums[front]==piece[1]) ++front;
                    while (front<back && nums[back]==piece[2]) --back;
                }
            }
            while (i<nums.size()-1 && nums[i]==nums[i+1]) ++i;
        }
        return res;
    }
};
// @lc code=end
