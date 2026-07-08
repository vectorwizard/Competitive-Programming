#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll func(ll ind,ll first,ll second,ll third,vector<ll> &a,vector<ll> &b,vector<ll> &c,vector<vector<vector<vector<ll>>>> &dp){
    ll n = a.size();
    if(ind == n){
        if(first==0 && second==0 && third==0) return 0;
        return -1e9;
    }
    if(dp[ind][first][second][third]!=-1) return dp[ind][first][second][third];
    ll op1=0,op2=0,op3=0,op4=0;
    if(first>0) op1 = a[ind] + func(ind+1,first-1,second,third,a,b,c,dp);
    if(second>0) op2 = b[ind] + func(ind+1,first,second-1,third,a,b,c,dp);
    if(third>0) op3 = c[ind] + func(ind+1,first,second,third-1,a,b,c,dp);
    op4 = func(ind+1,first,second,third,a,b,c,dp);
    return dp[ind][first][second][third]=max(op1,max(op2,max(op3,op4)));
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<n;i++) cin>>c[i];
    vector<vector<vector<vector<ll>>>> dp(
    n + 1,
    vector<vector<vector<ll>>>(
        2,
        vector<vector<ll>>(
            2,
            vector<ll>(2, -1)
        )
    )
);
    ll ans = func(0,1,1,1,a,b,c,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
