#include<vector>
#include<algorithm>
class Solution {
public:
    vector<int> v;
    vector<int> res;
    int minus_cnt = 0;
    int maxProduct(int A[], int n) {
        v.clear();
        res.clear();
        minus_cnt = 0;
        int ans = 0xf0000000;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                ans = max(ans, 0);
                compute();
                minus_cnt = 0;
                v.clear();
            }
            else if (A[i] < 0) {
                v.push_back(A[i]);
                ans = max(ans, A[i]);
                ++minus_cnt;
            }
            else {
                int tmp = 1;
                v.push_back(A[i++]);
                while (i < n && A[i] > 0) {
                    v[v.size()-1] *= A[i++];
                }
                --i;
            }
        }
        compute();
        for (int i = 0; i < res.size(); ++i) {
            ans = max(ans, res[i]);
        }
        return ans;
    }

    void compute() {
        if (v.empty()) {
            return;
        }
        if (minus_cnt % 2) {
            int index[2] = {-1, -1};
            for (int i = 0; i < v.size(); ++i) {
                if (v[i] < 0) {
                    index[0] = i;
                    break;
                }
            }
            for (int i = v.size() - 1; i >= 0; --i) {
                if (v[i] < 0) {
                    index[1] = i;
                    break;
                }
            }
            res.push_back(doProduct(0, index[0]));
            res.push_back(doProduct(index[0] + 1, v.size()));
            res.push_back(doProduct(0, index[1]));
            res.push_back(doProduct(index[1] + 1, v.size()));
        } else {
            res.push_back(doProduct(0, v.size()));
        }
    }

    int doProduct(int st, int ed) {
        if (st >= ed) {
            return 0xf0000000;
        }
        int res = 1;
        for (; st < ed; ++st) {
            res *= v[st];
        }
        return res;
    }
};
