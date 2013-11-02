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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        v.clear(), vv.clear();
        int ltr = 1;
        stack<TreeNode*> s[2];
        if(root != NULL)
            s[ltr].push(root);
        
        while(!s[ltr].empty()) {
            //ltr ^= 1;
            v.clear();
            while(!s[ltr].empty()) {
                TreeNode *tmp = s[ltr].top();
                s[ltr].pop();
                Push(s[1^ltr], tmp, ltr);
                v.push_back(tmp->val);
            }
            vv.push_back(v);
            ltr ^= 1;
        }
        return vv;
    }
    
private:
    vector<int> v;
    vector<vector<int> > vv;
    void Push(stack<TreeNode*> &s, TreeNode *node, int ltr) {
        if(ltr) {
            if(node->left != NULL)
                s.push(node->left);
            if(node->right != NULL)
                s.push(node->right);
        } else {
            if(node->right != NULL)
                s.push(node->right);
            if(node->left != NULL)
                s.push(node->left);
        }
    }
};