/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (41.19%)
 * Likes:    2928
 * Dislikes: 379
 * Total Accepted:    304.7K
 * Total Submissions: 699.5K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 * 
 * Follow up:
 * 
 * 
 * Could you solve the problem in O(1) extra memory space?
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1], k = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
 * 
 * 
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0,  head);
        ListNode *tail = &dummy;

        while (tail)
        {
            ListNode *next_head = tail->next;
            ListNode *next_tail = tail->next;
            for (int i=0; i<k; ++i)
            {
                if (!next_tail) return dummy.next;
                next_tail = next_tail->next;
            }
            ListNode *iter = tail->next;
            for (int i=0; i<k; ++i)
            {
                ListNode *buf = iter->next;
                iter->next = next_tail;
                next_tail = iter;
                iter = buf;
            }
            tail->next = next_tail;
            tail = next_head;
        }
        return dummy.next;
        
    }
};
// @lc code=end

int main(int argc, char** argv)
{
    ListNode dummy(0, nullptr);
    ListNode *tail = &dummy;
    int values[] = {1, 2, 3, 4, 5};
    for (int i=0;i<5;++i)
    {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }
    tail = dummy.next;
    while (tail)
    {
        cout << tail->val << endl;
        tail = tail->next;
    }
    ListNode *result = Solution().reverseKGroup(dummy.next, 2);
    cout << "result: \n";
    tail = result;
    while (tail)
    {
        cout << tail->val << endl;
        tail = tail->next;
    }

    return 0;
}
