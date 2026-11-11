#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 998244353;

ll func(ll ind,ll ptp,ll p,string &s,vector<vector<vector<ll>>> &dp){
    ll n = s.size();
    if(ind==n) return 1;
    if(dp[ind][ptp][p]!=-1) return dp[ind][ptp][p];
    ll ans = 0;
    if(s[ind]=='?'){
        bool fl0 = true;
        bool fl1 = true;
        if((ptp==0 && p==0) || (ptp==0 && p==1)){
            fl0 = false;
        }
        if((ptp==1 && p==1) || (ptp==1 && p==0)){
            fl1 = false;
        }
        if(fl0) ans+=func(ind+1,p,0,s,dp);
        if(fl1) ans+=func(ind+1,p,1,s,dp);
    }
    else{
        ll x = s[ind] - '0';
        if(x==0 && ((ptp==0 && p==0) || (ptp==0 && p==1))){
            ans = 0;
        }
        else if(x==1 && ((ptp==1 && p==1) || (ptp==1 && p==0))){
            ans = 0;
        }
        else ans+=func(ind+1,p,s[ind]-'0',s,dp);
    }
    return dp[ind][ptp][p] = ans%mod;
}

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = 0;
    vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(3,vector<ll>(3,-1)));
    if(s[0]=='?'){
        ans+=func(1,2,0,s,dp);
        ans+=func(1,2,1,s,dp);
    }
    else{
        ans+=func(0,2,2,s,dp);
    }
    cout<<ans%mod<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    while (t--) solve();
    return 0;
}