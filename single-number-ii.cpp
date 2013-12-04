class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        vector<int> count(32, 0);
        vector<int> bits(32, 1);
        for(int i = 1; i < 32; ++i)
            bits[i] = (bits[i-1]<<1);
        for(int i = 0; i < 32; ++i) {
            for(int j = 0; j < n; ++j) {
                if(bits[i] & A[j])
                    ++count[i];
            }
            if(count[i] % 3)
                res |= bits[i];
        }
        return res;
    }
};