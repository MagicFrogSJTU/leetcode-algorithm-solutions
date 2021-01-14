/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (55.09%)
 * Likes:    3328
 * Dislikes: 174
 * Total Accepted:    659K
 * Total Submissions: 1.2M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto &s : strs){
            mp[strSort(s)].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }

    string strSort(const string &s){
        int count[26];
        for (int i=0;i<26;++i) count[i]=0;
        for (char l : s){
            count[l-'a']++;
        }
        string result;
        for (int i=0;i<26;++i){
            for (int j=0;j<count[i];++j){
                result.push_back('a'+i);
            }
        }
        return result;
    }
};
// @lc code=end
