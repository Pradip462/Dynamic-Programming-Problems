#include<bits/stdc++.h>
using namespace std;

//Recursion Solution
int solved(int n,int m,int i,int j1,int j2,vector<vector<int>>& grid){
    //base cases
    //out of bound case
    if(j1 < 0 || j1 >=m || j2 < 0 || j2 >=m) return -1e9;
    //destination base case
    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    //explore all possible ways
    int maxi = INT_MIN;
    for(int dj1 = -1;dj1 <= 1;dj1++){
        for(int dj2 = -1;dj2 <= 1;dj2++){
            if(j1 == j2) maxi = max(maxi,grid[i][j1] + solved(n,m,i+1,j1+dj1,j2+dj2,grid));
            else maxi = max(maxi,grid[i][j1] + grid[i][j2] + solved(n,m,i+1,j1+dj1,j2+dj2,grid));
        }
    }
    
    return maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    return solved(n,m,0,0,m-1,grid);
}

//Memoization Solution
int solved(int n,int m,int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
    //base cases
    //out of bound case
    if(j1 < 0 || j1 >=m || j2 < 0 || j2 >=m) return -1e9;
    //destination base case
    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    //explore all possible ways
    int maxi = INT_MIN;
    for(int dj1 = -1;dj1 <= 1;dj1++){
        for(int dj2 = -1;dj2 <= 1;dj2++){
            if(j1 == j2) maxi = max(maxi,grid[i][j1] + solved(n,m,i+1,j1+dj1,j2+dj2,grid,dp));
            else maxi = max(maxi,grid[i][j1] + grid[i][j2] + solved(n,m,i+1,j1+dj1,j2+dj2,grid,dp));
        }
    }
    
    return dp[i][j1][j2] = maxi;
}
int rec_cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return solved(n,m,0,0,m-1,grid,dp);
}

//Tabulation Solution
int tab_cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1 = 0;j1 < m;j1++){
        for(int j2 = 0;j2 < m;j2++){
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    for(int i = n-2;i >= 0;i--){
        for(int j1 = 0;j1 < m;j1++){
            for(int j2 = 0;j2 < m;j2++){
                int maxi = INT_MIN;
                for(int dj1 = -1;dj1 <= 1;dj1++){
                    for(int dj2 = -1;dj2 <= 1;dj2++){
                        int value = 0;
                        if(j1 == j2) value += grid[i][j1];
                        else value += grid[i][j1] + grid[i][j2];
                        if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m){
                            value += dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            value += -1e9;
                        }
                        maxi = max(value,maxi);
                    }
                }
                dp[i][j1][j2] = maxi; 
            }
        }
    }
    return dp[0][0][m-1];
}

//Space Optimization Solution
int space_cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));
    for(int j1 = 0;j1 < m;j1++){
        for(int j2 = 0;j2 < m;j2++){
            if(j1 == j2) front[j1][j2] = grid[n-1][j1];
            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    for(int i = n-2;i >= 0;i--){
        for(int j1 = 0;j1 < m;j1++){
            for(int j2 = 0;j2 < m;j2++){
                int maxi = INT_MIN;
                for(int dj1 = -1;dj1 <= 1;dj1++){
                    for(int dj2 = -1;dj2 <= 1;dj2++){
                        int value = 0;
                        if(j1 == j2) value += grid[i][j1];
                        else value += grid[i][j1] + grid[i][j2];
                        if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m){
                            value += front[j1+dj1][j2+dj2];
                        }
                        else{
                            value += -1e9;
                        }
                        maxi = max(value,maxi);
                    }
                }
                cur[j1][j2] = maxi; 
            }
        }
        front = cur;
    }
    return front[0][m-1];
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
    cout << rec_cherryPickup(arr);
    // cout << mem_cherryPickup(arr);
    // cout << tab_cherryPickup(arr);
    // cout << space_cherryPickup(arr);
    return 0;
}