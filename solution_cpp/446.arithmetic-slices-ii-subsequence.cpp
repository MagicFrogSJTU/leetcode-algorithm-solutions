/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 *
 * https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/
 *
 * algorithms
 * Hard (33.08%)
 * Likes:    602
 * Dislikes: 62
 * Total Accepted:    23.7K
 * Total Submissions: 71.2K
 * Testcase Example:  '[2,4,6,8,10]'
 *
 * A sequence of numbers is called arithmetic if it consists of at least three
 * elements and if the difference between any two consecutive elements is the
 * same.
 * 
 * For example, these are arithmetic sequences:
 * 
 * 
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic.
 * 
 * 
 * 1, 1, 2, 5, 7
 * 
 * 
 * A zero-indexed array A consisting of N numbers is given. A subsequence slice
 * of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0
 * < P1 < ... < Pk < N.
 * 
 * A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the
 * sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular,
 * this means that k ≥ 2.
 * 
 * The function should return the number of arithmetic subsequence slices in
 * the array A.
 * 
 * The input contains N integers. Every integer is in the range of -2^31 and
 * 2^31-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 2^31-1.
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2, 4, 6, 8, 10]
 * 
 * Output: 7
 * 
 * Explanation:
 * All arithmetic subsequence slices are:
 * [2,4,6]
 * [4,6,8]
 * [6,8,10]
 * [2,4,6,8]
 * [4,6,8,10]
 * [2,4,6,8,10]
 * [2,6,10]
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
// O(n^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<unordered_map<long long, int>> dps(A.size()); // each value is target-1;
        
        int result(0);
        for (int i=1; i<A.size(); ++i){
            for (int j=0; j<i; ++j){
                long long diff = static_cast<long long>(A[i]) - static_cast<long long>(A[j]);
                if (dps[j].find(diff) != dps[j].end()){
                    dps[i][diff] += dps[j][diff];
                    result += dps[j][diff];
                }else{
                    dps[i][diff] += 1;
                }
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    vector<int> A={2,2,3,4};
    cout << Solution().numberOfArithmeticSlices(A) << endl;
    A={2,4,6,8,10};
    cout << Solution().numberOfArithmeticSlices(A) << endl;
    return 0;
}
