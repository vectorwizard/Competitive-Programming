#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool func(ll i,vector<ll> &b, map<ll,vector<ll>> &mpp,vector<ll> &dp){
    ll n = b.size();
    if(i>n) return false;
    if(i == n) return true;
    if(dp[i]!=-1) return dp[i];
    bool op1 = func(i+b[i]+1,b,mpp,dp);
    bool op2 = false;
    for(ll j=0;j<mpp[i].size();j++){
        op2 = op2 | func(mpp[i][j]+1,b,mpp,dp);
        if(op1|op2) break;
    }
    return dp[i] = (op1 | op2);
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> b(n);
    map<ll,vector<ll>> mpp;
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<n;i++){
        ll key = i - b[i];
        mpp[key].push_back(i);
    }
    vector<ll> dp(n+1,-1);
    bool ans = func(0,b,mpp,dp); 
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}