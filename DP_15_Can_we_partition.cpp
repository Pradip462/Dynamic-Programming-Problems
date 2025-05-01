#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& arr,int ind,int target,vector<vector<int>> &dp){
    //base case
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    int not_take = solve(arr,ind-1,target,dp);
    int take = false;
    if(arr[ind] <= target){
        take = solve(arr,ind-1,target-arr[ind],dp);
    }
    
    return dp[ind][target] = take || not_take;
}
bool equalPartition(vector<int>& arr) {
    int n  = arr.size();
    int sum = 0;
    for(int i = 0;i < n ;i++){
        sum += arr[i];
    }
    if(sum % 2 != 0) return false;
    int target = sum/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return solve(arr,n-1,target,dp);
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }
    if (equalPartition(arr)) {
        cout << "YES"; // If the array can be partitioned into two subsets with equal sum
    } else {
        cout << "NO"; // If the array cannot be partitioned into two subsets with equal sum
    }
    return 0;
}