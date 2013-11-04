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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int add = 0;
        ListNode **p = &l1;
        while(*p && l2) {
            (*p)->val += add + l2->val;
            if((*p)->val > 9) {
                add = 1;
                (*p)->val -= 10;
            } else
                add = 0;
            p = &((*p)->next);
            l2 = l2->next;
        }
        if(l2) {
            *p = l2;
        }
        while(*p && add) {
            (*p)->val += add;
            if((*p)->val > 9) {
                (*p)->val -= 10;
            } else {
                add = 0;
                break;
            }
            p = &((*p)->next);
        }
        if(add) {
            *p = new ListNode(add);
        }
        return l1;
    }
};