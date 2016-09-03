/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution 1
class Solution {
public:
    TreeNode* findLCA(TreeNode* node, TreeNode* p, TreeNode* q, bool& foundP, bool& foundQ) {
        if (node == NULL) {
            return NULL;
        }

        TreeNode* res = NULL;
        bool enterFoundP = foundP;
        bool enterFoundQ = foundQ;

        // find children first
        if (node->left) {
            res = findLCA(node->left, p, q, foundP, foundQ);
            if (res) {
                return res;
            }
        }

        if (node->right) {
            res = findLCA(node->right, p, q, foundP, foundQ);
            if (res) {
                return res;
            }
        }

        if (node == p) {
            foundP = true;
        }
        if (node == q) {
            foundQ = true;
        }

        if (foundP && foundQ && !enterFoundP && !enterFoundQ) {
            return node;
        }

        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool foundP = false;
        bool foundQ = false;
        return findLCA(root, p, q, foundP, foundQ);
    }
};

// Solution 2: https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
