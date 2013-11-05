class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> v;
        if(L.size() == 0 || L[0].size() == 0) {
            for(int i = 0; i < S.size(); ++i) {
                v.push_back(i);
            }
            return v;
        }
        unordered_map<string, int> str_set;  //after test, use map is better
        unordered_map<string, int> res_set;  //after test, use map is better
        //map<string, int> res_set;
        int ssz = S.size(), lsz = L.size(), len = L[0].size();
        for(int i = 0; i < lsz; ++i)
            ++str_set[L[i]];
        for(int i = 0; i + lsz * len <= ssz; ++i) {
            res_set.clear();
            bool f = true;
            for(int j = 0; j < lsz; ++j) {
                string stmp = S.substr(i + j * len, len);
                if(str_set[stmp] > res_set[stmp]) {
                    res_set[stmp]++;
                } else {
                    f = false;
                    break;
                }
            }
            if(f)
                v.push_back(i);
        }
        return v;
    }
};

/************************************
 * Solution 2: ugly codes
 ************************************/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> v;
        if(L.size() == 0 || L[0].size() == 0) {
            for(int i = 0; i < S.size(); ++i) {
                v.push_back(i);
            }
            return v;
        }
        unordered_map<string, int> str_set;
        unordered_map<string, int> res_set;
        unordered_map<string, int>::iterator p;
        //map<string, int> res_set;
        int st, ssz = S.size(), lsz = L.size(), len = L[0].size();
        for(int i = 0; i < L.size(); ++i)
            ++str_set[L[i]];
        for(int i = 0; i + lsz * len <= ssz; ++i) {
            st = i;
            res_set = str_set;
            while(st + len <= ssz) {
                string stmp = S.substr(st, len);
                p = res_set.find(stmp);
                if(p != res_set.end()) {
                    p->second -= 1;
                    if(p->second == 0)
                        res_set.erase(p);
                    if(res_set.size() == 0) {
                        v.push_back(i);
                        break;
                    }
                } else {
                    break;
                }
                st += len;
            }
        }
        return v;
    }
};//ugly codes