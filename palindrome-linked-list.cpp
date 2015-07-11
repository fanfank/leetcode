/** 
 * Definition for singly-linked list.  
 * struct ListNode { 
 *     int val; 
 *     ListNode *next; 
 *     ListNode(int x) : val(x), next(NULL) {} 
 * }; 
 */ 
class Solution { //O(5n) time, O(1) space
public: 
    bool isPalindrome(ListNode* head) { 
        int node_num = 0;

        //O(n) compute list length
        ListNode* tmp = head;
        while (tmp != NULL) {
            tmp = tmp->next;
            ++node_num;
        }
        if (node_num <= 1) {
            return true;
        }
        
        //O(n) split into two lists
        tmp = head;
        ListNode* revert_head = NULL;
        ListNode* forward_head = NULL;
        ListNode* middle_node = NULL;
        int current_index = 1;
        int revert_head_index = node_num / 2;
        int forward_head_index = (node_num + 1) / 2 + 1;
        while (current_index < revert_head_index && tmp != NULL) {
            tmp = tmp->next;
            ++current_index;
        }
        revert_head = tmp;
        middle_node = tmp->next;

        while (current_index < forward_head_index && tmp != NULL) {
            tmp = tmp->next;
            ++current_index;
        }
        forward_head = tmp;

        //O(n) revert the first half list
        revertList(head, revert_head);

        //O(n) compare two lists
        ListNode* tmp_revert_node = revert_head;
        ListNode* tmp_forward_node = forward_head;
        bool is_palindrome = true;
        while (tmp_revert_node != NULL) {
            if (tmp_revert_node->val != tmp_forward_node->val) {
                is_palindrome = false;
                break;
            }
            tmp_revert_node  = tmp_revert_node->next;
            tmp_forward_node = tmp_forward_node->next;
        }

        //O(n) reset the list so that the original program can free the memory
        revertList(revert_head, head);
        revert_head->next = middle_node;

        return is_palindrome;
    } 

    void revertList(ListNode* head, ListNode* tail) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nxt = NULL;
        while (cur != NULL && pre != tail) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
    }
};
