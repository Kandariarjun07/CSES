#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define vi vector<int>
#define vll vector<long long>

#define vi2 vector<vector<int>>
#define vll2 vector<vector<long long>>

void input(vi &arr)
{
    for (auto &it : arr)
        cin >> it;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vi arr(n);
    input(arr);

    vi2 dp(n, vi(m + 2, 0));

    if (arr[n - 1] == 0)
    {
        for (int num = 1; num <= m; num++)
        {
            dp[n - 1][num] = 1;
        }
    }
    else
    {
        dp[n - 1][arr[n - 1]] = 1;
    }

    for (int idx = n - 2; idx >= 0; idx--)
    {
        for (int num = 1; num <= m; num++)
        {
            if (arr[idx] != 0 && arr[idx] != num)
                continue;

            for (int d = -1; d <= 1; d++)
            {
                int next = num + d;
                if (next >= 1 && next <= m)
                {
                    dp[idx][num] = (dp[idx][num] + dp[idx + 1][next]) % MOD;
                }
            }
        }
    }

    int result = 0;
    if (arr[0] == 0)
    {
        for (int num = 1; num <= m; num++)
        {
            result = (result + dp[0][num]) % MOD;
        }
    }
    else
    {
        result = dp[0][arr[0]];
    }

    cout << result << endl;
    return 0;
}

// why arr[idx] != num
//  this means as long as for idx, actual number is not equal to num, computer for dp[idx][num] is not req as it will result in extra computation and wrong ans.