#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));
    for(int l=1;l<=a;l++){
        for(int w=1;w<=b;w++){
            if(l==w){
                dp[l][w] = 0;
                continue;
            }
            int ans = INT_MAX;
            for(int i=1;i<l;i++){
                int x = 1+dp[i][w]+dp[l-i][w];
                ans = min(ans,x);
            }
            for(int i=1;i<w;i++){
                int x = 1+dp[l][i]+dp[l][w-i];
                ans = min(ans,x);
            }
            dp[l][w]=ans;
        }
    }
    int final = dp[a][b];
    cout<<final;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
