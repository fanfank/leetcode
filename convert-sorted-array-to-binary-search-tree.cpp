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
    TreeNode *buildBST(int left, int rightp1, vector<int> &num) {
        if(left >= rightp1)
            return NULL;
        int middle = left + (rightp1 - left) / 2;
        TreeNode *root = new TreeNode(num[middle]);
        root->left = buildBST(left, middle, num);
        root->right = buildBST(middle + 1, rightp1, num);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(num.size() == 0)
            return NULL;
        return buildBST(0, num.size(), num);
    }
};