/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (41.90%)
 * Likes:    3726
 * Dislikes: 53
 * Total Accepted:    270.6K
 * Total Submissions: 616.4K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;


// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dps(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i=1; i<word1.size()+1; ++i){
            dps[i][0] = i;
        }
        for (int i=1; i<word2.size()+1; ++i){
            dps[0][i] = i;
        }
        for (int i=1; i<word1.size()+1; ++i){
            for (int j=1; j<word2.size()+1; ++j){
                if (word1[i-1] == word2[j-1]) dps[i][j] = min(dps[i-1][j-1], min(dps[i-1][j]+1, dps[i][j-1]+1));
                else dps[i][j] = min(dps[i-1][j-1]+1, min(dps[i-1][j]+1, dps[i][j-1]+1));
            }
        }
        return dps[word1.size()][word2.size()];
    }
};
// @lc code=end
//
int main(int argc, char **argv)
{
    cout << Solution().minDistance("intention", "execution") << endl;
    return 1;
}
