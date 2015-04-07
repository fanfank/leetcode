//Space : O(4n), Time : O(max_digits_num * 2n)
class Solution {
public:
    vector<pair<int, int> > bucket[10];
    vector<pair<int, int> > buffer;
    int maximumGap(vector<int> &num) {
        //use radix sort
        clearBuckets();

        buffer.clear();
        for (std::size_t i = 0; i < num.size(); ++i) {
            buffer.push_back(pair<int, int>(num[i], num[i]));
        }

        while (true) {
            bool finished = true;

            //fill buckets
            for (std::size_t i = 0; i < buffer.size(); ++i) {
                int index = buffer[i].first % 10;
                int quotient = buffer[i].first / 10;
                bucket[index].push_back(
                        pair<int, int>(quotient, buffer[i].second));
                finished = quotient == 0 ? finished : false;
            }

            //refresh buffer
            buffer.clear();
            for (std::size_t i = 0; i < 10; ++i) {
                buffer.insert(buffer.end(), bucket[i].begin(), bucket[i].end());
            }

            clearBuckets();
            if (finished) {
                break;
            }
        }

        int max_gap = 0;
        for (std::size_t i = 1; i < buffer.size(); ++i) {
            max_gap = max(max_gap, buffer[i].second - buffer[i-1].second);
        }
        
        return max_gap;
    }

    void clearBuckets() {
        for (std::size_t i = 0; i < 10; ++i) {
            bucket[i].clear();
        }
    }
};
