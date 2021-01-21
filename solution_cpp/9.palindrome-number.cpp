/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (47.18%)
 * Total Accepted:    896.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '121'
 *
 * <p>Determine whether an integer is a palindrome. An
 * integer&nbsp;is&nbsp;a&nbsp;palindrome when it&nbsp;reads the same backward
 * as forward.</p>
 *
 * <p><strong>Example 1:</strong></p>
 *
 * <pre>
 * <strong>Input:</strong> 121
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre>
 * <strong>Input:</strong> -121
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> From left to right, it reads -121. From right
 * to left, it becomes 121-. Therefore it is not a palindrome.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre>
 * <strong>Input:</strong> 10
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> Reads 01 from right to left. Therefore it is
 * not a palindrome.
 * </pre>
 *
 * <p><strong>Follow up:</strong></p>
 *
 * <p>Coud you solve&nbsp;it without converting the integer to a string?</p>
 *
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if ((x < 0) || (x>0 && x%10==0)) return false;
        int half = 0;
        while (x > half){
            half=half*10+x%10;
            x/=10;
        }
        return (x==half || x==(half/10));
    }
};
