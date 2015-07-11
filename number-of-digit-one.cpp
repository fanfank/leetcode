class Solution { 
public: 
    int countDigitOne(int n) {
        int one_num = 0;
        int base = 1;
        int lower_digits = 0;
        while (n > 0) {
            one_num += (n / 10) * base;
            if (n % 10 > 1) {
                one_num += base;
            } else if (n % 10 == 1) {
                one_num += (lower_digits + 1);
            }
            lower_digits += base * (n % 10);
            n /= 10;
            base *= 10;
        }
        return one_num;
    } 
};
