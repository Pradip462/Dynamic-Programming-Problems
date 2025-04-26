#include<bits/stdc++.h>
using namespace std;

//Recursion Solution
int solve(int i,int j,vector<vector<int>>& grid){
    //base case
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e9;
    //do all stuffs
    int up = grid[i][j] + solve(i-1,j,grid);
    int left = grid[i][j] + solve(i,j-1,grid);
    return min(up,left);
}
int rec_minimumpath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    return solve(m-1,n-1,grid);
}

//Memoization Solution
int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //base case
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e9;
    if(dp[i][j] != -1) return dp[i][j];
    //do all stuffs
    int up = grid[i][j] + solve(i-1,j,grid,dp);
    int left = grid[i][j] + solve(i,j-1,grid,dp);
    return dp[i][j] = min(up,left);
}
int mem_minimumpath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,grid,dp);
}
//Tabulation Solution
int tab_minimumpath(int m,int n,vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    for(int i = 0;i < m;i ++){
        for(int j = 0;j < n;j++){
            if(i == 0 && j == 0) dp[0][0] = grid[0][0];
            else{
                int up = 0;
                if(i > 0) up = grid[i][j] + dp[i-1][j];
                else up += 1e9;
                int left = 0;
                if(j > 0) left = grid[i][j] + dp[i][j-1];
                else left += 1e9;
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[m-1][n-1];
}
//Space Optimization Solution

//main function
int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m,vector<int> (n));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
        }
    }
    // cout << tab_minimumpath(m,n,arr);
    // cout << tab_minimumpath(m,n);
    cout << tab_minimumpath(m,n,arr);
    // cout << tab_minimumpath(m,n);
    return 0;
}