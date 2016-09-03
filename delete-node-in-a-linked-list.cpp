/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Delete the next node
        ListNode* toBeDeleted = node->next;
        node->next = toBeDeleted->next;
        node->val = toBeDeleted->val;
        delete toBeDeleted;
    }
};
