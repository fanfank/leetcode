/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildBST(ListNode *st, ListNode *ed) {
        if(st == NULL || st == ed) {
            return NULL;
        }
        ListNode *pFast = st, *pSlow = st;
        while(pFast != ed && pFast->next != ed) {
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        TreeNode *root = new TreeNode(pSlow->val);
        root->left = buildBST(st, pSlow);
        root->right = buildBST(pSlow->next, ed);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
            return NULL;
        return buildBST(head, NULL);
    }
};