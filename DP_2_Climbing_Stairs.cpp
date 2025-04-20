#include <bits/stdc++.h>
using namespace std;

// ----------- 1. Brute-Force Recursion -----------
int bruteForce(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return bruteForce(n - 1) + bruteForce(n - 2);
}
// The brute-force approach has exponential time complexity O(2^n) and is inefficient for large n.
// It is included here for completeness, but it is not recommended for practical use due to its inefficiency.
// The memoization, tabulation, and space-optimized approaches are much more efficient.

// ----------- 2. Memoization (Top-Down DP) -----------
int memoSolve(int n, vector<int> &dp) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = memoSolve(n - 1, dp) + memoSolve(n - 2, dp);
}


int memoization(int n) {
    vector<int> dp(n + 1, -1);
    return memoSolve(n, dp);
}
//Time Complexity: O(n) for Memoization, Space Complexity: O(n) for the dp array.
// The memoization approach stores the results of subproblems in a dp array to avoid redundant calculations.

// ----------- 3. Tabulation (Bottom-Up DP) -----------
int tabulation(int n) {
    if (n < 2) return 1;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// Time Complexity: O(n) for Tabulation, Space Complexity: O(n) for the dp array.
// The tabulation approach builds the dp array iteratively from the base cases up to n.

// ----------- 4. Space-Optimized DP -----------
int spaceOptimized(int n) {
    if (n < 2) return 1;
    int prev2 = 1; // dp[0]
    int prev1 = 1; // dp[1]
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
// Time Complexity: O(n) for Space Optimized, Space Complexity: O(1) as we only use two variables to store the last two results.
// The space-optimized approach reduces the space complexity by only keeping track of the last two computed values.

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    // Choose the approach you want to run:
    cout << "Brute Force: " << bruteForce(n) << endl;
    cout << "Memoization: " << memoization(n) << endl;
    cout << "Tabulation: " << tabulation(n) << endl;
    cout << "Space Optimized: " << spaceOptimized(n) << endl;

    return 0;
}
// Time Complexity: O(n) for Memoization, Tabulation, and Space Optimized approaches.
// Space Complexity: O(n) for Memoization and Tabulation, O(1) for Space Optimized approach.