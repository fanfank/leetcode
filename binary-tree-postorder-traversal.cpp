/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//Trick is that root=>s2, root->right=>s2, root->left=>s2
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        v.clear();
        queue<TreeNode*> q;
        stack<TreeNode*> s1, s2;
        if(root)
            q.push(root);
        while(!q.empty() || !s1.empty()) {
            while(!q.empty()) {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->right)
                    q.push(tmp->right);
                s1.push(tmp);
                s2.push(tmp);
            }
            if(!s1.empty()) {
                TreeNode *tmp = s1.top();
                s1.pop();
                if(tmp->left)
                    q.push(tmp->left);
            }
        }
        while(!s2.empty()) {
            v.push_back(s2.top()->val);
            s2.pop();
        }
        return v;
    }
};