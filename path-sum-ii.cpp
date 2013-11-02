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
    vector<int> v;
    vector<vector<int> > vv;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        v.clear(), vv.clear();
        pathSums(root, 0, sum);
        return vv;
    }
    
private:
    void pathSums(TreeNode *root, int sum, const int ans) {
        if(root == 0)
            return;
        v.push_back(root->val);
        sum += root->val;
        bool isLeaf = true;
        if(root->left) {
            isLeaf = false;
            pathSums(root->left, sum, ans);
        }
        if(root->right) {
            isLeaf = false;
            pathSums(root->right, sum, ans);
        }
        if(isLeaf && sum == ans)
            vv.push_back(v);
        v.pop_back();
    }
};