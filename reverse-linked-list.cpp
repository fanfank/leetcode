/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Solution 1: iterative solution, 11ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre  = NULL;
        ListNode* cur  = head;
        ListNode* next = NULL;
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next      = pre;
            pre            = cur;
            cur            = next;
        }
        
        return pre;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Solution 2: recursive solution, 10ms
class Solution {
public:
    ListNode* ans = NULL;
    ListNode* reverseList(ListNode* head) {
        reverse(NULL, head);
        return ans;
    }

    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL) {
            ans = pre;
            return pre;
        }
        reverse(cur, cur->next)->next = pre;
    }
};
