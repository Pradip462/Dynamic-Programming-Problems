#include<bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

//Recursion Solution
int solve(int i,int j,vector<vector<int>> &grid){
    //base case
    if(i >= 0 && j>= 0 && grid[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    int up = solve(i-1,j,grid);
    int left = solve(i,j-1,grid);
    return up+left;
}

int rec_uniquepath(int m,int n,vector<vector<int>> &grid){
    return solve(m-1,n-1,grid);
}

int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //base case
    if(i >= 0 && j >= 0 && grid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    //do all stuffs
    return dp[i][j] = solve(i-1,j,grid,dp)+solve(i,j-1,grid,dp);
}
int mem_uniquepath(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,grid,dp);
}

//Space Optimization Solution
int space_uniquepath(int n, int m, vector<vector<int>>& grid) {
    vector<int> prev(m,0);
    for(int i = 0;i < n;i++){
        vector<int> cur(m,0);
        for(int j= 0;j < m;j++){
            if(grid[i][j] == 1){
                cur[j] = 0;
            } 
            else if(i == 0 && j == 0) cur[0] = 1;
            else{
                int up = 0;
                if(i > 0) up = prev[j];
                int left = 0;
                if(j > 0) left = cur[j-1];
                cur[j] = (up + left)%mod;
            }
        }
        prev = cur;
    }
    return prev[m-1]%mod;
}

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
    cout << rec_uniquepath(m,n,arr);
    // cout << mem_uniquepath(m,n);
    // cout << tab_uniquepath(m,n);
    // cout << space_uniquepath(m,n);
    return 0;
}