#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll func(ll ind,vector<ll> &a,vector<ll> &dp){
    ll n = a.size();
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    ll prev = func(ind-1,a,dp);
    ll take = 1e18,nottake = 1e18;
    if(a[ind]>=prev){
        nottake = min(a[ind],nottake);
    }
    if(ind>0){  
        prev = func(ind-2,a,dp);
        ll mini = min(a[ind-1]-1,(a[ind]+a[ind-1])/2);
        if(mini>=prev){
            ll next = a[ind]+a[ind-1]-mini;
            take = min(take,next);
        }
    }
    return dp[ind]=min(take,nottake);
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> dp(n+1,-1);
    ll ans = func(n-1,a,dp);
    if(ans>=1e18) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
