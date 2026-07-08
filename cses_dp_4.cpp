#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    for(int ind = n-1;ind>=0;ind--){
        for(int sum=0;sum<=x;sum++){
            int take = 0;
        if(coins[ind]<=sum) take = dp[ind][sum-coins[ind]]%mod;
        int nottake = dp[ind+1][sum]%mod;
        dp[ind][sum]=(take+nottake)%mod;
        }
    }
    cout<<dp[0][x]<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
