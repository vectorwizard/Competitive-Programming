#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind,vector<ll> &a,map<ll,vector<ll>> &mpp,vector<ll> &dp){
    ll n = a.size();
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    ll ch1 = 0;
    ll ch2 = 0;
    if(mpp[a[ind]][0]==ind){
        ch1 = (mpp[a[ind]][1]-mpp[a[ind]][0]+1)*(mpp[a[ind]][1]-mpp[a[ind]][0]+1) + func(mpp[a[ind]][1]+1,a,mpp,dp);
    }
    ch2 = 1 + func(ind+1,a,mpp,dp);
    return dp[ind] = max(ch1,ch2);
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(2*n);
    for(ll i=0;i<2*n;i++) cin>>a[i];
    map<ll,vector<ll>> mpp;
    for(ll i=0;i<2*n;i++){
        mpp[a[i]].push_back(i);
    }
    vector<ll> dp(2*n+1,-1); 
    ll ans = func(0,a,mpp,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}
