#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>

#define vc2 vector<vector<char>>
#define vi2 vector<vector<int>>
#define vll2 vector<vector<long long>>

void input(vi &arr)
{
    for (auto &it : arr)
        cin >> it;
}

int main()
{
    int n;
    cin >> n;
    vc2 grid(n, vc(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<string>> dp(n + 1, vector<string>(n + 1));

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (i == n - 1 && j == n - 1)
                dp[i][j] = "";
            else if (i == n - 1)
                dp[i][j] = grid[i][j + 1] + dp[i][j + 1];
            else if (j == n - 1)
                dp[i][j] = grid[i + 1][j] + dp[i + 1][j];
            else
                dp[i][j] = min(grid[i + 1][j] + dp[i + 1][j], grid[i][j + 1] + dp[i][j + 1]);
        }
    }

    cout << grid[0][0] + dp[0][0] << '\n';


    return 0;
}
