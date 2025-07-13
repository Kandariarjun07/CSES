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


    vector<int> dp(desired_sum + 1,INT_MAX);
    dp[desired_sum] = 0;

    for(int currSum = desired_sum - 1; currSum >= 0; currSum--) {
        int minCount = INT_MAX;

        for(auto coin : coins) {
            if(currSum + coin <= desired_sum && dp[currSum + coin] != INT_MAX)
                dp[currSum] = min(dp[currSum],1 + dp[currSum + coin]);
        }
    }

    cout<<(dp[0] == INT_MAX?-1:dp[0])<<endl;
    return 0;
}