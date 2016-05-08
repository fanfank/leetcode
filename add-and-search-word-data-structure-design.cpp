class WordDictionary { 
private:
    class TrieNode {
    public:
        TrieNode(char c = '\0') : val(c), complete_flag(false) {
            for (int i = 0; i < 26; ++i) {
                children[i] = NULL;
            }
        }
        
        TrieNode* get_child(char c) {
            int index = c - 'a';
            if (index >= 0 && index < 26) {
                return children[index];
            }
            return NULL;
        }

        TrieNode* add_child(char c) {
            int index = c - 'a';

            if (index < 0 || index >= 26) {
                return NULL;
            } else if (children[index] != NULL) {
                return children[index];
            }

            children[index] = new TrieNode(c);

            return children[index]; 
        }

        void set_complete_flag() {
            complete_flag = true;
        }

        bool is_complete() {
            return complete_flag;
        }

        char get_val() {
            return val;
        }

    private:
        char val;
        bool complete_flag;
        TrieNode* children[26];
    };

    TrieNode root;

public: 
    ~WordDictionary() {
        //TODO destroy trie
    }

    // Adds a word into the data structure.  
    void addWord(string word) { 
        TrieNode* cur = &root;
        for (int i = 0; i < word.size() && cur != NULL; ++i) {
            cur = cur->add_child(word[i]);
        }
        cur->set_complete_flag();
    } 

    // Returns if the word is in the data structure. A word could 
    // contain the dot character '.' to represent any one letter.  
    bool search(string word) { 
        if (word.size() == 0) {
            return true;
        }
        return search(word, 0, &root);
    } 

    bool search(string& word, int index, TrieNode* node) {
        if (node == NULL) {
            return false;
        }

        if (word[index] != '.') {
            TrieNode* cur = node->get_child(word[index]);

            if (index == word.size() - 1) {
                return cur != NULL && cur->is_complete();
            } else {
                return search(word, index + 1, cur);
            }

        } else {
            bool find = false;
            TrieNode* cur = NULL;
            for (char c = 'a'; c <= 'z' && !find; ++c) {
                cur = node->get_child(c);
                if (index == word.size() - 1) {
                    find |= (cur != NULL && cur->is_complete());
                } else {
                    find |= search(word, index + 1, cur);
                }
            }

            return find;
        }
    }
}; 

// Your WordDictionary object will be instantiated and called as such: 
// WordDictionary wordDictionary; 
// wordDictionary.addWord("word"); 
// wordDictionary.search("pattern");
