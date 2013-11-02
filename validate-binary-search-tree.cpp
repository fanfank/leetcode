/*
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
    const int MAX = 0x7fffffff;
    const int MIN = 0x80000000;
    bool traverse(TreeNode *root, int lowBound, int highBound) {
        if(root->val <= lowBound || root->val >= highBound)
            return false;
        if(root->left != NULL) {
            if(traverse(root->left, lowBound, root->val) == false)
                return false;
        }
        if(root->right != NULL) {
            if(traverse(root->right, root->val, highBound) == false)
                return false;
        }
        return true;
    }
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
            return true;
        return traverse(root, MIN, MAX);
    }
};
