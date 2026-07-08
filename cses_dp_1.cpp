#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
ll func(int sum,vector<ll> &dp){
    if(sum==0) return 1;
    if(dp[sum]!=-1) return dp[sum];
    ll ways = 0;
    for(int i=1;i<=6;i++){
        if(sum<i) break;
        ways+=func(sum-i,dp)%mod;
    }
    return dp[sum]=ways%mod;
}
void solve() {
    int n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    ll ans = func(n,dp);
    cout<<ans%mod<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
