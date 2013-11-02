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
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool f = true;
        checkBalance(root, 0, f);
        return f;
    }
    
private:
    int checkBalance(TreeNode *root, int level, bool &f) {
        if(root == NULL)
            return level - 1;
        int lheight = checkBalance(root->left, level + 1, f);
        if(f == false)
            return level;
        
        int rheight = checkBalance(root->right, level + 1, f);
        if(f == false)
            return level;
        
        if(abs(lheight - rheight) > 1)
            f = false;
        return max(lheight, rheight);
    }
};