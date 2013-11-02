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
    vector<int> v;
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        v.clear();
        if(root == NULL)
            return v;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            while(NULL != root->left) {
                root = root->left;
                s.push(root);
            }
            while(!s.empty()) {
                root = s.top();
                s.pop();
                v.push_back(root->val);
                if(NULL != root->right) {
                    root = root->right;
                    s.push(root);
                    break;
                }
            }
        }
        return v;
    }
};