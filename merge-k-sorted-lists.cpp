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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(lists.size() == 0)
            return NULL;
        ListNode *head = NULL, **pHead = &head;
        while(true) {
            ListNode **tmp = &lists[0];
            for(int i = 1; i < lists.size(); ++i) {
                if(*tmp == NULL || (lists[i] != NULL && (*tmp)->val > lists[i]->val)) {
                    tmp = &lists[i];
                }
            }
            if(NULL == *tmp)
                break;
            *pHead = *tmp;
            *tmp = (*tmp)->next;
            pHead = &((*pHead)->next);
        }
        return head;
    }
};