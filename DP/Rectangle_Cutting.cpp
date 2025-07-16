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
    int a, b;
    cin >> a >> b;

    vi2 dp(a + 1, vi(b + 1, INT_MAX));

    for (int height = 1; height <= a; height++)
    {
        for (int width = 1; width <= b; width++)
        {
            if (height == width)
            {
                dp[height][width] = 0;
                continue;
            }
            for (int h = 1; h < height; h++)
            {
                dp[height][width] = min(dp[height][width], 1 + dp[h][width] + dp[height - h][width]);
            }
            for (int w = 1; w < width; w++)
            {
                dp[height][width] = min(dp[height][width], 1 + dp[height][w] + dp[height][width - w]);
            }
        }
    }

    cout << dp[a][b] << endl;
    return 0;
}
