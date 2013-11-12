/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == NULL)
            return;
        TreeLinkNode *leftmost = NULL;
        while(root != NULL && root->left == NULL && root->right == NULL)
            root = root->next;
        if(root == NULL)
            return;
        leftmost = root->left?root->left:root->right;
        TreeLinkNode *p = leftmost;
        if(p == root->left && root->right) {
            p->next = root->right;
            p = p->next;
        }
        while(root->next) {
            root = root->next;
            if(root->left) {
                p->next = root->left;
                p = p->next;
            }
            if(root->right) {
                p->next = root->right;
                p = p->next;
            }
        }
        connect(leftmost);
    }
};