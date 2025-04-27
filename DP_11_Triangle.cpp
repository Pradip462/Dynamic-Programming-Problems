#include<bits/stdc++.h>
using namespace std;

//Recursion Solution
int solve(int i,int j,vector<vector<int>>& tri){
    //base case
    if(i == tri.size()-1) return tri[i][j];
    //do all stuff on that index
    int down = tri[i][j] + solve(i+1,j,tri);
    int dia = tri[i][j] + solve(i+1,j+1,tri);
    
    return min(down,dia);
}
int rec_minPathSum(vector<vector<int>>& triangle) {
    int m = triangle.size();
    int n = triangle[0].size();
    return solve(0,0,triangle);
}

//Memoization Solution
int solve(int i,int j,vector<vector<int>>& tri,vector<vector<int>> &dp){
    //base case
    if(i == tri.size()-1) return tri[tri.size()-1][j];
    if(dp[i][j] != -1) return dp[i][j];
    //do all stuff on that index
    int down = tri[i][j] + solve(i+1,j,tri,dp);
    int dia = tri[i][j] + solve(i+1,j+1,tri,dp);
    
    return dp[i][j] = min(down,dia);
}
int mem_minPathSum(vector<vector<int>>& triangle) {
    int m = triangle.size();
    int n = triangle[0].size();
    vector<vector<int>> dp(m);
    for (int i = 0; i < m; ++i) {
        dp[i].resize(triangle[i].size(), -1);
    }
    return solve(0,0,triangle,dp);
}

//Tabulation Solution
int tab_minPathSum(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i].resize(triangle[i].size(), -1);
    }
    for(int j = 0;j < n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    for(int i = n-2;i >= 0;i --){
        for(int j = i;j >= 0;j --){
            int down = triangle[i][j] + dp[i+1][j];
            int diag = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,diag);
        }
    }
    return dp[0][0];
}

//Space Optimization
int space_minPathSum(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n);
    for(int i = n-1;i >= 0;i --){
        vector<int> cur(i+1); //because it need i+1 element tpo store 
        //as we know the row i contain i+1 elements
        for(int j = i;j >= 0;j --){
            if(i == n-1) cur[j] = triangle[i][j];
            else{
                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j+1];
                cur[j] = min(down,diag);
            }
        }
        dp = cur;
    }
    return dp[0];
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
    cout << rec_minPathSum(arr);
    // cout << mem_minPathSum(arr);
    // cout << tab_minPathSum(m,n,arr);
    // cout << space_minPathSum(m,n);
    return 0;
}