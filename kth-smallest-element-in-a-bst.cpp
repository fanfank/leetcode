/** 
 * Definition for a binary tree node.  
 * struct TreeNode { 
 *     int val; 
 *     TreeNode *left; 
 *     TreeNode *right; 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 * }; 
 */ 
class Solution { 
public: 
    int kthSmallest(TreeNode* root, int k) { 
        return k_inorder(root, k);
    } 
    int k_inorder(TreeNode* root, int& k) {
        if (root == NULL) {
            return 0;
        }

        int res = 0;

        //left
        res = k_inorder(root->left, k);
        if (k == 0) {
            return res;
        }

        //current
        if (--k == 0) {
            return root->val;
        }

        //right
        return k_inorder(root->right, k);
    }
};
