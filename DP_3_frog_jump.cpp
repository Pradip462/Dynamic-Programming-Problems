#include<bits/stdc++.h>
using namespace std;

//recursion solution
int solve(int ind,vector<int>&arr){
    //base case
    if(ind == 0) return 0;
    int left = solve(ind-1,arr) + abs(arr[ind] - arr[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = solve(ind-2,arr) + abs(arr[ind] - arr[ind-2]);
    } 
    return min(left,right);
}
int rec_frogjump(vector<int>&arr){
    int n = arr.size();
    return solve(n-1,arr);
}
//memoization solution
int solve(int ind,vector<int>&arr,vector<int> &dp){
    //base case
    if(ind == 0) return 0;
    if(dp[ind] != -1){
        return dp[ind];
    }
    int left = solve(ind-1,arr) + abs(arr[ind] - arr[ind-1]);
    int right = INT_MAX;
    if(ind > 1){
        right = solve(ind-2,arr) + abs(arr[ind] - arr[ind-2]);
    } 
    return dp[ind] = min(left,right);
}
int mem_frogjump(vector<int>&arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    return solve(n-1,arr,dp);
}
//tabulation solution
int tab_frogjump(vector<int> &arr){
    int n = arr.size();
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i = 1;i < n;i++){
        int left = dp[i-1] + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1) right = dp[i-2] + abs(arr[i] - arr[i-2]);
        dp[i] = min(left,right);
    }
    return dp[n-1];
}
//space optimization solution
int space_frogjump(vector<int> &arr){
    int n = arr.size();
    int prev2 = 0;
    int prev1 = 0;
    for(int i = 2;i < n;i++){
        int left = prev1 + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(right > 1) right = prev2 + abs(arr[i] - arr[i-2]);
        int curr = min(left,right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;

}
//main function
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    // cout << rec_frogjump(arr);
    // cout << mem_frogjump(arr);
    // cout << tab_frogjump(arr);
    cout << space_frogjump(arr);
    return 0;
}