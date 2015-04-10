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
    vector<int> res;
    vector<int> rightSideView(TreeNode *root) {
        //先序遍历，右子树优先于左子树被遍历
        //Preorder-Traverse the tree from right to left
        //time: O(n)
        //space: O(h)
        //8ms
        res.clear();
        preorder_right(root, 0);
        return res;
    }

    void preorder_right(TreeNode *root, int depth) {
        if (root == NULL) {
            return;
        }

        if (res.size() <= depth) {
            res.push_back(root->val);
        }

        preorder_right(root->right, depth + 1);
        preorder_right(root->left, depth + 1);
    }
};
