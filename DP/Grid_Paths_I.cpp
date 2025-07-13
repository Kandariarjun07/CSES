#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void input1D(vector<int>&arr){for(auto &it : arr) cin>>it;}
void print(vector<int>&arr){for(auto &it : arr) {cout<<it<<" ";}cout<<endl;}

int dir[] = {0,1,0};

int main() {
    int n;
    cin>>n;

    vector<vector<int>> grid(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>(n,0));

    dp[n - 1][n - 1] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char ch;
            cin>> ch;
            grid[i][j] = ch == '.' ? 1 : 0;
        }
    }

    if (grid[n - 1][n - 1] == 0 || grid[0][0] == 0) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {

            if (grid[i][j] == 0) continue; 

            for(int k = 0; k < 2; k++) {

                int _i = i + dir[k], _j = j + dir[k + 1];

                if(_i < n && _j < n && grid[_i][_j] != 0) {
                    dp[i][j] = (dp[i][j] + dp[_i][_j]) % MOD;
                }
            }

        }
    }

    cout<<dp[0][0]<<endl;
    return 0;
}