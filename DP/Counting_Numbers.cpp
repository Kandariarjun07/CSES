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

#define input(v)       \
    for (auto &it : v) \
        cin >> it;

#define HASTESTCASES 0

ll dp[20][2][11][2];

ll helper(ll pos, ll tight, ll prev, ll lz, string &str)
{
    if (pos == str.length())
        return 1;

    if (dp[pos][tight][prev][lz] != -1)
        return dp[pos][tight][prev][lz];

    ll lb = 0;
    ll ub = (tight == 1) ? (str[pos] - '0') : 9;

    ll res = 0;

    for (ll d = lb; d <= ub; d++)
    {
        if (d == prev && lz == 0)
            continue;

        int new_lz = (d == 0) && (lz == 1);
        int new_tight = (tight && d == ub);
        res += helper(pos + 1, new_tight, d, new_lz, str);
    }

    return dp[pos][tight][prev][lz] = res;
}

void solve()
{
    ll a, b;
    cin >> a >> b;

    string l = to_string(a - 1);
    string r = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll ans_l = helper(0, 1, 10, 1, l);
    memset(dp, -1, sizeof(dp));
    ll ans_r = helper(0, 1, 10, 1, r);
    cout << ans_r - ans_l << endl;
}

int main()
{
    fastio();
#if HASTESTCASES
    int t;
    cin >> t;
    while (t--)
        solve();
#else
    solve();
#endif
    return 0;
}