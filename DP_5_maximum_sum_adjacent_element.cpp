#include<bits/stdc++.h>
using namespace std;

//recursive Solution
int solve(int ind,vector<int> &nums){
    //base case
    if(ind == 0) return nums[ind];
    if(ind < 0) return 0;
    int pick = nums[ind] + solve(ind - 2,nums);
    int not_pick = solve(ind - 1,nums);
    return max(pick,not_pick);
}
int rec_maxSum(vector<int>& nums) {
    int n = nums.size();
    return solve(n-1,nums);
}

//Memoization Solution
int mem_solve(int ind,vector<int> &arr,vector<int> &dp){
    if(ind == 0) return arr[ind];
    if(dp[ind] != -1) return dp[ind];
    if(ind < 0) return 0;
    int pick = arr[ind] + mem_solve(ind-2,arr,dp);
    int not_pick = mem_solve(ind-1,arr,dp);
    return dp[ind] = max(pick,not_pick);
}
int mem_maxSum(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    return mem_solve(n-1,arr,dp);
}

//Tabulation Solution
int tab_maxSum(vector<int> &arr){
    int n =  arr.size();
    vector<int> dp(n,-1);
    dp[0] = arr[0];
    for(int i = 1;i < n;i ++){
        int left = arr[i] + dp[i-2];
        int right = dp[i-1];
        dp[i] = max(left,right);
    }
    return dp[n-1];
}
//Space Optimization
int space_maxSum(vector<int> &arr){
    int n = arr.size();
    int prev2 = arr[0];
    int prev1 = max(arr[0],arr[1]);
    for(int i = 2;i < n;i++){
        int left = arr[i] + prev2;
        int right = prev1;
        int curr = max(left,right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;

}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    // rec_maxSum(arr);
    mem_maxSum(arr);
    // tab_maxSum(arr);
    // space_maxSum(arr);
}