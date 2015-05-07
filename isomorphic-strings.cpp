class Solution {
public:
    char char_map[265];
    char char_rmap[265];
    bool isIsomorphic(string s, string t) {
        memset(char_map, 0, sizeof(char_map));
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (char_map[s[i]] == 0 && char_rmap[t[i]] != 0
                || char_map[s[i]] != 0 && char_rmap[t[i]] == 0) {

                return false;
            } else if (char_map[s[i]] == 0 && char_rmap[t[i]] == 0) {
                char_map[s[i]]  = t[i];
                char_rmap[t[i]] = s[i];
            } else if (char_map[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};
