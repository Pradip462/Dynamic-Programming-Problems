#include<bits/stdc++.h>
using namespace std;


//Recursion Solution
int solve(int ind,int T,vector<int> &coins){
    //base case
    if(ind == 0){
        if(T % coins[ind] == 0) return T/coins[ind];
        else return 1e9;
    }
    //explore all paths
    int not_take = solve(ind-1,T,coins);
    int take = INT_MAX;
    if(coins[ind] <= T){
        take = 1 + solve(ind,T-coins[ind],coins);
    }
    return min(take,not_take);
}
int minCoins(vector<int> &coins, int sum) {
    int n = coins.size();
    int res = solve(n-1,sum,coins);
    return res>=1e9?-1:res;
}

//Memoization Solution
int solve(int ind,int T,vector<int> &coins,vector<vector<int>> &dp){
    //base case
    if(ind == 0){
        if(T % coins[ind] == 0) return T/coins[ind];
        else return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    //explore all paths
    int not_take = solve(ind-1,T,coins,dp);
    int take = INT_MAX;
    if(coins[ind] <= T){
        take = 1 + solve(ind,T-coins[ind],coins,dp);
    }
    return dp[ind][T] = min(take,not_take);
}
int minCoins(vector<int> &coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    int res = solve(n-1,sum,coins,dp);
    return res>=1e9?-1:res;
}

//Tabulation Solution
int coinChange(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,0));

    //base case
    for(int j = 0;j <= sum ;j++){
        if(j % coins[0] == 0) dp[0][j] =  j/coins[0];
        else dp[0][j] = 1e9;
    }

    //explore all paths
    for(int i = 1;i < n;i++){
        for(int j = 0;j <= sum;j++){
            int not_take = dp[i-1][j];
            int take = INT_MAX;
            if(coins[i] <= j){
                take = 1 + dp[i][j-coins[i]];
            }
            dp[i][j] = min(take,not_take);
        }
    }

    int res = dp[n-1][sum];
    return res>=1e9?-1:res;
}

//Space Optimization Solution
int coinChange(vector<int>& coins, int sum) {
    int n = coins.size();
    vector<int> prev(sum+1,0);
    vector<int> cur(sum+1,0);
    //base case
    for(int j = 0;j <= sum ;j++){
        if(j % coins[0] == 0) prev[j] =  j/coins[0];
        else prev[j] = 1e9;
    }

    //explore all paths
    for(int i = 1;i < n;i++){
        for(int j = 0;j <= sum;j++){
            int not_take = prev[j];
            int take = 1e9;
            if(coins[i] <= j){
                take = 1 + cur[j-coins[i]];
            }
            cur[j] = min(take,not_take);
        }
        prev = cur;
    }

    int res = prev[sum];
    return res>=1e9?-1:res;
}

int main() {
    int n, sum;
    cin >> n; // Input the number of coin denominations
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i]; // Input the coin denominations
    }
    cin >> sum; // Input the target sum

    // Call and print results for each solution
    // cout << "Recursive Solution: " << minCoins(coins, sum) << endl;
    // cout << "Memoization Solution: " << minCoins(coins, sum) << endl;
    // cout << "Tabulation Solution: " << coinChange(coins, sum) << endl;
    cout << "Space Optimized Solution: " << coinChange(coins, sum) << endl;

    return 0;
}