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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        v.clear();
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        if(root)
            q.push(root);
        while(!q.empty() || !s.empty()) {
            while(!q.empty()) {
                TreeNode *tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                s.push(tmp);
            }
            if(!s.empty()) {
                if(s.top()->right)
                    q.push(s.top()->right);
                s.pop();
            }
        }
        return v;
    }
};