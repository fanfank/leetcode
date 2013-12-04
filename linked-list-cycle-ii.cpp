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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while(p2) {
            p2 = p2->next;
            if(p2 == NULL)
                return NULL;
            p2 = p2->next;
            p1 = p1->next;
            if(p1 == p2) {
                ListNode *p3 = head;
                while(p1 != p3) {
                    p1 = p1->next;
                    p3 = p3->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};