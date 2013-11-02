class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0)
            return false;
        if(x == 0)
            return true;
            
        int highb = 10;
        while((highb < 1000000000) && x/highb > 0)
            highb*=10;
        if(x/highb == 0)
            highb/=10;
        int lowb = 10;
        while(x>9)
        {
            if((x/highb) != (x%lowb))
                return false;
            x%=highb; x/=lowb;
            highb/=100;
        }
        return true;
    }
};
