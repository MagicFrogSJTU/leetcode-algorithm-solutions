/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (35.61%)
 * Likes:    1264
 * Dislikes: 295
 * Total Accepted:    169.9K
 * Total Submissions: 476.7K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
#include <iostream>
#include <climits>
#include <map>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;


// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        int pTable[10] = {1};
        for(int i = 1; i <= 9; i++){
                pTable[i] = i * pTable[i - 1];
                
        }
        string result;
        vector<char> numSet;
        numSet.push_back('1');
        numSet.push_back('2');
        numSet.push_back('3');
        numSet.push_back('4');
        numSet.push_back('5');
        numSet.push_back('6');
        numSet.push_back('7');
        numSet.push_back('8');
        numSet.push_back('9');
        for (int i=n; i>0; --i){
            int temp = (k - 1) / pTable[i - 1];
            result += numSet[temp];
            numSet.erase(numSet.begin() + temp);
            k = k - temp * pTable[i - 1];
        }
        return result;
        
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    cout << Solution().getPermutation(4, 4) << endl;
    return 0;
}
