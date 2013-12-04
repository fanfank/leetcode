class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        string res(n, '0');
        for(int i = n - 2; i >= 0; --i) {
            res[i] += (k % (n - i));
            k /= (n-i);
        }
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i - 1; j >= 0; --j) {
                if(res[j] <= res[i])
                    ++res[i];
            }
            ++res[i];
        }
        return res;
    }
};