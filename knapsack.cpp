#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to find the maximum profit
ll knapsack(ll W, vector<ll> &val, vector<ll> &wt) {

    // Initializing dp vector
    vector<ll> dp(W + 1, 0);

    // Taking first i elements
    for (ll i = 1; i <= wt.size(); i++) {

        // Starting from back, so that we also have data of
        // previous computation of i-1 items
        for (ll j = W; j >= wt[i - 1]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int main() {
    vector<ll> val = {1, 2, 3};
    vector<ll> wt = {4, 5, 1};
    ll W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}
