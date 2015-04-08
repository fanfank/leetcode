//Solution 0: my fastest solution
//            12ms
class Solution {
public:
    unsigned int c2i[128];

    Solution() {
        c2i['A'] = 0;
        c2i['C'] = 1;
        c2i['G'] = 2;
        c2i['T'] = 3;
    }   

    char bits[1<<18]; //we need at least 2 * 1<<20 bits, thus 1<<18 bytes
    unsigned int num;
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        memset(bits, 0, sizeof(bits));

        num = 0;
        for (int i = 0; i < s.size() && i < 9; ++i) {
            num = (num << 2) | c2i[s[i]];
        }

        for (int i = 9; i < s.size(); ++i) {
            num = ((num << 2) & 0x000fffff) | c2i[s[i]];
            if (setBit(num) == 1) {
                res.push_back(s.substr(i - 9, 10));
            }
        }
        
        return res;
    }

    unsigned int setBit(unsigned int num) {
        num *= 2; //each num require 2 status bits

        int index1  = num / 8;
        int offset1 = num % 8;
        int offset2 = (offset1 + 1) % 8;
        int index2  = offset2 == 0 ? index1 + 1 : index1;
        if (bits[index1] & (1 << offset1)) {
            if (bits[index2] & (1 << offset2)) {
                return 2;
            } else {
                bits[index2] |= (1 << offset2);
                return 1;
            }
        } else {
            bits[index1] |= (1 << offset1);
            return 0;
        }
    }
};

//Solution 1: use bitmap, but less space compared to solution 2
//            138ms
class Solution {
public:
    unsigned int c2i[128];
    char         i2c[4];

    Solution() {
        c2i['A'] = 0; i2c[0] = 'A';
        c2i['C'] = 1; i2c[1] = 'C';
        c2i['G'] = 2; i2c[2] = 'G';
        c2i['T'] = 3; i2c[3] = 'T';
    }   

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<unsigned int, int> num_count;

        int slen = s.size();
        for (int i = 0; i <= slen - 10; ++i) {
            unsigned int num = convert2Uint(s.substr(i, 10));
            if (num_count[num]++ == 1) {
                res.push_back(s.substr(i, 10));
            }
        }

        return res;
    }

    unsigned int convert2Uint(string s) {
        unsigned int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            num |= c2i[s[i]] << (2 * (s.size() - 1 -i));
        }
        return num;
    }   
};

//Solution 2: use bitmap, bitset
//            870ms, very slow
class Solution {
public:
    unsigned int c2i[128]; 
    char         i2c[4];

    Solution() {
        c2i['A'] = 0; i2c[0] = 'A';
        c2i['C'] = 1; i2c[1] = 'C';
        c2i['G'] = 2; i2c[2] = 'G';
        c2i['T'] = 3; i2c[3] = 'T';
    }

    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        bitset<2*(1<<20)> num_count;

        int slen = s.size();
        for (int i = 0; i <= slen - 10; ++i) {
            unsigned int num = convert2Uint(s.substr(i, 10));
            if (num_count.test(num * 2)) {
                num_count.set(num * 2 + 1, 1);
            } else {
                num_count.set(num * 2, 1);
            }
        }

        for (unsigned int i = 0; i < (1 << 20); ++i) {
            if (num_count.test(i * 2 + 1)) {
                res.push_back(convert2String(i));
            }
        }

        return res;
    }

    unsigned int convert2Uint(string s) {
        unsigned int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            num |= c2i[s[i]] << (2 * (s.size() - 1 -i));
        }
        return num;
    }

    string convert2String(unsigned int num) {
        string s = "0123456789";
        int index = 10;
        while (--index >= 0) {
            s[index] = i2c[num & 3];
            num >>= 2;
        }
        return s;
    }
};

//Solution 3: the shortest, refer to:
//      https://leetcode.com/discuss/24478/i-did-it-in-10-lines-of-c
//      93ms
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<unsigned int, int> num_count;
        unsigned int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            num = (num << 3) & 0x3fffffff | s[i] & 0x00000007;
            if (num_count[num]++ == 1) {
                res.push_back(s.substr(i - 9, 10));
            }
        }
        return res;
    }
};

//use KMP, TIME LIMIT EXCCEEDED
/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        set<string> str_set;
        int slen = s.size();
        for (int i = 0; i <= slen - 10; ++i) {
            string needle(s.substr(i, 10));
            if (str_set.find(needle) != str_set.end()) {
                continue;
            }

            if (kmp_find(needle, s.substr(i+1)) != string::npos) {
                res.push_back(needle);
                str_set.insert(needle);
            }
        }
        return res;
    }

    std::size_t kmp_find(string needle, string str) {
        int slen = str.size();
        int nlen = needle.size();

        vector<int> next(nlen);
        next[0] = -1;

        for (std::size_t i = 1; i < nlen;  ++i) {
            int j = i - 1;
            while (j != -1) {
                int pos = next[j];
                if (pos == -1 || needle[i-1] == needle[pos]) {
                    next[i] = pos + 1;
                    break;
                }
                j = next[j];
            }
        }

        int i = 0, j = 0;
        while (i < slen && j < nlen) {
            if (j == -1 || str[i] == needle[j]) {
                ++i; ++j;
                continue;
            } 
            j = next[j];
        }

        if (i < slen) {
            return i - nlen;
        }

        return string::npos;
    }
};
*/
