/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.32%)
 * Likes:    1440
 * Dislikes: 5950
 * Total Accepted:    317.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Note:
 * 
 * 
 * Assume we are dealing with an environment that could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For this
 * problem, assume that your function returns 2^31 − 1 when the division result
 * overflows.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: dividend = 0, divisor = 1
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: dividend = 1, divisor = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int _dividend, int _divisor) {
        long long dividend = _dividend;
        long long divisor = _divisor;
        bool pos = true;
        if (dividend<0){
            dividend = 0-dividend; 
            pos = !pos;
        }
        if (divisor<0){
            divisor = 0-divisor;
            pos = !pos;
        }
        if (dividend < divisor) return 0;

        int multiplier = 0;
        while (dividend >= (divisor<<multiplier)) ++multiplier;

        divisor <<= multiplier-1;
        long long result = 0;
        long long current = static_cast<long long>(1) << (multiplier-1) ;
        for (int i=multiplier-1; i>=0; --i)
        {
            if (dividend >= divisor){
                result += current;
                dividend -= divisor;
            }
            current >>= 1;
            divisor >>= 1;
        }
        if (!pos) result = 0-result;
        if (result > INT_MAX || result < INT_MIN) return INT_MAX;
        return result;
        
    }
};
// @lc code=end
