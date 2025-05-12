#include <bits/stdc++.h>
using namespace std;

//Recursion Solution
int solve(vector<int>& nums, int ind, int target){
    //base case
    if(ind == 0){
        if(target == nums[ind] && target == -nums[ind]) return 2;
        if(target == nums[ind] || target == -nums[ind]) return 1;
        else return 0;
    }
    //explore all possible paths
    int plus = solve(nums, ind - 1, target - nums[ind]);
    int minus = solve(nums, ind - 1, target + nums[ind]);
    return plus + minus;
}
int rec_findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return solve(nums, n - 1, target);
}

//Memoization Solution

//Tabulation Solution

//Space Optimization Solution

//Another way that concept of S1 - S2 = D
//Recursion Solution
int mod = 1e9+7;
long long solve(int ind, vector<int>& A, int target){
    //base case
    if (ind == 0) {
        if (target == 0 && A[0] == 0) return 2;
        if (target == 0 || target == A[0]) return 1;
        return 0;
    }
    
    //explore all paths
    int not_pick = solve(ind - 1, A, target);
    int pick = 0;
    if(target >= A[ind]){
        pick = solve(ind - 1, A, target - A[ind]);
    }
    
    return (not_pick + pick) % mod;
}
long long findTargetSumWays(int n, vector<int>& A, int target) {
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    if((sum - target) < 0 || (sum - target) % 2 != 0) return 0;
    int op = (sum - target) / 2;
    long long ans = solve(n - 1, A, op);
    return ans;
}

//Memoization Solution

//Tabulation Solution
long long tab_findTargetSumWays(int n, vector<int>& A, int target) {
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    if((sum - target) < 0 || (sum - target) % 2 != 0) return 0;
    int op = (sum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(op + 1, 0));
    
    // Base case initialization
    if (A[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1; 
    
    if (A[0] != 0 && A[0] <= op) dp[0][A[0]] = 1;
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= op; j++){
            int not_pick = dp[i - 1][j];
            int pick = 0;
            if(j >= A[i]){
                pick = dp[i - 1][j - A[i]];
            }
            dp[i][j] = (not_pick + pick) % mod;
        }
    }
    return dp[n - 1][op];
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> target;

    // Test all versions
    cout << "Recursion: " << rec_findTargetSumWays(arr, target) << endl;
    cout << "S1-S2 Concept (Rec): " << findTargetSumWays(n, arr, target) << endl;
    cout << "Tabulation: " << tab_findTargetSumWays(n, arr, target) << endl;

    return 0;
}
