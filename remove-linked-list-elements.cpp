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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** p_cur  = &head;
        while (*p_cur != NULL) {
            if ((*p_cur)->val == val) {
                ListNode* del_node = *p_cur;
                *p_cur = (*p_cur)->next;
                delete del_node;
            } else {
                p_cur = &((*p_cur)->next);
            }
        }

        return head;
    }
};
