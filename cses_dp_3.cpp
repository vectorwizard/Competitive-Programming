#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
ll func(int sum,vector<int> &coins,vector<ll> &dp){
    if(sum==0) return 1;
    if(sum<coins[0]) return 0;
    if(dp[sum]!=-1) return dp[sum];
    ll ways = 0;
    for(int i=0;i<coins.size();i++){
        if(coins[i]>sum) break;
        ways+=func(sum-coins[i],coins,dp)%mod;
    }
    return dp[sum]=ways%mod;
}
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    vector<ll> dp(x+1,-1);
    ll ans = func(x,coins,dp)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
