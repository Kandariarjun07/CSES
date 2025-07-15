#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define vi vector<int>
#define vll vector<long long>

#define vi2 vector<vector<int>>
#define vll2 vector<vector<long long>>

vi2 dp(1e6 + 1, vi(2));

void input(vector<int> &arr)
{
    for (auto &it : arr)
        cin >> it;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        dp[n][0] = 1;
        dp[n][1] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {

            dp[idx][0] = (2LL * dp[idx + 1][0] + dp[idx + 1][1]) % MOD;
            dp[idx][1] = (4LL * dp[idx + 1][1] + dp[idx + 1][0]) % MOD;
        }

        cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    }

    return 0;
}