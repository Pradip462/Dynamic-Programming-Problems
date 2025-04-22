#include<bits/stdc++.h>
using namespace std;

//recursion solution
int rec_solve(int ind,vector<int>&arr,int k){
    //base case
    if(ind == 0) return 0;
    int left = INT_MAX;
    for(int i = 1;i <= k;i++){
        if(ind - i >= 0){
            left = min(left,rec_solve(ind-i,arr,k) + abs(arr[ind] - arr[ind-i]));
        }
    }
    return left;
}
int rec_frogjump(vector<int>&arr,int k){
    int n = arr.size();
    return rec_solve(n-1,arr,k);
}
//memoization solution
int solve(int ind,vector<int>&arr,vector<int> &dp,int k){
    //base case
    if(ind == 0) return 0;
    if(dp[ind] != -1){
        return dp[ind];
    }
    int left = INT_MAX;
    for(int i = 1;i <= k;i++){
        if(ind - i >= 0){
            left = min(left,solve(ind-i,arr,dp,k) + abs(arr[ind] - arr[ind-i]));
        }
    }
    
    return dp[ind] = left;
}
int mem_frogjump(vector<int>&arr,int k){
    int n = arr.size();
    vector<int> dp(n,-1);
    return solve(n-1,arr,dp,k);
}
//tabulation solution
int tab_frogjump(vector<int> &arr,int k){
    int n = arr.size();
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i = 1;i < n;i++){
        int min_jumps = INT_MAX;
        for(int j = 1;j <= k;j++){
            if(i - j >= 0){
                int jumps = dp[i-j] + abs(arr[i] - arr[i-j]);
                min_jumps = min(min_jumps,jumps);
            }
        }
        dp[i] = min_jumps;
    }
    return dp[n-1];
}
//space optimization solution //not needed
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
    int k;
    cin >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    // cout << rec_frogjump(arr,k);
    // cout << mem_frogjump(arr,k);
    cout << tab_frogjump(arr,k);
    // cout << space_frogjump(arr);
    return 0;
}