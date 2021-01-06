/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (29.90%)
 * Likes:    1032
 * Dislikes: 32
 * Total Accepted:    128.8K
 * Total Submissions: 430.8K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1) return 0;

        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        isPalindrome[0][0] = true;
        vector<int> dps(s.size()+1, INT_MAX);
        dps[0] = -1;
        dps[1] = 0;
        for (int i=1; i<s.size(); ++i){
            isPalindrome[i][i] = true;
            if (s[i] == s[i-1]) isPalindrome[i][i-1] = true;
            for (int j=0; j<i-1; ++j){
                isPalindrome[i][j] = isPalindrome[i-1][j+1] && s[i]==s[j];
            }
            for (int j=0; j<=i; ++j){
                if (isPalindrome[i][j]) dps[i+1] = min(dps[i+1], dps[j]+1);
            }
        }
        return dps[s.size()];
    }
};
// @lc code=end
