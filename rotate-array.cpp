//Solution 1: 就地移位
//            In place rotating
//            time: O(n)
//            space: O(1)
//            29ms
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n == 0 || k % n == 0) {
            return;
        }

        k = k % n;
        int cnt = 0;

        int st = 0;
        while (cnt < n) {
            int tmp = nums[st];
            int next = (st + k) % n;
            while(next != st) {
                swap(tmp, nums[next]);
                next = (next + k) % n;
                ++cnt;
            }
            nums[next] = tmp;
            ++cnt;
            ++st;
        }
    }
};

//Solution 2: 德摩根法
//            de Morgan
//            time: O(n)
//            space: O(1)
//            29ms
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n == 0 || k % n == 0) {
            return;
        }

        k = k % n;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(int nums[], int st, int ed) {
        for (int i = st; i <= (st + ed) / 2; ++i) {
            swap(nums[i], nums[ed-i+st]);
        }
    }
};
