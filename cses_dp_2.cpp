#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll func(int sum,vector<int> &coins,vector<ll> &dp){
    if(sum==0) return 0;
    if(dp[sum]!=-1) return dp[sum];
    ll ans = INT_MAX;
    for(int i=0;i<(int)coins.size();i++){
        if(coins[i]>sum) break;
        ans = min(ans,1+func(sum-coins[i],coins,dp));
    }
    return dp[sum]=ans;
}
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    vector<ll> dp(x+1,-1);
    ll ans = func(x,coins,dp);
    if(ans>=INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
