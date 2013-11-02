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
    int MAX = 0x7fffffff;
    vector<int> v1;
    vector<int> v2;
    void traverseLeft(TreeNode *root) {
        if(root == NULL) {
            v1.push_back(MAX);
            return;
        }
        v1.push_back(root->val);
        traverseLeft(root->left);
        traverseLeft(root->right);
    }
    void traverseRight(TreeNode *root) {
        if(root == NULL) {
            v2.push_back(MAX);
            return;
        }
        v2.push_back(root->val);
        traverseRight(root->right);
        traverseRight(root->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        v1.clear(); v2.clear();
        traverseLeft(root);
        traverseRight(root);
        for(int i = 0; i < v1.size(); i++)
            if(v1[i] != v2[i])
                return false;
        return true;
    }
};
