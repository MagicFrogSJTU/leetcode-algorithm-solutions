/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (33.08%)
 * Likes:    4628
 * Dislikes: 1623
 * Total Accepted:    448.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 * 
 * The replacement must be in place and use only constant extra memory.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;

        int i;
        for (i=nums.size()-1; i>=1; --i){
            if (nums[i] > nums[i-1]) break;
        }

        if (i!=0){
            int j;
            for (j=nums.size()-1; j>=i; --j){
                if (nums[j] > nums[i-1]) break;
            }
            swap(nums[i-1], nums[j]);
        }
        reverse(nums.begin()+i, nums.end());
    }
};
// @lc code=end
