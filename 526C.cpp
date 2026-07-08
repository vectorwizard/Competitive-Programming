#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const ll mod = 1e9 + 7;
ll func(ll ind,vector<ll> &segments,vector<ll> &dp){
    ll n = segments.size();
    if(ind==n) return 1;
    if(dp[ind]!=-1) return dp[ind];
    ll take = (segments[ind] * func(ind+1,segments,dp))%mod;
    ll nottake = func(ind+1,segments,dp)%mod;
    return dp[ind] = (take + nottake)%mod;
}
void solve() {
    string s;
    cin>>s;
    ll n = s.size();
    vector<ll> segments;
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        if(s[i]=='a') cnt++;
        else if(s[i]=='b'){
            if(cnt>0) segments.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt>0) segments.push_back(cnt);
    if(segments.size()==0){
        cout<<0<<endl;
        return;
    }
    ll m = segments.size();
    vector<ll> dp(m+1,-1); 
    ll ans = func(0,segments,dp);
    cout<<((ans-1)%mod)<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
