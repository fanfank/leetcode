//time: O(n), space: O(n), find smallest coninuous sub-array
class Solution {
public:
    struct Range {
        int l,r;
        long long sum;
    };
    int sz;
    void findSCSA(long long arr[], Range &res)
    {
        res.sum = (long long)0x7fffffffffffffff;
        int i = 0, l = 0, sum = 0;
        while(l < sz && (i - l) < sz)
        {
            sum += arr[i%sz];
            if(sum < res.sum)
            {
                res.l = l;
                res.r = i;
                res.sum = sum;
            }
            if(sum > 0)
            {
                l = i + 1;
                sum = 0;
            }
            ++i;
        }
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sz = gas.size();
        long long *ab = new long long[sz];
        for(int i = 0; i < sz; i++)
            ab[i] = gas[i] - cost[i];
            
        Range res;
        findSCSA(ab, res);
        if(res.sum >= 0)
        {
            delete []ab;
            return 0;
        }
        
        long long sum = 0;
        for(int i = res.r + 1; (i % sz) != res.l; ++i)
        {
            sum += ab[i%sz];
            if(sum < 0)
            {
                delete []ab;
                return -1;
            }
        }
        delete []ab;
        if(sum < -res.sum)
            return -1;
        return (res.r + 1)%sz;
    }
};
