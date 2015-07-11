//Solution 1: O(k) space, O(nlogk) time
//          this solution is long because I implement a simple priority queue
//          rather than using STL
class Solution { 
public: 
    int findKthLargest(vector<int>& nums, int k) { 
        SimplePriorityQueue q(k);
        for (size_t i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
        }
        return q.top();
    } 

private:
    class SimplePriorityQueue {
    public:
        ~SimplePriorityQueue() {
            delete []q;
        }

        SimplePriorityQueue(size_t _queue_size_limit) : 
                size(0), 
                size_limit(_queue_size_limit), 
                reserved(_queue_size_limit + 2) {
            q = new int[reserved];
        }

        void push(int x) {
            if (size < size_limit) {
                q[++size] = x;
                adjust_down_top(size);
            } else if (x > top()) {
                q[1] = x;
                adjust_top_down(1);
            }
        }

        int top() {
            return q[1];
        }

        bool empty() {
            return size == 0;
        }

    private:
        void adjust_top_down(size_t index) {
            while (true) {
                int min_child_index = get_min_child(index);
                if (min_child_index == -1 || q[index] <= q[min_child_index]) {
                    break;
                }
                swap(q[index], q[min_child_index]);
                index = min_child_index;
            }
        }

        void adjust_down_top(size_t index) {
            while (index > 1 && q[index] < q[index >> 1]) {
                swap(q[index], q[index >> 1]);
                index >>= 1;
            }
        }

        int get_min_child(int index) {
            if (index << 1 > size_limit) {
                return -1;
            } else  if ((index << 1) + 1 > size_limit) {
                return index << 1;
            } else {
                return q[index << 1] < q[(index << 1) + 1] ? 
                        (index << 1) : (index << 1) + 1;
            }
        }

        size_t size;
        size_t size_limit;
        size_t reserved;
        int* q;
    }; //class PriorityQueue
};

//Solution 2: a very interesting solution from:
//          https://leetcode.com/discuss/41983/solution-straightforward-largest-like-partition-version
//          O(n) space, time < O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cur=nums[k-1];
        vector<int> bigger;
        vector<int> smaller;
        for(size_t i=0; i<nums.size(); ++i){
            if(i==k-1) continue;
            if(nums[i]>=cur) bigger.push_back(nums[i]);
            else smaller.push_back(nums[i]);
        }
        if(bigger.size()==k-1) return cur;
        if(bigger.size()>k-1) return findKthLargest(bigger,k);
        if(bigger.size()<k-1) return findKthLargest(smaller,k-bigger.size()-1);
    }
};
