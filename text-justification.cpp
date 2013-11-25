class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = 0;
        vector<string> v;
        while(i < words.size()) {
            string tmp = "";
            int space = L, cnt = 0, residual = 0, gap = 0;
            while(i < words.size() && (int)words[i].size() <= space) {//the "(int)" cannot be ignored! else err
                space -= (words[i].size() + 1);
                ++cnt;
                ++i;
            }
            space += cnt;
            if(cnt == 1 || i == words.size()) {
                for(int j = i - cnt; j < i; ++j) {
                    tmp.append(words[j]);
                    if(space > 0) {
                        tmp.append(1, ' ');
                        --space;
                    }
                }
                v.push_back(tmp.append(space, ' '));
                continue;
            }
            gap = space / (cnt - 1);
            residual = space % (cnt - 1);
            for(int j = i - cnt; j < i; ++j) {
                tmp.append(words[j]);
                int ap = (--cnt>0)?gap:0;
                ap += (residual-->0)?1:0;
                tmp.append(ap, ' ');
            }
            v.push_back(tmp);
        }
        return v;
    }
};