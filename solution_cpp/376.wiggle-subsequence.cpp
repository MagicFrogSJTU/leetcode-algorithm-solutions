/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (39.95%)
 * Likes:    1213
 * Dislikes: 63
 * Total Accepted:    78.5K
 * Total Submissions: 195.9K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
 * 
 * 
 * 
 */

// @lc code=start
// O(n)
// 每个符合要求的子串，肯定能够以nums的最后一个数为结尾。所以很简单！
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        int i = 1;
        while (i < nums.size() && nums[i] == nums[0]) ++i;
        if (i == nums.size()) return 1;
        int len = 2;
        bool up = nums[i] > nums[0];

        for (++i; i<nums.size(); ++i){
            if (nums[i] == nums[i-1]) continue;
            if ((up&&nums[i]<nums[i-1]) || (!up && nums[i]>nums[i-1])){
                up = !up;
                ++len;
            }
        }
        return len;
    }
};
// @lc code=end
