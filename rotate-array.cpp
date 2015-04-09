//Solution 1: 就地移位，应该算是简单的做法
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
