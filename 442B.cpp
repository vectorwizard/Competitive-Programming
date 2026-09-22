#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const ll mod = 1e9 + 7;
vector<ll> fact(1e6+2,0);
void cal(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i=2;i<=1e6;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b%2==1){
        ans = (ans*a)%mod;
    }
    return ans%mod;
}

ll ncr(ll n,ll r){
    ll x = fact[n];
    ll y = fact[r];
    y = (y*fact[n-r])%mod;
    ll ans = (x * power(y,mod-2))%mod;
    return ans;
}

ll func(ll ind,ll op,string &s,vector<vector<ll>> &dp){
    ll n = s.size();
    if(ind==n){
        if(op==3) return 0;
        return 1e9;
    }
    if(dp[ind][op]!=-1) return dp[ind][op];
    ll mini = 1e9;
    if(op==0){
        mini = min(mini,1+func(ind+1,0,s,dp));
        mini = min(mini,1+func(ind+1,1,s,dp));
        mini = min(mini,1+func(ind+1,2,s,dp));
        mini = min(mini,1+func(ind+1,3,s,dp));
        if(s[ind]=='a') mini = min(mini,func(ind+1,0,s,dp));
        if(s[ind]=='a') mini = min(mini,func(ind+1,1,s,dp));
        if(s[ind]=='a') mini = min(mini,func(ind+1,2,s,dp));
        if(s[ind]=='a') mini = min(mini,func(ind+1,3,s,dp));
    }
    else if(op==1){
        mini = min(mini,1+func(ind+1,1,s,dp));
        mini = min(mini,1+func(ind+1,2,s,dp));
        mini = min(mini,1+func(ind+1,3,s,dp));
        if(s[ind]=='b') mini = min(mini,func(ind+1,1,s,dp));
        if(s[ind]=='b') mini = min(mini,func(ind+1,2,s,dp));
        if(s[ind]=='b') mini = min(mini,func(ind+1,3,s,dp));
    }
    else if(op==2){
        mini = min(mini,1+func(ind+1,2,s,dp));
        mini = min(mini,1+func(ind+1,3,s,dp));
        if(s[ind]=='a') mini = min(mini,func(ind+1,2,s,dp));
        if(s[ind]=='a') mini = min(mini,func(ind+1,3,s,dp));
    }
    else{
        mini = min(mini,1+func(ind+1,3,s,dp));
    }
    return dp[ind][op]=mini;
}

void solve() {
    string s;
    cin>>s;
    ll n = s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(4,-1));
    ll ans = min(func(0,0,s,dp),func(0,1,s,dp));
    ans = min(ans,func(0,2,s,dp));
    cout<<(n-ans)<<endl;
}

int main() {
    fastio();
    ll t=1;
    cal();
    // cin>>t;
    while (t--) solve();
    return 0;
}
