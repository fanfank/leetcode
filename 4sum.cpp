class Solution {
public:
    vector<vector<int> > vv;
    int binarySearch(vector<int> &a, int left, int right, int target) {
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(a[middle] == target)
                return middle;
            else if(a[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return -1;
    }
    void kSum(vector<int> &a, int target, int k, int index, vector<int> &helper) {
        int sz = a.size();
        if(k > sz - index)
            return;
        if(k == 1) {
            int pos = binarySearch(a, index, sz - 1, target);
            if(pos != -1) {
                helper.push_back(a[pos]);
                vv.push_back(helper);
                helper.pop_back();
            }
            return;
        }
        for(int i = index; i <= sz - k; ++i) {
            if(i != index && a[i] == a[i-1])
                continue;
            helper.push_back(a[i]);
            kSum(a, target - a[i], k - 1, i + 1, helper);
            helper.pop_back();
        }
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vv.clear();
        sort(num.begin(), num.end());
        vector<int> tmp;
        kSum(num, target, 4, 0, tmp);
        return vv;
    }
};