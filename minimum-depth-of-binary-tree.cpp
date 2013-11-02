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
    int minLevel;
    void traverse(TreeNode *root, int level) {
        if(level >= minLevel)
            return;
        bool isLeaf = true;
        if(root->left) {
            isLeaf = false;
            traverse(root->left, level + 1);
        }
        if(root->right) {
            isLeaf = false;
            traverse(root->right, level + 1);
        }
        if(isLeaf) {
            minLevel = level;
        }
    }
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
            return 0;
        minLevel = 0x7fffffff;
        traverse(root, 1);
        return minLevel;
    }
};
