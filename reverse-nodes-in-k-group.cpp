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
    ListNode *reverse(ListNode *head, ListNode *stop, ListNode *last)
    {
        ListNode *pre = NULL, *cur = head, *next;
        while(cur != stop) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if(last != NULL)
            last->next = pre;
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
            return NULL;
        ListNode *newHead = head, *stop = head, *last = NULL;
        int cnt = k - 1;
        bool firsttime = true;
        while(true) {
            while(cnt && (stop != NULL)) {
                stop = stop->next;
                --cnt;
            }
            if(cnt > 0 || stop == NULL)
                break;
            if(firsttime) {
                head = stop;
                firsttime = false;
            }
            stop = stop->next;
            reverse(newHead, stop, last)->next = stop;
            last = newHead;
            newHead = stop;
            cnt = k - 1;
        }
        return head;
    }
};
