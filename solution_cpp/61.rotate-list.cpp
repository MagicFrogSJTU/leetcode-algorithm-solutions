/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (29.17%)
 * Likes:    1095
 * Dislikes: 982
 * Total Accepted:    262.4K
 * Total Submissions: 889.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;

        ListNode null_head(0, head);
        ListNode *seg_head=&null_head, *seg_tail=&null_head;
        int i=0;
        while (seg_tail->next != nullptr && i<k){
            seg_tail = seg_tail->next;
            i++;
        }
        if (i<k || seg_tail->next == nullptr) {
            return rotateRight(head, k%i);
        }else {
            while (seg_tail->next != nullptr){
                seg_head = seg_head->next;
                seg_tail = seg_tail->next;
            }
            ListNode *new_head = seg_head->next;
            seg_head->next = nullptr;
            seg_tail->next = head;
            return new_head;
        }
        
    }
};
// @lc code=end
