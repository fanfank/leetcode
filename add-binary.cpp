class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int asz = a.size(), bsz = b.size();
        int ressz = max(asz,bsz) + 3;
        char *res = new char[ressz];
        res[--ressz] = '\0';
        int add = 0;
        while(asz != 0 && bsz != 0)
        {
            res[--ressz] = a[--asz] + b[--bsz] - '0' + add;
            if(res[ressz] >= '2')
            {
                add = 1;
                res[ressz] -= 2;
            }
            else
                add = 0;
        }
        while(asz != 0)
        {
            res[--ressz] = a[--asz] + add;
            if(res[ressz] == '2')
            {
                add = 1;
                res[ressz] -= 2;
            }
            else
                add = 0;
        }
        while(bsz != 0)
        {
            res[--ressz] = b[--bsz] + add;
            if(res[ressz] == '2')
            {
                add = 1;
                res[ressz] -= 2;
            }
            else
                add = 0;
        }
        if(add == 1)
            res[--ressz] = '0' + add;
        string s(&res[ressz]);
        delete []res;
        return s;
    }
};
