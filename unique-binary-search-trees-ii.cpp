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
    vector<TreeNode*> buildTree(int left, int right) {
        vector<TreeNode*> root;
        if(left > right) {
            root.push_back(NULL);
            return root;
        }
        for(int i = left; i <= right; ++i) {
            vector<TreeNode*> left_tree = buildTree(left, i - 1);
            vector<TreeNode*> right_tree = buildTree(i + 1, right);
            for(int j = 0; j < left_tree.size(); ++j) {
                for(int k = 0; k < right_tree.size(); ++k) {
                    TreeNode *r = new TreeNode(i);
                    r->left = left_tree[j];
                    r->right = right_tree[k];
                    root.push_back(r);
                }
            }
        }
        return root;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildTree(1, n);
    }
};