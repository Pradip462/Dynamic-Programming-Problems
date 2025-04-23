#include<bits/stdc++.h>
using namespace std;

//Recursion Solution
int solve(int day,int last,vector<vector<int>>& arr){
    //base case
    if(day == 0){
        int maxi = INT_MIN;
        for(int i = 0;i < 3;i++){
            if(i != last){
                maxi = max(maxi,arr[0][i]);
            }
        }
        return maxi;
    }
    
    int maxi = INT_MIN;
    for(int i = 0;i < 3;i++){
        if(i != last){
            int points = arr[day][i] + solve(day-1,i,arr);
            maxi = max(maxi,points);
        }
    }
    return maxi;
}
int rec_maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    return solve(n-1,n,arr);
}


//Memoization Solution
//here we use 2D DP
int solve(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& dp){
    //base case
    if(day == 0){
        int maxi = INT_MIN;
        for(int i = 0;i < 3;i++){
            if(i != last){
                maxi = max(maxi,arr[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = INT_MIN;
    for(int i = 0;i < 3;i++){
        if(i != last){
            int points = arr[day][i] + solve(day-1,i,arr);
            maxi = max(maxi,points);
        }
    }
    return dp[day][last] = maxi;
}
int mem_maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(n-1,n,arr,dp);
}

//Tabulation Solution
int mem_maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(arr[0][1],arr[0][2]);
    dp[0][1] = max(arr[0][0],arr[0][2]);
    dp[0][2] = max(arr[0][0],arr[0][1]);
    dp[0][3] = max(arr[0][0],max(arr[0][1],dp[0][2])); 
    
    for(int day = 1;day < n;day++){
        for(int last = 0;last < 4;last++){
            dp[day][last] = 0;
            for(int task = 0;task < 3;task++){
                if(task != last){
                    int point = arr[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

//Space Optimization
int maximumPoints(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<int> dp(4,0);
    dp[0] = max(arr[0][1],arr[0][2]);
    dp[1] = max(arr[0][0],arr[0][2]);
    dp[2] = max(arr[0][0],arr[0][1]);
    dp[3] = max(arr[0][0],max(arr[0][1],arr[0][2])); 
    
    for(int day = 1;day < n;day++){
        vector<int> temp(4,0);
        for(int last = 0;last < 4;last++){
            temp[last] = 0;
            for(int task = 0;task < 3;task++){
                if(task != last){
                    int point = arr[day][task] + dp[task];
                    temp[last] = max(temp[last],point);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}

//main function
int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 3;j++){
            cin >> arr[i][j];
        }
    }
    // cout << rec_maximumPoints(arr);
    cout << mem_maximumPoints(arr);
    // cout << tab_maximumPoints(arr);
    // cout << space_maximumPoints(arr);
    return 0;
}