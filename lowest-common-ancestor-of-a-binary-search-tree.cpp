/** 
 * Definition for a binary tree node.  
 * struct TreeNode { 
 *     int val; 
 *     TreeNode *left; 
 *     TreeNode *right; 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 * }; 
 */ 
//Solution 1: O(h) space, O(h) time, h is the height of tree
//          this solution uses node vals
class Solution { 
public: 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        if (root == NULL || p == NULL || q == NULL) {
            return NULL;
        }

        int left  = min(p->val, q->val);
        int right = max(p->val, q->val);
        return search(root, left, right);
    } 

    TreeNode* search(TreeNode* node, int left, int right) {
        if (node == NULL) {
            return NULL;
        }

        if ((left < node->val && right > node->val)
                || left == node->val || right == node->val) {
            return node;
        } else if (left < node->val && right < node->val) {
            return search(node->left, left, right);
        } else {
            return search(node->right, left, right);
        }
    }
};
