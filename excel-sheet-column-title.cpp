//solution 1: my solution ...
class Solution {
public:
    string convertToTitle(int n) {
        int base = 1;
        while (n / base > 26) {
            base *= 26;
        }
        
        char underflow_char = 'A' - 1;
        string res = "";
        while (base > 0) {
            int coefficient = n / base;
            n -= base * coefficient;
            base /= 26;
            res.append(1, 'A' + coefficient - 1);
        }

        if (res.empty()) {
            return res;
        }

        int last_underflow_index = res.size() - 1;
        int head_index           = res.size() - 1;
        for (; head_index >= 0; --head_index) {
            if (res[head_index] != underflow_char) {
                while (last_underflow_index > head_index 
                        && res[last_underflow_index] != underflow_char) {
                    --last_underflow_index;
                }

                char replace_char = 'Z';
                while (last_underflow_index != head_index) {
                    res[last_underflow_index--] = replace_char--;
                }

                if (replace_char != 'Z') {
                    res[head_index] -= 1;
                }
            } 
        }

        int start_index = last_underflow_index;
        if (res[last_underflow_index] == underflow_char) {
            ++start_index;
        }

        return res.substr(start_index);
    }
};

//solution 2(好牛B的样子): 
//refer to :
//      https://oj.leetcode.com/discuss/19120/short-and-recursive-solution-with-note-about-algorithm-trick
string convertToTitle(int n) {
    string r;
    for (; n > 0; n /= 26)  {
        r = (char)(--n % 26 + 'A') + r;
    }
    return r;
}
