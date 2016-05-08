class Solution {
public:
    int integerBreak(int n, bool first_split = true) {
        // p = x[0] * x[1] * ... * x[i] * ... * x[n]
        // For any x[i]:
        //     Hint1: 1 * (x[i] - 1) >= x[i] => impossible
        //     Hint2: 2 * (x[i] - 2) >= x[i] => if x[i] >= 4
        //     Hint3: 3 * (x[i] - 3) >= x[i] => if x[i] >= 4.5
        //         =>
        //             Hint4: 4 * (x[i] - 4) <= 2 * 2 * (x[i] - 4)
        //             Hint5: 5 * (x[i] - 5) <= 2 * 3 * (x[i] - 5)
        //             Hint6: 6 * (x[i] - 6) <= 2 * 2 * 2 * (x[i] - 6) <= 3 * 3 * (x[i] - 6)
        //             ...
        // Conclusion1: we can split x[i] into 2s and 3s
        // Conclusion2: From Hint3, Hint5 and Hint6, 3s are prefered if x[i] > 4

        if (!first_split && n <= 4) {
            return n;
        } else if (n == 1 || n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        } else if (n == 4) {
            return 4;
        } else {
            return 3 * this->integerBreak(n - 3, false); // This line can be optimized
        }
    }
};
