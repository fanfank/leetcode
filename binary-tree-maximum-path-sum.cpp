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
    int ans;
    int traverse(TreeNode *root) {
        if(root == NULL)
            return 0;
        int sum = root->val;
        int leftsum = traverse(root->left);
        int rightsum = traverse(root->right);
        if(leftsum > 0)
            sum += leftsum;
        if(rightsum > 0)
            sum += rightsum;
        ans = max(sum, ans);
        sum = (leftsum>rightsum?leftsum:rightsum);
        return (root->val + (sum>0?sum:0));
    }
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ans = 0x80000000;
        traverse(root);
        return ans;
    }
};