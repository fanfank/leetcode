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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return judgeSame(p, q);
    }
    
private:
    bool judgeSame(TreeNode *p, TreeNode *q) {
        if((NULL == p && NULL != q) || (NULL != p && NULL == q))
            return false;
        if(NULL == p && NULL == q)
            return true;
        if(!judgeSame(p->left, q->left))
            return false;
        if(!judgeSame(p->right, q->right))
            return false;
        return p->val == q->val;
    }
};