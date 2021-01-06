/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.65%)
 * Likes:    3231
 * Dislikes: 5070
 * Total Accepted:    1.1M
 * Total Submissions: 4.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */
#include <iostream>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0)
        {
            result = result*10 + x % 10;
            x /= 10;
        }
        return (result > INT_MAX || result < INT_MIN)? 0 : result;
    }
};
// @lc code=end
int main(int args, char **argv)
{
    cout << Solution().reverse(-123) << endl;
    cout << Solution().reverse(123) << endl;
}

