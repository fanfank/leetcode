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
    TreeNode *buildTree(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr)
    {
        if(il > ir || pl > pr)
            return NULL;
        int proot = pr, iroot = ir;
        while(inorder[iroot] != postorder[proot]) 
            {iroot--;}

        int rightCnt = ir - iroot, pright = proot - rightCnt;
            
        TreeNode *root = new TreeNode(postorder[proot]);
        root->left = buildTree(inorder, il, iroot - 1, postorder, pl, pright - 1);
        root->right = buildTree(inorder, iroot + 1, ir, postorder, pright, proot - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.empty() || postorder.empty())
            return NULL;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
