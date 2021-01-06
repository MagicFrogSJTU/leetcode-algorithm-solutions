/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (37.18%)
 * Likes:    1152
 * Dislikes: 53
 * Total Accepted:    133K
 * Total Submissions: 352.9K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * It's guaranteed the answer fits on a 32-bit signed integer.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        if (!t.size()) return 1;

        vector<vector<size_t>> dps(t.size(), vector<size_t>(s.size(), 0));

        dps[0][0] = s[0] == t[0];
        for (int i=1; i<s.size(); ++i){
            dps[0][i] = dps[0][i-1];
            if (s[i]==t[0]) dps[0][i]+=1;
        }
        for (int i=1; i<t.size(); ++i){
            for (int j=i; j<s.size()-(t.size()-i-1); ++j){
                dps[i][j] = dps[i][j-1];
                if (s[j] == t[i]) dps[i][j] += dps[i-1][j-1];
            }
        }
        return dps[t.size()-1][s.size()-1];
    }
};
// @lc code=end
