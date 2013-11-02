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
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return pathSum(root, 0, sum);
    }
    
private:
    bool pathSum(TreeNode *root, int sum, const int ans) {
        if(root == NULL)
            return false;
        sum += root->val;
        bool isLeaf = true;
        if(root->left) {
            isLeaf = false;
            if(pathSum(root->left, sum, ans))
                return true;
        }
        if(root->right) {
            isLeaf = false;
            if(pathSum(root->right, sum, ans))
                return true;
        }
        if(isLeaf && sum == ans)
            return true;
        return false;
    }
};