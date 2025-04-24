#include<bits/stdc++.h>
using namespace std;
//Recursion Solution
int solve(int i,int j){
    //base case
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    int up = solve(i-1,j);
    int left = solve(i,j-1);
    return up+left;
}

int rec_uniquepath(int m,int n){
    return solve(m-1,n-1);
}


//Memoization Solution
int solve(int i,int j,vector<vector<int>> &dp){
    //base case
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int up = solve(i-1,j,dp);
    int left = solve(i,j-1,dp);
    return up+left;
}
int mem_uniquepath(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,dp);
}


//Tabulation Solution
int tab_uniquepath(int m,int n){
    vector<vector<int>> dp(m,vector<int>(n));
    // if(i == 0 && j == 0) return 1;
    // if(i < 0 || j < 0) return 0;

    // if(dp[i][j] != -1) return dp[i][j];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(i == 0 & j == 0) dp[0][0] = 1;
            else{
                int up = 0;
                if(i > 0) up = dp[i-1][j];
                int left = 0;
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }            
        }
    }
    
    return dp[m-1][n-1];
}

int space_uniquepath(int m,int n){
    vector<int> prev(n,0);//make the previous row elements 0
    for(int i = 0;i < m;i ++){
        vector<int> cur(n,0);
        for(int j = 0;j <n;j++){
            if(i == 0 && j == 0) cur[j] = 1;
            else{
                cur[j] = prev[j] + cur[j-1];
            }
        }
        prev = cur;//shifitng the value of current row to the prev array to use it in next row
    }
    return prev[n-1];
}
//main function
int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m,vector<int> (n));
    // cout << rec_uniquepath(m,n);
    // cout << mem_uniquepath(m,n);
    // cout << tab_uniquepath(m,n);
    cout << space_uniquepath(m,n);
    return 0;
}