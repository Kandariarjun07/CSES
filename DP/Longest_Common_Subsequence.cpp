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

int solve(int i, int j, vi &A, vi &B)
{
    if (i == A.size() || j == B.size())
        return 0;

    if (A[i] == B[j])
        return 1 + solve(i + 1, j + 1, A, B);

    return max(solve(i, j + 1, A, B), solve(i + 1, j, A, B));
}

int main()
{
    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    input(A), input(B);

    vi2 dp(n + 1, vi(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (A[i] == B[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];

            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << endl;
    vi lcs;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] == B[j])
        {
            lcs.push_back(A[i]);
            i++, j++;
        }
        else if (dp[i + 1][j] >= dp[i][j + 1])
            i++;
        else
            j++;
    }
    for (auto it : lcs)
        cout << it << " ";
    cout << endl;
    return 0;
}
