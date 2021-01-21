/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (45.38%)
 * Likes:    3622
 * Dislikes: 397
 * Total Accepted:    582.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(const string digits) {
        if (digits.size() == 0){
            return {};
        }
        string sample = digits;
        vector<string> res;
        helper(digits, 0, sample, res);
        return res;
    }

    const vector<vector<char>> mapping = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    void helper(const string &digits, int current, string &sample, vector<string> &res)
    {
        if (current == digits.size()){
            res.push_back(sample);
            return;
        }
        for (const auto i : mapping[digits[current] - '2'])
        {
            sample[current] = i;
            helper(digits, current+1, sample, res);
        }
    }
};
// @lc code=end

// WFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return {};
        }
        const vector<vector<char>> mapping = {{'a','b','c'}, {'d','e','f'}, {'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        vector<string> before = letterCombinations(digits.substr(0, digits.size()-1));
        if (before.size() == 0) before = {""};
        vector<string> res;
        for (char next : mapping[digits[digits.size()-1]-'2']){
            for (const string &l : before){
                res.push_back(l + next);
            }
        }
        return res;
    }
};
