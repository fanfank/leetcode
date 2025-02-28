#include <vector>
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        // dp means how many points the first-in-action player will get more than the second player
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = nums[i];
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j + i < nums.size(); j++) {
                dp[j][j+i] = max(nums[j]-dp[j+1][j+i], nums[j+i]-dp[j][j+i-1]);
            }
        }

        return dp[0][nums.size()-1] >= 0; 
    }
};

int main() {
    Solution s;
    //vector<int> nums = {1,5,2};
    vector<int> nums = {1,5,233,7};
    cout << s.predictTheWinner(nums) << endl;
}