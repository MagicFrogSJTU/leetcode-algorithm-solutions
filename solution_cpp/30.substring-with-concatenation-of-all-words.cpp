/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (25.88%)
 * Likes:    1067
 * Dislikes: 1360
 * Total Accepted:    191.7K
 * Total Submissions: 740.5K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of
 * each word in words exactly once, in any order, and without any intervening
 * characters.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * Output: [6,9,12]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of lower-case English letters.
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * words[i] consists of lower-case English letters.
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        size_t wordSize = words[0].size();
        vector<int> results;
        if (wordSize > s.size()) return results;  // Edge case.

        unordered_map<string, int> cmapping;
        for (const string& word : words){
            if (cmapping.find(word) == cmapping.end()) cmapping[word] = 0;
            cmapping[word] += 1;
        }
        for (int i=0; i<wordSize; ++i){
            size_t fsize = words.size();
            unordered_map<string, int> mapping = cmapping; 
            for (int j=i; j<=s.size()-wordSize; j+=wordSize){  // Edge detection.
                const string cut = s.substr(j, wordSize);
                if (mapping.find(cut)!=mapping.end()){
                    if (mapping[cut]>0){
                        --mapping[cut];
                        --fsize;
                    }else{
                        for (int k=j-(words.size()-fsize)*wordSize; k<j; k+=wordSize){
                            const string recover = s.substr(k, wordSize);
                            if (recover == cut){
                                break;
                            }
                            if (mapping.find(recover)!=mapping.end()){
                                ++mapping[recover];
                                ++fsize;
                            }
                        }
                    }
                    if (!fsize) results.emplace_back(j-(words.size()-1)*wordSize);
                }else{
                    if (fsize != words.size()){
                        mapping = cmapping;
                        fsize = words.size();
                    }
                }
            }
        }
        return results;
    }
};
// @lc code=end
//
int main(int argc, char **argv)
{
    vector<string> words = {"ababa","babab"};
    auto results = Solution().findSubstring("ababababab", words);
    for (auto r : results)
        cout << r << endl;
    words = {"mississippis"};
    results = Solution().findSubstring("mississippi", words);
    for (auto r : results)
        cout << r << endl;
    return 1;
}
