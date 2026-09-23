#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll ind,ll rem,vector<ll> &a,vector<vector<ll>> &dp){
    ll n = a.size();
    if(rem==0) return true;
    if(ind==n){
        return false;
    }
    if(dp[ind][rem]!=-1) return dp[ind][rem];
    bool ans = false;
    if(rem>=a[ind]) ans = ans | func(ind+1,rem-a[ind],a,dp);
    ans = ans | func(ind+1,rem,a,dp);
    return dp[ind][rem]=ans;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll total = accumulate(a.begin(),a.end(),0LL);
    if(total%2==1){
        cout<<0<<endl;
        return;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(total+1,-1));
    bool ans = func(0,total/2,a,dp);
    if(!ans){
        cout<<0<<endl;
        return;
    }
    cout<<1<<endl;
    ll mini = 1e9;
    ll fin = -1;
    for(ll i=0;i<n;i++){
        ll tz = __builtin_ctz(a[i]);
        if(tz<mini){
            mini = tz;
            fin = i+1;
        }
    }
    cout<<fin<<endl;
}

int main() {
    fastio();
    ll t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}
