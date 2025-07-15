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
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();

    vi prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 0; i <= m; i++)
        prev[i] = i;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                curr[j] = prev[j - 1];

            else
                curr[j] = 1 + min({prev[j],
                                   curr[j - 1], prev[j - 1]});
        }
        prev = curr;
    }
    cout << curr[m] << endl;
    return 0;
}
