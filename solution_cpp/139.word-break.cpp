/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (39.44%)
 * Likes:    4124
 * Dislikes: 225
 * Total Accepted:    536.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dps(s.size()+1, false);
        dps[0] = true;
        unordered_map<int, unordered_set<string>> wordMap;
        for (const string &word : wordDict){
            wordMap[word.size()].insert(word);
        }
        for (int i=0; i<s.size(); ++i){
            for (auto iterator=wordMap.begin(); iterator!=wordMap.end(); ++iterator){
                int start = i - iterator->first + 1;
                if (start >= 0 && dps[start]){
                    if (iterator->second.find(s.substr(start, iterator->first)) != iterator->second.end()){
                        dps[i+1] = true;
                        break;
                    }
                }
            }
        }
        return dps[s.size()];
    }
};
// @lc code=end
int main(int argc, char **argv) {
    vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    string s = "catsandog";
    printf("%d\n", Solution().wordBreak(s, words));
    words = {"leet", "code"};
    s = "leetcode";
    printf("%d\n", Solution().wordBreak(s, words));
    words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    printf("%d\n", Solution().wordBreak(s, words));
    return 1;
}
