/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (31.08%)
 * Likes:    1847
 * Dislikes: 372
 * Total Accepted:    228.9K
 * Total Submissions: 735.5K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        int max_len = 0;
        unordered_set<string> dict;
        for(string& str : wordDict)
        {
            dict.insert(str);
            max_len = max(max_len, (int)str.length());
        }

        unordered_map<int, vector<string>> mp;
        return break_word(s, 0, dict, max_len, mp);
    }

protected:
    vector<string> break_word(  const string& s, int n, unordered_set<string>& dict, 
                                int max_len, unordered_map<int, vector<string>>& mp)
    {
        if(mp.count(n)) return mp[n];

        string str;
        for(int i = n; i < s.length() && str.length() <= max_len; ++i)
        {
            str += s[i];
            if(dict.count(str))
            {
                if(i == s.length()-1)
                    mp[n].push_back(str);
                else
                {
                    vector<string> vs = break_word(s, i+1, dict, max_len, mp);
                    for(auto& a : vs) mp[n].push_back(str + " " + a);
                }
            }
        }
        return mp[n];
    }

};
// @lc code=end
int main(int argc, char **argv) {
    vector<string> words = {"cats", "dog", "sand", "and", "cat"};
    string s = "catsandog";
    auto results = Solution().wordBreak(s, words);
    for (auto r : results)
        cout << r << endl;
    cout << "end\n";

    s = "pineapplepenapple";
    words = {"apple", "pen", "applepen", "pine", "pineapple"};
    results = Solution().wordBreak(s, words);
    for (auto r : results)
        cout << r << endl;
    cout << "end\n";

    words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    return 0;
}
