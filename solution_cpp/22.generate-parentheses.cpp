/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (61.70%)
 * Likes:    6449
 * Dislikes: 296
 * Total Accepted:    636K
 * Total Submissions: 991K
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string current;
        helper(current, 0, n, results);
        return results;
    }

    void helper(string &current, int l_now, int l_left, vector<string> &results)
    {
        if (!l_left && !l_now){
            results.push_back(current);
            return;
        }
        if (l_left){
            current.push_back('(');
            helper(current, l_now+1, l_left-1, results);
            current.pop_back();
        }
        if (l_now){
            current.push_back(')');
            helper(current, l_now-1, l_left, results);
            current.pop_back();
        }
    }
};
// @lc code=end
//
//
int main(int argc, char **argv)
{
    auto result = Solution().generateParenthesis(3);
    for (auto &str : result)
        cout << str << endl;
}
