/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//O(1) space
class Solution {
public:
    vector<TreeNode*> v;  //push at most 2 elements
    TreeNode *last;
    void traverse(TreeNode *root) {
        if(root == NULL)
            return;
        traverse(root->left);
        if(last == NULL) {
            //just do nothing
        }
        else if(v.size() == 0) {
            if(root->val < last->val) {
                v.push_back(last);
                v.push_back(root);
            }
        }
        else {
            if(root->val < last->val) {
                v[1] = root;
            }
        }
        last = root;
        traverse(root->right);
    }
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        v.clear();
        last = NULL;
        traverse(root);
        swap(v[0]->val, v[1]->val);
    }
};
