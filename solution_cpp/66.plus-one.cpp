/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.00%)
 * Likes:    1312
 * Dislikes: 2148
 * Total Accepted:    544.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus=1;
        int pos=digits.size();
        while (plus && pos>0){
            pos-=1;
            digits[pos] = digits[pos] + 1;
            if (digits[pos] == 10){
                digits[pos] = 0;
            }else{
                plus=0;
            }
        }
        if (plus) digits.insert(digits.begin(), 1);
        return digits;
        
    }
};
// @lc code=end
