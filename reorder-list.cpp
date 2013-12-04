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
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        int cnt = 0;
        ListNode *p1 = head, *p2 = head;
        while(p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(p2)
                p2 = p2->next;
        }
        p2 = reverseList(p1);
        p1 = head;
        while(p2) {
            ListNode *tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = tmp;
            p1 = tmp;
        }
        if(p1 != NULL && p1->next != NULL)
            p1->next = NULL;
    }
};