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
    vector<vector<int> > vv;
    void levelTraverse(TreeNode *root, int level) {
        if(root == NULL)
            return;
        if(vv.size() <= level) {
            vv.push_back(vector<int>());
        }
        vv[level].push_back(root->val);
        levelTraverse(root->left, level + 1);
        levelTraverse(root->right, level + 1);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vv.clear();
        levelTraverse(root, 0);
        int hd = 0, tl = vv.size() - 1;
        while(hd < tl) {
            swap(vv[hd++], vv[tl--]);
        }
        return vv;
    }
};