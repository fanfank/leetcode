#include<algorithm>
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *a = new int[triangle.back().size()];
        int asize = 0;
        a[asize++] = triangle[0][0];
        int mini = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++)
        {
            int pos = asize++;
            a[pos] = triangle[i][pos] + a[pos-1];
            mini = a[pos];
            pos--;
            for(;pos>0;pos--)
            {
                a[pos] = triangle[i][pos] + min(a[pos], a[pos-1]);
                mini = min(a[pos], mini);
            }
            a[0] = triangle[i][0] + a[0];
            mini = min(a[0], mini);
        }
        delete []a;
        return mini;
    }
};
