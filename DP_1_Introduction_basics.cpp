#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//Top Down Approach
//Time Complexity: O(n)
//Space Complexity: O(n)
long long int top(int n,vector<long long int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = (top(n-1,dp) + top(n-2,dp)) % MOD;
}
long long int topDown(int n) {
    vector<long long int> dp(n+1,-1);
    return top(n,dp);
}
//Bottom Up Approach
//Time Complexity: O(n)
//Space Complexity: O(n)
long long int bottomUp(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    vector<long long int> dp(n+1,0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i <= n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}
//Space Optimized Approach
//Time Complexity: O(n)     
//Space Complexity: O(1)
//We only need the last two Fibonacci numbers to calculate the next one.
long long int spaceOptimized(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long int prev2 = 0, prev1 = 1, curr;
    for(int i = 2;i <= n;i++){
        curr = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main() {
    int n;
    cin >> n;
    cout << "Top Down: " << topDown(n) << endl;
    cout << "Bottom Up: " << bottomUp(n) << endl;
    cout << "Space Optimized: " << spaceOptimized(n) << endl;
    return 0;
}