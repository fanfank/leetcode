//time: O(1)
//space: O(1) <- O(891)
class Solution {
private:
    //0: uninitialized
    //1: happy num
    //2: not happy num
    //3: being set
    int answer[9*9*11];

public:
    Solution() {
        memset(answer, 0, sizeof(answer));
        for (int i = 1; i < 9 * 9 * 11; ++i) {
            judgeHappy(i);
        }
    }

    int judgeHappy(int num) {
        if (answer[num] == 1 || answer[num] == 2) {
            return answer[num];
        } else if (answer[num] == 3) {
            return 2;
        } else if (num == 1) {
            return answer[num] = 1;
        }

        answer[num] = 3;

        return answer[num] = judgeHappy(digitSquareSum(num));
    }

    int digitSquareSum(int num) {
        int res = 0, digit = 0;
        while (num != 0) {
            digit = num % 10;
            res += digit * digit;
            num /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        return answer[digitSquareSum(n)] == 1 ? true : false;
    }
};
