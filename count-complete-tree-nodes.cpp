/** 
 * Definition for a binary tree node.  
 * struct TreeNode { 
 *     int val; 
 *     TreeNode *left; 
 *     TreeNode *right; 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
 * }; 
 */ 
//Solution 0: Olog(N) space, O(log(N) * log(N)) time, 88ms
class Solution { 
public: 
    int height = 0;
    int countNodes(TreeNode* root) { 
        TreeNode* p = root;
        height = 0;
        while (p != NULL) {
            ++height;
            p = p->left;
        }

        return _countNodes(root, 1);
    } 

private:
    int _countNodes(TreeNode* root, const int cur_height) {
        if (root == NULL) {
            return 0;
        }

        TreeNode* check_bound  = root->right;
        int check_bound_height = cur_height;
        while (check_bound != NULL) {
            ++check_bound_height;
            check_bound = check_bound->left;
        }

        //use << is much faster
        if (check_bound_height == height) {
            return (1 << (height - cur_height))
                    + _countNodes(root->right, cur_height + 1);
        } else {
            return (1 << (height - cur_height - 1))
                    + _countNodes(root->left, cur_height + 1);
        }
    }
};

//Solution 1: Olog(N) space, O(log(N) * log(N)) time, 80ms
//similar to binary search
class Solution { 
public: 
    int height = 0;
    int countNodes(TreeNode* root) { 
        TreeNode* p = root;
        height = 0;
        while (p != NULL) {
            ++height;
            p = p->left;
        }

        return _countNodes(root, 1);
    } 

private:
    int _countNodes(TreeNode* root, const int cur_height) {
        if (root == NULL) {
            return 0;
        }

        if (cur_height >= height - 1) {
            int res = 1;
            res += root->left == NULL ? 0 : 1;
            res += root->right == NULL ? 0 : 1;
            return res;
        }

        TreeNode* check_bound  = root->right;
        int check_bound_height = cur_height;
        int bound_status = -1; //1 -> bound found
                               //2 -> deepest layer missing
                               //3 -> deepest layer filled
        while (true) {
            ++check_bound_height;
            if (check_bound_height == height - 1) {
                if (check_bound->right != NULL) {
                    bound_status = 3;
                } else if (check_bound->left != NULL) {
                    bound_status = 1;
                } else {
                    bound_status = 2;
                }
                break;
            }
            check_bound = check_bound->left;
        }

        //use << is much faster
        switch (bound_status) {
        case 1:
            return (1 << (height - cur_height))
                    + (1 << (height - cur_height - 1));
        case 2:
            return (1 << (height - cur_height - 1))
                    + _countNodes(root->left, cur_height + 1);
        case 3:
            return (1 << (height - cur_height))
                    + _countNodes(root->right, cur_height + 1);
        }
    }
};


//Solution 1: Olog(N) space, O(log(N) * log(N)) time, 156ms
//Inspired by: https://leetcode.com/discuss/38899/easy-short-c-recursive-solution
//Actually rewriten the refered one
class Solution { 
public: 
    int countNodes(TreeNode* root) { 
        if (root == NULL) {
            return 0;
        }

        int left_height = 0, right_height = 0;
        TreeNode* left  = root->left;
        TreeNode* right = root->right;
        while (left != NULL) {
            ++left_height;
            left = left->left;
        }
        while (right != NULL) {
            ++right_height;
            right = right->right;
        }
        
        //use << is much faster
        if (left_height == right_height) {
            return (1 << (left_height + 1)) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    } 
};
