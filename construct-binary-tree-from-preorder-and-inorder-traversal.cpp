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
    TreeNode *rebuild(vector<int> &preorder, int pleft, int prightp1, vector<int> &inorder, int ileft, int irightp1) {
        if(pleft >= prightp1)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pleft]);
        int root_index = ileft;
        while(inorder[root_index] != root->val) {
            root_index++;
        }
        root->left = rebuild(preorder, pleft + 1, pleft + 1 + root_index - ileft, inorder, ileft, root_index);
        root->right = rebuild(preorder, pleft + 1 + root_index - ileft, prightp1, inorder, root_index + 1, irightp1);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return rebuild(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};