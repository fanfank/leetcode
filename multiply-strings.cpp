/*****************************************
 Solution 1: from me ... ugly code
 *****************************************/
class Solution {//10000 base, ugly code
public:
    void strToVect(string num, vector<int> &v) {
        for(int i = num.size() - 1; i >= 0; i -= 4) {
            int tmp = 0, base = 1;
            for(int j = i; j >= 0 && j > i - 4; --j, base *= 10)
                tmp += (num[j] - '0') * base;
            v.push_back(tmp);
        }
    }
    void addVect(vector<int> &res, vector<int> &addend) {
        while(res.size() < addend.size())
            res.push_back(0);
        int carry = 0;
        for(int i = 0; i < addend.size(); ++i) {
            res[i] += addend[i] + carry;
            carry = res[i] / 10000;
            res[i] %= 10000;
        }
        if(carry)
            res.push_back(carry);
    }
    void multiplyVect(vector<int> &n1, vector<int> &n2, vector<int> &res) {
        for(int i = 0; i < n1.size(); ++i) {
            vector<int> v(i, 0);
            int carry = 0;
            for(int j = 0; j < n2.size(); ++j) {
                int tmp = n2[j] * n1[i] + carry;
                carry = tmp / 10000;
                v.push_back(tmp % 10000);
            }
            if(carry)
                v.push_back(carry);
            addVect(res, v);
        }
    }
    string multiply(string num1, string num2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> n1, n2, n3;
        strToVect(num1, n1);
        strToVect(num2, n2);
        multiplyVect(n1, n2, n3);
        string res;
        for(int i = 0; i < n3.size() - 1; ++i) {
            for(int j = 0; j < 4; ++j) {
                int digit = n3[i]?n3[i]%10:0;
                res.append(1, digit + '0');
                n3[i] /= 10;
            }
        }
        while(n3[n3.size()-1]) {
            res.append(1, '0' + n3[n3.size()-1]%10);
            n3[n3.size()-1] /= 10;
        }
        reverse(res.begin(), res.end());
        while(res[0] == '0')
            res.pop_back();
        return res.size()?res:"0";
    }
};

/*****************************************
 Solution 2: from http://blog.csdn.net/doc_sgl/article/details/13279999
 *****************************************/
string multiply(string num1, string num2) {
    if(num1=="0" || num2=="0") return "0";
    int l1 = num1.length(), l2 = num2.length();
    int* n1 = new int[l1];
    int* n2 = new int[l2];
    int* res = new int[l1+l2];
    memset(res,0,sizeof(int)*(l1+l2));
    for(int i=0; i<l1; ++i)
        n1[i] = num1[i] - '0';
    for(int i=0; i<l2; ++i)
        n2[i] = num2[i] - '0';
    
    for(int i=0; i<l1; ++i)
        for (int j=0; j<l2; ++j)
            res[i+j+1] += n1[i]*n2[j];
    
    string ss = "";
    for (int k=l1+l2-1; k>=0; --k){
        if(k>0) res[k-1] += res[k]/10;
        res[k] %= 10;
        ss = char(res[k]+'0')+ss;
    }
    ss = ss[0]=='0'? ss.substr(1):ss;
    //return ss.empty()?"0":ss;
    return ss;
}