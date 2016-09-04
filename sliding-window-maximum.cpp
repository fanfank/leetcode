// Solution 1: use deque. 109ms
class Solution {
    struct E {
        int val, index;
        E(int val, int index) {
            this->val = val;
            this->index = index;
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0) {
            return vector<int>();
        }

        deque<E> d;
        vector<int> ans;

        // Start to slide
        for (int i = 0; i < nums.size(); ++i) {
            int left_bound = i - k + 1;
            while (!d.empty() && d.front().index < left_bound) {
                d.pop_front();
            }
            while (!d.empty() && (d.back().index < left_bound || d.back().val <= nums[i])) {
                d.pop_back();
            }
            d.push_back(E(nums[i], i));
            if (i >= k - 1) {
                ans.push_back(d.front().val);
            }
        }

        return ans;
    }
};

// Solution 2: use ringed buffer. 83ms
class Solution {
    struct E {
        int val, index;
        E() { this->val = this->index = -1; }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0) {
            return vector<int>();
        }

        vector<int> ans;

        int rb_sz = 2 * (k + 1);
        int head = 0; // Position of first element
        int tail = 0; // Position of the last element - 1
        E* rb = new E[rb_sz];

        // Start to slide
        for (int i = 0; i < nums.size(); ++i) {
            int left_bound = i - k + 1;
            while ((head != tail) && rb[head].index < left_bound) {
                head = (head -1 + rb_sz) % rb_sz;
            }

            while ((head != tail) && (rb[(tail+1)%rb_sz].index < left_bound || rb[(tail+1)%rb_sz].val <= nums[i])) {
                tail = (tail + 1) % rb_sz;
            }

            rb[tail].val = nums[i];
            rb[tail].index = i;
            tail = (tail - 1 + rb_sz) % rb_sz;

            if (i >= k - 1) {
                ans.push_back(rb[head].val);
            }
        }

        delete []rb;
        return ans;
    }
};
