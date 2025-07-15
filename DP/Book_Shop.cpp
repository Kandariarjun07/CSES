#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
void input(vector<int>&arr){for(auto &it : arr) cin>>it;}
void print(vector<int>&arr){for(auto &it : arr) {cout<<it<<" ";}cout<<endl;}

int main() {
    int n,total_price;
    cin>>n>>total_price;
    vector<int> prices(n), pages(n);
    input(prices);
    input(pages);

    vector<int> after(total_price + 1, 0), curr(total_price + 1, 0);

    for(int idx = n - 1; idx >= 0; idx--) {
        for(int money_left = 0; money_left <= total_price; money_left++) {
            int buy_this_book = INT_MIN;
            int dont_buy =after[money_left];

            if(prices[idx] <= money_left) {
                buy_this_book = pages[idx] + after[money_left - prices[idx]];
            }

            curr[money_left] = max(buy_this_book, dont_buy);
        }
        after = curr;
    }
 
 
    cout<<curr[total_price]<<endl;
    return 0;
}
