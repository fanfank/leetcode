class TrieNode { 
public: 
    // Initialize your data structure here.  
    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
        }
    } 

    int count;
    TrieNode* next[26];
}; 

class Trie { 
public: 
    Trie() { 
        root = new TrieNode();
    } 

    ~Trie() {
        this->deleteNodes(root);
    }

    // Inserts a word into the trie.  
    void insert(string key) { 
        TrieNode* cur = this->root;
        for (size_t i = 0; i < key.size(); ++i) {
            if (cur->next[key[i]-'a'] == NULL) {
                cur->next[key[i]-'a'] = new TrieNode();
            }
            cur = cur->next[key[i]-'a'];
        }
        ++cur->count;
    } 

    // Returns if the word is in the trie.  
    bool search(string key) { 
        return getTargetCount(key) > 0;
    } 

    // Returns if there is any word in the trie 
    // that starts with the given prefix.  
    bool startsWith(string prefix) { 
        return this->getTargetCount(prefix) != -1;
    } 

    void deleteNodes(TrieNode* node) {
        if (node == NULL) {
            return;
        }

        for (size_t i = 0; i < 26; ++i) {
            this->deleteNodes(node->next[i]);
        }

        delete node;
    }

private: 
    int getTargetCount(string key) {
        TrieNode* cur = this->root;
        for (size_t i = 0; i < key.size(); ++i) {
            if (cur->next[key[i]-'a'] == NULL) {
                return -1;
            }
            cur = cur->next[key[i]-'a'];
        }
        return cur->count;
    }
    TrieNode* root; 
}; 

// Your Trie object will be instantiated and called as such: 
// Trie trie; 
// trie.insert("somestring"); 
// trie.search("key");
