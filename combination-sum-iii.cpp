class Solution { 
public: 
    vector<vector<int>> combinationSum3(int k, int n) { 
        vector<vector<int> > res;
        if (n / k < 1 || n / k > 9) {
            return res;
        }
        if (k == 1) {
            res.push_back(vector<int>(1, n));
            return res;
        }

        vector<int> seq;
        for (int i = 1; i < (n - i) / (k - 1); ++i) {
            seq.clear();
            seq.push_back(i);
            combine(i, k - 1, n - i, seq, res);
        }
        
        return res;
    }

    void combine(int last_num, int count_down, int target, vector<int>& seq, 
            vector<vector<int> >& res) {

        if (count_down == 1) { 
            if (target > last_num && target <= 9) {
                seq.push_back(target);
                res.push_back(seq);
                seq.pop_back();
            }
            return;
        }

        --count_down;
        for (int i = last_num + 1; i < (target - i) / count_down; ++i) {
            seq.push_back(i);
            combine(i, count_down, target - i, seq, res);
            seq.pop_back();
        }
    }
};
