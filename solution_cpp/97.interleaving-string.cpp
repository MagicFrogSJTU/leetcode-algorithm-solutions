/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (30.48%)
 * Likes:    1327
 * Dislikes: 81
 * Total Accepted:    148.5K
 * Total Submissions: 479.7K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size() != s3.size()) return false;

        vector<vector<bool>> dps(s1.size()+1, vector<bool>(s2.size()+1, false));
        dps[0][0] = true;
        for (int i=0; i<s2.size(); ++i){
            if (s3[i] == s2[i]) dps[0][i+1] = true;
            else break;
        }
        for (int i=0; i<s1.size(); ++i){
            if (s3[i] == s1[i]) dps[i+1][0] = true;
            else break;
        }
        for (int i=1; i<s1.size()+1; ++i){
            for (int j=1; j<s2.size()+1; ++j){
                dps[i][j] = (dps[i][j-1] && s2[j-1]==s3[i+j-1]) || (dps[i-1][j] && s1[i-1]==s3[i+j-1]);
            }
        }
        return dps[s1.size()][s2.size()];
        
    }
};
// @lc code=end
