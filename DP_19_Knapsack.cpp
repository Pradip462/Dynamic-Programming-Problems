#include<bits/stdc++.h>
using namespace std;

// Recursion Solution
int solve(int ind,int W,vector<int> &val, vector<int> &wt){
    if(ind == 0){
        if(W >= wt[ind]) return val[ind];
        else return 0;
    }
    int not_pick = 0 + solve(ind - 1,W,val,wt);
    int pick = INT_MIN;
    if(W >= wt[ind]) pick = val[ind] + solve(ind-1,W-wt[ind],val,wt);
    
    return max(pick,not_pick);
}
int knapsack_rec(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    return solve(n-1,W,val,wt);
}

// Memoization Solution
int solve(int ind,int W,vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){
    if(ind == 0){
        if(W >= wt[ind]) return val[ind];
        else return 0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    
    int not_pick = 0 + solve(ind - 1,W,val,wt,dp);
    int pick = INT_MIN;
    if(W >= wt[ind]) pick = val[ind] + solve(ind-1,W-wt[ind],val,wt,dp);
    
    return dp[ind][W] = max(pick,not_pick);
}
int knapsack_memo(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return solve(n-1,W,val,wt,dp);
}

// Tabulation Solution
int knapsack_tab(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,0));

    for(int i = 0;i < W+1;i++){
        if(i >= wt[0]) dp[0][i] = val[0];
        else dp[0][i] = 0;
    }

    for(int ind = 1;ind < n;ind++){
        for(int j = 0;j < W+1;j++){
            int not_pick = 0 + dp[ind - 1][j];
            int pick = INT_MIN;
            if(j >= wt[ind]) pick = val[ind] + dp[ind-1][j-wt[ind]];
            
            dp[ind][j] = max(pick,not_pick);
        }
    }
    return dp[n-1][W];
}

// Space Optimization
int knapsack_opt(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> prev(W+1,0);

    for(int i = 0;i < W+1;i++){
        if(i >= wt[0]) prev[i] = val[0];
        else prev[i] = 0;
    }

    for(int ind = 1;ind < n;ind++){
        for(int j = W;j >= 0;j--){
            int not_pick = 0 + prev[j];
            int pick = INT_MIN;
            if(j >= wt[ind]) pick = val[ind] + prev[j-wt[ind]];
            
            prev[j] = max(pick,not_pick);
        }
    }
    return prev[W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> val(n), wt(n);
    cout << "Enter values of items:\n";
    for(int i = 0; i < n; i++) cin >> val[i];
    
    cout << "Enter weights of items:\n";
    for(int i = 0; i < n; i++) cin >> wt[i];
    
    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "\nResults:\n";
    cout << "Recursive solution: " << knapsack_rec(W, val, wt) << endl;
    cout << "Memoization solution: " << knapsack_memo(W, val, wt) << endl;
    cout << "Tabulation solution: " << knapsack_tab(W, val, wt) << endl;
    cout << "Space Optimized solution: " << knapsack_opt(W, val, wt) << endl;

    return 0;
}
