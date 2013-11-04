class Solution {
public:
    string intToRoman(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string roman = "IVXLCDM", res = "";
        int div = 1000;
        for(int i = 6; i >= 0; i -= 2) {
            int tmp = num / div;
            if(tmp == 0) {
                div /= 10;
                continue;
            }
            if(tmp <= 3) {
                res.append(tmp, roman[i]);
            } else if(tmp == 4) {
                res.append(1, roman[i]);
                res.append(1, roman[i+1]);
            } else if(tmp == 5) {
                res.append(1, roman[i+1]);
            } else if(tmp <= 8) {
                res.append(1, roman[i+1]);
                res.append(tmp-5, roman[i]);
            } else {
                res.append(1, roman[i]);
                res.append(1, roman[i+2]);
            }
            num %= div;
            div /= 10;
        }
        return res;
    }
};