#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ll> costs;

void cal(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
    costs[1] = 0;
    while(!q.empty()){
        auto it = q.front();
        ll x = it.first;
        ll steps = it.second;
        q.pop();
        for(ll i=1;i<=x;i++){
            ll next = x + (x/i);
            if(next>1000) continue;
            if(costs[next]>steps+1){
                costs[next] = steps+1;
                q.push({next,steps+1});
            }
        }
    }
}

ll func(ll ind,vector<ll> &b,vector<ll> &c,ll k,vector<vector<ll>> &dp){
    ll n = b.size();
    if(ind==n) return 0;
    ll take = 0,nottake = 0;
    if(dp[ind][k]!=-1) return dp[ind][k];
    if(costs[b[ind]]<=k){
        take = c[ind] + func(ind+1,b,c,k-costs[b[ind]],dp);
    }
    nottake = func(ind+1,b,c,k,dp);
    return dp[ind][k]=max(take,nottake);
}

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> b(n);
    vector<ll> c(n);
    for(ll i=0;i<n;i++) cin>>b[i];
    for(ll i=0;i<n;i++) cin>>c[i];
    ll maxi = *max_element(costs.begin(),costs.end());
    maxi = maxi*n;
    k = min(k,maxi);
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
    ll ans = func(0,b,c,k,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    cin>>t;
    costs.assign(1001,1e9);
    costs[0] = 0;
    cal();
    while (t--) solve();
    return 0;
}