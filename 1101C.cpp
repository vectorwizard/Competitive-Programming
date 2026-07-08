#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll func(ll ind,ll tables,ll x,string &s,vector<vector<ll>> &dp){
    if(ind==-1){
        if(tables==0) return 0;
        else return -1e9;
    }
    if(tables<0) return -1e9;
    if(dp[ind][tables]!=-1) return dp[ind][tables];
    ll ans = func(ind-1,tables,x,s,dp);
    if(s[ind]=='I' || s[ind]=='A'){
        ans = max(ans,1+func(ind-1,tables-1,x,s,dp));
    }
    if(s[ind]=='A' || s[ind]=='E'){
        ll prev = func(ind-1,tables,x,s,dp);
        if(prev>=0 && prev<tables*x){
            ans = max(1+prev,ans);
        }
    }
    return dp[ind][tables]=ans;
}

void solve() {
    ll n,x,s;
    cin>>n>>x>>s;
    string st;
    cin>>st;
    ll ans = 0;
    vector<vector<ll>> dp(n+1,vector<ll>(x+1,-1));
    for(ll tables = 0;tables<=x;tables++){
        ans = max(ans,func(n-1,tables,s,st,dp));
    }
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}