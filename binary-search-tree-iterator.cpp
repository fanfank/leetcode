/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> node_trace;
    BSTIterator(TreeNode *root) {
        TreeNode *node = root;
        while (node != NULL && node->left != NULL) {
            node_trace.push(node);
            node = node->left;
        }
        if (node != NULL) {
            node_trace.push(node);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !node_trace.empty();
    }

    /** @return the next smallest number */
    int next() {
        assert(hasNext());
        TreeNode *node = node_trace.top();
        int res = node->val;

        if (node->right != NULL) {
            node = node->right;
            while (node != NULL && node->left != NULL) {
                node_trace.push(node);
                node = node->left;
            }
            node_trace.push(node);
        } else {
            node_trace.pop();
            while (!node_trace.empty() && node_trace.top()->right == node) {
                node = node_trace.top();
                node_trace.pop();
            }
        }
        
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
