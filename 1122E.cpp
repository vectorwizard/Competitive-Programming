#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> spf;
ll m = 2e5;
vector<vector<ll>> primes;
void sieve(){
    spf.assign(m+1,0);
    for(ll i=0;i<=m;i++) spf[i] = i;
    for(ll i=2;i*i<=m;i++){
        if(spf[i]==i){
            for(ll j=i*i;j<=m;j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
}

ll func(ll n,ll k,vector<ll> &dp){
    if(n<=k) return 0;
    ll ans = 1e18;
    if(dp[n]!=-1) return dp[n];
    for(auto it:primes[n]){
        ll cnt = it;
        ll res = n/it;
        ans = min(ans,1 + cnt*func(res,k,dp));
    }
    return dp[n] = ans;
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll ans = 0;
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> dp(n+1,-1);
    for(ll i=0;i<n;i++){
        ll x = a[i];
        if(x<=k) continue;
        ans+=func(x,k,dp);
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    sieve();
    primes.assign(m+1,vector<ll>());
    for(ll i=2;i<=m;i++){
        ll x = i;
        unordered_set<ll> st;
        while(x>1){
            st.insert(spf[x]);
            x/=spf[x];
        }
        for(auto it:st) primes[i].push_back(it);
    }
    while (t--) solve();
    return 0;
}