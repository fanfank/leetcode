class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m<n) swap(m,n);
        long long mm = m - 1, nn = n - 1;
        long long ans = 1;
        long long i = mm + nn;
        for(long long j = 1; j <= nn; j++,i--)
        {
            ans = (ans * i)/j;
        }
        return ans;
    }
};
