/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (48.66%)
 * Likes:    504
 * Dislikes: 959
 * Total Accepted:    84K
 * Total Submissions: 172.3K
 * Testcase Example:  '2'
 *
 * Given a non-negative integer n, count all numbers with unique digits, x,
 * where 0 ≤ x < 10^n.
 * 
 * 
 * Example:
 * 
 * 
 * Input: 2
 * Output: 91 
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, 
 * excluding 11,22,33,44,55,66,77,88,99
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 8
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
    static vector<int> dps;
    int countNumbersWithUniqueDigits(int n) {
        if (dps[2] == -1){
            // 在这个位置，有多少以非零开头的数字
            // 想象新增的数字在最右边。
            for (int i=2; i<9; ++i) dps[i] = dps[i-1] * (11-i);

            // 加起来
            for (int i=1; i<9; ++i) dps[i] = dps[i] + dps[i-1];
        }
        return dps[n];
    }
};

vector<int> Solution::dps = {1, 9, -1, -1, -1, -1, -1, -1, -1};
// @lc code=end
int main(int argc, char **argv)
{
    cout << Solution().countNumbersWithUniqueDigits(2) << endl;
    return 0;
}
