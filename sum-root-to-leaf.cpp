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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        
        int total = 0;
        sum = 0;
        dfs(root, total);
        return sum;
    }

private:
    int sum;
    void dfs(TreeNode *node, int &total)
    {
        bool isLeaf = true;
        total = total * 10 + node->val;
        if(node->left)
        {
            isLeaf = false;
            dfs(node->left, total);
        }
        if(node->right)
        {
            isLeaf = false;
            dfs(node->right, total);
        }
        if(isLeaf)
            sum += total;
        total /= 10;
    }
};

