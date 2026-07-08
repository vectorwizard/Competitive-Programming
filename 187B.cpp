#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
bool check(ll x){
    return x<=9;
}
ll func(ll ind,ll temp,string &s,vector<vector<ll>> &dp){
    ll n = s.size();
    if(ind==n){
        if(check(temp)) return 0;
        return 20;
    }
    if(dp[ind][temp]!=-1) return dp[ind][temp];
    ll mini = 20;
    for(ll i=0;i<10;i++){
        if(ind==0 && i==0) continue;
        if((s[ind]-'0')==i) mini = min(mini,func(ind+1,temp+i,s,dp));
        else mini = min(mini,1+func(ind+1,temp+i,s,dp));
    }
    return dp[ind][temp]=mini;
}
void solve() {
    ll x;
    cin>>x;
    string s = to_string(x);
    ll n = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(200,-1));
    ll ans = func(0,0, s,dp);
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}