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
    TreeNode *pre;
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
            return;
        pre = root;
        TreeNode *r = root->right;
        if(root->left != NULL) {
            root->right = root->left;
            flatten(root->left);
        }
        if(r != NULL) {
            pre->right = r;
            flatten(r);
        }
        root->left = NULL;
    }
};
