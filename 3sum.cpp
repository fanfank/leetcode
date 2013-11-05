class Solution { //extremely ugly code, extremely ...
public:
    vector<vector<int> > vv;
    int binarySearchLow(vector<int> &a, int left, int right, int target) {
        int lp = left;
        while(left < right) {
            int middle = left + (right - left) / 2;
            if(a[middle] < target)
                left = middle + 1;
            else if(a[middle] > target)
                right = middle - 1;
            else
                right = middle;
        }
        if(left > lp && a[left] > target)
            return (left - 1);
        return left;
    }
    int binarySearch(vector<int> &a, int left, int right, int target) {
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if(a[middle] == target)
                return middle;
            else if(a[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
    vector<vector<int> > threeSum(vector<int> &num) {//an O(n^2) method
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vv.clear();
        int sz = num.size();
        if(sz < 3)
            return vv;
        sort(num.begin(), num.end());
        int lp = binarySearchLow(num, 0, sz - 1, 0);
        int rp = lp + 1, last = num[0] - 1;
        for(; lp >= 0; --lp) {
            if(rp - lp > 1 && num[lp] == num[lp+1])
                continue;
            last = num[0] - 1;
            for(int j = rp; j < sz; ++j) {
                if(last == num[j] || (lp + 1 != rp && num[j] == 0)) continue;
                last = num[j];
                int sum = num[lp] + num[j];
                if(sum <= 0) {
                    if(-sum < num[j]) continue;
                    int pos = binarySearch(num, j + 1, sz - 1, -sum);
                    if(pos != -1) {
                        vv.push_back(vector<int>({num[lp], num[j], num[pos]}));
                    }
                } else {
                    if(-sum > num[lp]) continue;
                    int pos = binarySearch(num, 0, lp - 1, -sum);
                    if(pos != -1) {
                        vv.push_back(vector<int>({num[pos], num[lp], num[j]}));
                    }
                }
            }
        }
        return vv;
    }
};


/**********************************************************
 a better way to solve this problem, to solve K SUM problem
 **********************************************************/
class Solution { //better and extensible code
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
    vector<vector<int> > threeSum(vector<int> &num) {//an O(n^2) method
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vv.clear();
        sort(num.begin(), num.end());
        vector<int> tmp;
        kSum(num, 0, 3, 0, tmp);
        return vv;
    }
};