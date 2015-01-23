class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.empty()) {
            return -1;
        }

        int peak_index = 0;
        for (unsigned int i = 1; i < num.size(); ++i) {
            if (num[i] > num[peak_index]) {
                peak_index = i;
            } else {
                return peak_index;
            }
        }
        return peak_index;
    }
};
