/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (49.68%)
 * Likes:    2870
 * Dislikes: 185
 * Total Accepted:    525.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes. Only nodes itself may be
 * changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 100].
 * 0 <= Node.val <= 100
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *buf = head->next;
        head->next = swapPairs(buf->next);
        buf->next = head;
        return buf;
    }
};
// @lc code=end
