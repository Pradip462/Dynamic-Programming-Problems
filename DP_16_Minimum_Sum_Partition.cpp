
#include<bits/stdc++.h>
using namespace std;

int minDifference(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if (nums[0] <= sum) dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            bool not_take = dp[i - 1][j];
            bool take = false;
            if (j >= nums[i]) {
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = take || not_take;
        }
    }

    int minimum = INT_MAX;
    for (int s1 = 0; s1 <= sum/2; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = sum - s1;
            minimum = min(minimum, abs(s2 - s1));
        }
    }

    return minimum;
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; // Input the elements of the array
    }
    cout << minDifference(nums); // Call the function and print the result
    return 0;
}