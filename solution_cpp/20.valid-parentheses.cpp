/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.29%)
 * Likes:    4739
 * Dislikes: 211
 * Total Accepted:    966.5K
 * Total Submissions: 2.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */

// @lc code=start
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> container;
        for (auto c : s)
        {
            switch (c){
                case '(':
                case '[':
                case '{':
                    container.push(c);
                    break;
                case ')':
                    if (container.empty() || container.top() != '(') return false; else container.pop(); break;
                case ']':
                    if (container.empty() || container.top() != '[') return false; else container.pop(); break;
                case '}':
                    if (container.empty() || container.top() != '{') return false; else container.pop(); break;
            }
        }
        return container.empty();
    }
};
// @lc code=end
