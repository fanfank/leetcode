#include<vector>
class Solution {
public:
    void reverseWords(string &s) {
		vector<string> v;
		int i = 0;
		for (;i < s.length() && s[i] == ' ' ; ++i);
		for (;i < s.length() ; ++i) {
			if (s[i] == ' ') {
				while (i < s.length() && s[i] == ' ') {++i;}
				if (i < s.length()) {
					v.push_back(string(" "));
				}
				--i;
			} else {
				int st = i;
				while (i < s.length() && s[i] != ' ') {
					++i;
				}
				int n = i - st;
				v.push_back(s.substr(st, n));
				--i;
			}
		}

		s = "";
		for (i = v.size() - 1; i >= 0; --i) {
			s.append(v[i]);
		}
    }
};
