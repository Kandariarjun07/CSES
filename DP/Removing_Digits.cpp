#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void input(vector<int>&arr){for(auto &it : arr) cin>>it;}
void print(vector<int>&arr){for(auto &it : arr) {cout<<it<<" ";}cout<<endl;}

int main() {
    int n;
    cin>>n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int currNum = 1; currNum <= n; currNum++) {
        int temp = currNum;
        while(temp) {

            int digit = temp % 10;
            temp /= 10;

            if(digit == 0) continue;
            
            if(currNum - digit >= 0 && dp[currNum - digit] != INT_MAX)
                dp[currNum] = min(dp[currNum] , 1 + dp[currNum - digit]);
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}