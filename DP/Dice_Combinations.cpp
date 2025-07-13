#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin>>n;

    vector<int> dp(n + 1 , 0);
    dp[n] = 1;

    for(int currSum = n - 1; currSum >= 0; currSum--) {
        int ways = 0;
        for(int i = 1; i <= 6 && currSum + i<= n; i++) {
                ways = (ways % MOD + dp[currSum + i] % MOD) % MOD;
        }
        dp[currSum] = ways;
    }

    cout<<dp[0]<<endl;

    return 0;
}