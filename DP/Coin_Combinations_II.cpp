#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void input(vector<int>&arr){for(auto &it : arr) cin>>it;}
void print(vector<int>&arr){for(auto &it : arr) {cout<<it<<" ";}cout<<endl;}

int main() {
    int n,desired_sum;
    cin>>n>>desired_sum;
    vector<int> coins(n);
    input(coins);


    vector<vector<int>> dp(n + 1,vector<int> (desired_sum + 1,0));
    for(int idx = 0; idx < n; idx++) dp[idx][desired_sum] = 1;

    for(int idx = n - 1; idx >= 0; idx--) {
        for(int sum = desired_sum - 1; sum >= 0; sum--) {

            if(sum + coins[idx] <= desired_sum) {

                dp[idx][sum] = (dp[idx][sum] + dp[idx][sum + coins[idx]]) % MOD;
            }

            dp[idx][sum] = (dp[idx][sum] + dp[idx + 1][sum]) % MOD;
        }
    }


    cout<<dp[0][0]<<endl;
    return 0;
}