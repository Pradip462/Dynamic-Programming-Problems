#include <iostream>
#include <vector>
using namespace std;



//Recusrsion Solution
int solve(vector<int>& arr, int ind,int target){
    //base case
    if(ind == 0){
        if(arr[ind] == target && target == 0) return 2;
        if(arr[ind] == target || target == 0) return 1;
        return 0;
    }
    
   
    
    int not_pick = solve(arr,ind-1,target);
    int pick = 0;
    if(target >= arr[ind]) pick = solve(arr,ind-1,target-arr[ind]);
    
    return pick + not_pick;
}
int rec_countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }
    if((sum - d) < 0 || (sum - d) % 2 != 0) return false;
    int target = (sum - d)/2;
    return solve(arr,n-1,target);
}
//Memoization Solution
int solve(vector<int>& arr, int ind,int target,vector<vector<int>> &dp){
    //base case
    if(ind == 0){
        if(arr[ind] == target && target == 0) return 2;
        if(arr[ind] == target || target == 0) return 1;
        return 0;
    }
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int not_pick = solve(arr,ind-1,target,dp);
    int pick = 0;
    if(target >= arr[ind]) pick = solve(arr,ind-1,target-arr[ind],dp);
    
    return dp[ind][target] = pick + not_pick;
}
int mem_countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }
    if((sum - d) < 0 || (sum - d) % 2 != 0) return false;
    int target = (sum - d)/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return solve(arr,n-1,target,dp);
}

//tabulation Solution
int tab_countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }
    if((sum - d) < 0 || (sum - d) % 2 != 0) return false;
    int target = (sum - d)/2;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    //tabulation part
    for(int i = 0;i <= target;i++){
        if(arr[0] == i && i == 0) dp[0][i] = 2;
        else if(arr[0] == i || i == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int ind = 1;ind < n;ind++){
        for(int tar = 0;tar <= target;tar++){
            int not_pick = dp[ind-1][tar];
            int pick = 0;
            if(tar >= arr[ind]) pick = dp[ind-1][tar-arr[ind]];
            dp[ind][tar] = pick + not_pick;
        }
    }
    return dp[n-1][target];
}
//Space Optimization Solution
int space_opt_countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }
    if((sum - d) < 0 || (sum - d) % 2 != 0) return 0;
    int target = (sum - d)/2;
    vector<int> prev(target+1,0);
    vector<int> cur(target+1,0);
    //tabulation part
    for(int i = 0;i <= target;i++){
        if(arr[0] == 0 && i == 0) cur[i] = 2;
        else if(i == 0) cur[i] = 1;
        else if(arr[0] == i ) cur[i] = 1;
        else cur[i] = 0;
    }
    
    prev = cur;
    
    for(int ind = 1;ind < n;ind++){
        for(int tar = 0;tar <= target;tar++){
            int not_pick = prev[tar];
            int pick = 0;
            if(tar >= arr[ind]) pick = prev[tar-arr[ind]];
            cur[tar] = pick + not_pick;
        }
        prev = cur;
    }
    return prev[target];
}
// int countPartitions(vector<int>& arr, int d) {
//     int n = arr.size();
//     int sum = 0;
//     for(int i = 0;i < n;i++){
//         sum += arr[i];
//     }
//     if((sum - d) < 0 || (sum - d) % 2 != 0) return 0;
//     int target = (sum - d)/2;
//     vector<int> prev(target+1,0);
//     vector<int> cur(target+1,0);
//     //tabulation part
//     for(int i = 0;i <= target;i++){
//         if(arr[0] == 0 && i == 0) prev[i] = 2;
//         else if(i == 0) prev[i] = 1;
//         else if(arr[0] == i ) prev[i] = 1;
//         else prev[i] = 0;
//     }
    
//     // prev = cur;
    
//     for(int ind = 1;ind < n;ind++){
//         for(int tar = 0;tar <= target;tar++){
//             int not_pick = prev[tar];
//             int pick = 0;
//             if(tar >= arr[ind]) pick = prev[tar-arr[ind]];
//             cur[tar] = pick + not_pick;
//         }
//         prev = cur;
//     }
//     return prev[target];
// }

int main() {
    int n, d;
    cin >> n; // Input the size of the array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }
    cin >> d; // Input the difference value

    // Call and print results for each solution
    cout << "Recursive Solution: " << rec_countPartitions(arr, d) << endl;
    cout << "Memoization Solution: " << mem_countPartitions(arr, d) << endl;
    cout << "Tabulation Solution: " << tab_countPartitions(arr, d) << endl;
    cout << "Space Optimized Solution: " << space_opt_countPartitions(arr, d) << endl;

    return 0;
}