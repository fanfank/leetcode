class Solution { 
public: 
    static const uint64_t seed = 31;
    vector<uint64_t> vpow;
    uint64_t pow(int n) {
        while (n >= this->vpow.size()) {
            if (this->vpow.size() == 0) {
                this->vpow.push_back(1);
            } else {
                this->vpow.push_back(this->vpow.back() * Solution::seed);
            }
        }
        return this->vpow[n];
    }

    string shortestPalindrome(string s) {
        uint64_t SEED = Solution::seed;
        vector<uint64_t> left_hash;
        vector<uint64_t> right_hash;

        int ssize = s.size();
        if (ssize == 0) {
            return string("");
        }

        left_hash.resize(ssize + 1);
        left_hash[0] = 0;
        for (int i = 0; i < ssize; ++i) {
            left_hash[i+1] = left_hash[i] * SEED + s[i];
        }

        right_hash.resize(ssize + 1);
        right_hash[0] = 0;
        for (int i = 0; i < ssize; ++i) {
            right_hash[i+1] = right_hash[i] * SEED + s[ssize-1-i];
        }

        for (int i = (ssize - 1) / 2; i >= 0; --i) {
            // Even
            int left_left_bound = 0;
            int left_right_bound = i + 1;
            int right_left_bound = ssize - i - 1;
            int right_right_bound = ssize - i - 1 - (i + 1);
            if (right_right_bound >= 0) {
                if ((left_hash[left_right_bound] - left_hash[left_left_bound] * this->pow(i+1)) == 
                        (right_hash[right_left_bound] - right_hash[right_right_bound] * this->pow(i+1))) {

                    string s2(s.substr(2*(i+1)));
                    reverse(s2.begin(), s2.end());
                    return s2 + s;
                }
            }
            
            // Odd
            left_left_bound = 0;
            left_right_bound = i - 1 + 1;
            right_left_bound = ssize - i - 1;
            right_right_bound = ssize - i - 1 - i;
            if (left_hash[left_right_bound] - left_hash[left_left_bound] * this->pow(i) == 
                    right_hash[right_left_bound] - right_hash[right_right_bound] * this->pow(i)) {

                string s2(s.substr(2*i+1));
                reverse(s2.begin(), s2.end());
                return s2 + s;
            }

        }
        
        string s2 = s.substr(1);
        reverse(s2.begin(), s2.end());
        return s2 + s;
    } 
};
