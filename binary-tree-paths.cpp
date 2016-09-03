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
    void buildPaths(TreeNode* root, vector<string>& res, vector<string>& path) {
        if (root == NULL) {
            return;
        }

        if (path.empty()) {
            path.push_back(to_string(root->val));
        } else {
            path.push_back("->" + to_string(root->val));
        }

        if (root->left == NULL && root->right == NULL) {
            string target("");
            for (int i = 0; i < path.size(); ++i) {
                target += path[i];
            }
            res.push_back(target);
        } else {
            if (root->left) buildPaths(root->left, res, path);
            if (root->right) buildPaths(root->right, res, path);
        }
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<string> path;
        buildPaths(root, res, path);
        return res;
    }
};
