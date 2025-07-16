#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define vi vector<int>
#define vll vector<long long>
#define vi2 vector<vector<int>>
#define vll2 vector<vector<long long>>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sumv(v) accumulate(all(v), 0LL)
#define sortv(v) sort(all(v))
#define rsortv(v) sort(rall(v))
#define revv(v) reverse(all(v))
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define cntv(v, x) count(all(v), x)
#define fndv(v, x) find(all(v), x)

#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void input(vi &arr)
{
    for (auto &it : arr)
        cin >> it;
}

bool solve(int idx, int currSum, int k, vi &arr)
{
    if (idx == arr.size())
        return currSum == k;

    bool skip = solve(idx + 1, currSum, k, arr);
    bool keep = false;
    if (currSum + arr[idx] <= k)
        keep = solve(idx + 1, currSum + arr[idx], k, arr);
    return keep || skip;
}

int main()
{
    fastio();

    int n;
    cin >> n;
    vi arr(n);
    input(arr);
    ll totalSum = sumv(arr);

    vi2 dp(n + 1, vi(totalSum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    dp[n][totalSum] = 1;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int sum = totalSum; sum >= 0; sum--)
        {
            bool skip = dp[idx + 1][sum];
            bool keep = false;
            if (sum + arr[idx] <= totalSum)
                keep = dp[idx + 1][sum + arr[idx]];
            dp[idx][sum] = keep || skip;
        }
    }
    cout << sumv(dp[0]) - 1 << endl;
    ;
    for (int sum = 1; sum <= totalSum; sum++)
    {
        if (dp[0][sum])
            cout << sum << " ";
    }

    return 0;
}
