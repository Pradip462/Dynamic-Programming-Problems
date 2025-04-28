#include<bits/stdc++.h>
using namespace std;

//Recursion Solution
int solve(int i,int j,vector<vector<int>>& mat){
    //base case
    if(i == 0) return mat[0][j];
    //out of bound
    if(j < 0 || j >= mat[0].size()) return -1e9;
    //do all stuffs
    int up = mat[i][j] + solve(i-1,j,mat);
    int ld = mat[i][j] + solve(i-1,j-1,mat);
    int rd = mat[i][j] + solve(i-1,j+1,mat);
    
    return max(up,max(ld,rd));
}
int rec_maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = INT_MIN;
    for(int j = 0;j < m;j ++){
        int res = solve(n-1,j,mat);
        ans = max(ans,res);
    }
    return ans;
}
//Memoization Solution
int solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
    //out of bound
    if(j < 0 || j >= mat[0].size()) return -1e9;
    //base case
    if(i == 0) return mat[0][j];
    //do all stuffs
    int up = mat[i][j] + solve(i-1,j,mat);
    int ld = mat[i][j] + solve(i-1,j-1,mat);
    int rd = mat[i][j] + solve(i-1,j+1,mat);
    
    return max(up,max(ld,rd));
}
int mem_maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = INT_MIN;
    for(int j = 0;j < m;j ++){
        int res = solve(n-1,j,mat);
        ans = max(ans,res);
    }
    return ans;
}

//Tabularion Solution
int tab_maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    //base case
    for(int j = 0;j < m;j++){
        dp[0][j] = mat[0][j];
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < m;j++){
            int up = mat[i][j] + dp[i-1][j];
            int ld = mat[i][j];
            if(j-1 >= 0) ld += dp[i-1][j-1];
            else ld += -1e9;
            int rd = mat[i][j];
            if(j+1 < m) rd += dp[i-1][j+1];
            else rd += -1e9;
            dp[i][j] = max(up,max(ld,rd));
        }
    }
    
    int maxi = dp[n-1][0];
    for(int j = 1;j < m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
    
}

//Space Optimizing
int space_maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> prev(m);
    //base case
    for(int j = 0;j < m;j++){
        prev[j] = mat[0][j];
    }
    for(int i = 1;i < n;i++){
        vector<int> cur(m);
        for(int j = 0;j < m;j++){
            int up = mat[i][j] + prev[j];
            int ld = mat[i][j];
            if(j-1 >= 0) ld += prev[j-1];
            else ld += -1e9;
            int rd = mat[i][j];
            if(j+1 < m) rd += prev[j+1];
            else rd += -1e9;
            cur[j] = max(up,max(ld,rd));
        }
        prev = cur;
    }
    
    int maxi = prev[0];
    for(int j = 1;j < m;j++){
        maxi = max(maxi,prev[j]);
    }
    
    return maxi;
    
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
    cout << rec_maximumPath(arr);
    // cout << mem_maximumPath(arr);
    // cout << tab_maximumPath(arr);
    // cout << space_maximumPath(arr);
    return 0;
}