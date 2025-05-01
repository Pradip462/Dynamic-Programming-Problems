#include<bits/stdc++.h>
using namespace std;

//Recursion Solution
bool solve(vector<int>& arr, int ind, int sum){
    //base case
    if(sum == 0) return true;
    if(ind == 0){
        return (arr[0] == sum);
    }
    
    bool not_take = solve(arr,ind-1,sum);
    bool take = false;
    if(sum >= arr[ind]){
        take = solve(arr,ind-1,sum-arr[ind]);
    }
    return take or not_take;
}
bool rec_isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    return solve(arr,n-1,sum);
}


//Memoization Solution
bool solve(vector<int>& arr, int ind, int sum,vector<vector<int>> &dp){
    //base case
    if(sum == 0) return true;
    if(ind == 0){
        return (arr[0] == sum);
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    bool not_take = solve(arr,ind-1,sum,dp);
    bool take = false;
    if(sum >= arr[ind]){
        take = solve(arr,ind-1,sum-arr[ind],dp);
    }
    return dp[ind][sum] = take or not_take;
}
bool mem_isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return solve(arr,n-1,sum,dp);
}

//Tabulation Solution
bool tab_isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    for(int i = 0;i < n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= sum;j++){
            bool not_take = dp[i-1][j];
            bool take = false;
            if(j >= arr[i]){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take or not_take;
        }
    }
    return dp[n-1][sum];
}

//Space Optimization
bool space_isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum+1,false);
    vector<bool> cur(sum+1,false);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= sum;j++){
            bool not_take = prev[j];
            bool take = false;
            if(j >= arr[i]){
                take = prev[j-arr[i]];
            }
            cur[j] = take or not_take;
        }
        prev = cur;
    }
    return prev[sum];
}

//main function
int main(){
    int m;
    cin >> m ;
    int sum;
    cout<<"Enter the target value";
    cin >> sum;
    vector<int> arr(m);
    for(int i = 0;i < m;i++){
        cin >> arr[i];
    }
    cout << rec_isSubsetSum(arr,sum);
    // cout << mem_isSubsetSum(arr,sum);
    // cout << tab_isSubsetSum(arr,sum);
    // cout << space_isSubsetSum(arr,sum);
    return 0;
}