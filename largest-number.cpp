class Solution {
public:
    string largestNumber(vector<int> &num) {
        char buffer[33];
        vector<string> num_as_string;
        for (unsigned int i = 0, num_n = num.size(); i < num_n; ++i) {
            num_as_string.push_back(string(itoa(num[i], buffer)));
        }
        sort(num_as_string.begin(), num_as_string.end(), cmp);
        string res = "";
        for (unsigned int i = 0, num_n = num_as_string.size(); i < num_n; ++i) {
            res = res + num_as_string[i];
        }

        int last_zero_index = -1;
        for (int i = 0; i < res.size(); last_zero_index = i++) {
            if (res[i] != '0') {
                break;
            }
        }
        if (last_zero_index < int(res.size() - 1)) {
            res = res.substr(last_zero_index + 1);
        } else {
            res = "0";
        }
        return res;
    }

    static bool cmp(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }

    static char *itoa(int num, char *buffer) {
        unsigned int index = 0;
        while (index == 0 || num > 0) {
            buffer[index++] = num % 10 + '0';
            num /= 10;
        }
        buffer[index] = '\0';
        for (unsigned int i = 0; i < index / 2; ++i) {
            swap(buffer[i], buffer[index - 1 - i]);
        }
        return buffer;
    }
};
