class Solution {
    struct Node {
        Node** children;
        string* finish;
        int childnum;
        bool deleted;

        Node() {
            this->childnum = 0;
            this->deleted = false;
            this->children = NULL;
            this->finish = NULL;
        }
    };
    vector<string> ans;
    Node* root;
    int max_x, min_x, max_y, min_y;
public:
    /************ Implement a trie ****************/
    void insertToTrie(const string& s) {
        Node* cur = this->root;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            int index = c - 'a';
            if (cur->children == NULL) {
                cur->children = new Node*[26];
                for (int i = 0; i < 26; ++i) {
                    cur->children[i] = NULL;
                }
            }
            if (cur->children[index] == NULL) {
                cur->children[index] = new Node();
                cur->childnum += 1;
            }
            cur = cur->children[index];
        }
        cur->finish = new string(s);
    }

    void buildTrie(vector<string>& words) {
        this->root = new Node();
        for (vector<string>::iterator iter = words.begin(); 
                iter != words.end(); ++iter) {
            this->insertToTrie(*iter);
        }
    }

    void releaseTrie(Node* node) {
        if (node == NULL) {
            return;
        }

        if (node->children != NULL) {
            for (int i = 0; i < 26; ++i) {
                this->releaseTrie(node->children[i]);
            }
            delete node->children;
            node->children = NULL;
        }
        if (node->finish != NULL) {
            delete node->finish;
            node->finish = NULL;
        }

        delete node;
    }

    Node* locateChildTrie(Node* parent, int index) {
        if (parent == NULL || parent->children == NULL || parent->children[index] == NULL) {
            return NULL;
        }
        Node* child = parent->children[index];
        return child->deleted ? NULL : child;
    }
    
    void deleteFromTrie(string s, Node* parent, int index = 0) {
        Node* cur_node = this->locateChildTrie(parent, s[index] - 'a');
        if (cur_node == NULL || cur_node->deleted) {
            return;
        }

        if (index >= s.size() - 1) {
            delete cur_node->finish;
            cur_node->finish = NULL;
            if (cur_node->childnum == 0) {
                cur_node->deleted = true;
                parent->childnum--;
            }
            return;
        }

        this->deleteFromTrie(s, cur_node, index + 1);
        if (cur_node->childnum == 0) {
            cur_node->deleted = true;
            parent->childnum--;
        }
    }
    /************ Implement a trie end ****************/

    bool dofind(vector<vector<char> >& board, int x, int y, Node* parent) {
        if (x < this->min_x 
                || x > this->max_x 
                || y < this->min_y 
                || y > this->max_y) {
            return false;
        }

        char c = board[x][y];
        if (c == 0) {
            return false;
        }

        Node* cur_node = this->locateChildTrie(parent, c - 'a');
        if (cur_node == NULL || cur_node->deleted) {
            return false;
        }

        if (cur_node->finish != NULL) {
            // Found
            this->ans.push_back(*(cur_node->finish));
            this->deleteFromTrie(*(cur_node->finish), this->root);
        }

        board[x][y] = 0;
        if (!cur_node->deleted) this->dofind(board, x - 1,  y, cur_node);
        if (!cur_node->deleted) this->dofind(board, x + 1,  y, cur_node);
        if (!cur_node->deleted) this->dofind(board, x,  y - 1, cur_node);
        if (!cur_node->deleted) this->dofind(board, x,  y + 1, cur_node);
        board[x][y] = c;
        return true;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        min_x = min_y = 0;
        max_x = board.size() - 1;
        max_y = board[0].size() - 1;
        this->ans.clear();

        this->buildTrie(words);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                this->dofind(board, i, j, this->root);
            }
        }
        this->releaseTrie(this->root);
        this->root = NULL;
        return this->ans;
    }
};
