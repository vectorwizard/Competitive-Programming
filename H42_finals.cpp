#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll func(ll ind,ll m,ll k,vector<ll> &a,vector<ll> &b,vector<vector<ll>> &dp){
    ll n = a.size();
    if(ind==n-1){
        return 0;
    }
    if(dp[ind][m]!=-1) return dp[ind][m];
    ll web = 1e18;
    ll run = a[ind] + func(ind+1,m,k,a,b,dp);
    if(m>0){
        for(ll i=1;i<=k;i++){
            if(ind+i>=n) break;
            web = min(web,b[ind]+b[ind+i]+func(ind+i,m-1,k,a,b,dp));
        }
    }
    return dp[ind][m]=min(web,run);
}
void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>b[i];
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    for(ll i=0;i<=m;i++) dp[n-1][i] = 0;
    for(ll rem = 0;rem<=m;rem++){
        deque<pair<ll,ll>> dq;
        for(ll ind = n-2;ind>=0;ind--){
            ll web = 1e18;
            ll run = a[ind] + dp[ind+1][rem];
            if(rem>0){
                ll j = ind+1;
                ll val = b[j] + dp[j][rem-1];
                while(!dq.empty() && dq.back().first>=val){
                    dq.pop_back();
                }
                dq.push_back({val,j});
                while(!dq.empty() && dq.front().second>(ind+k)){
                    dq.pop_front();
                }
                if(!dq.empty()){
                    web = b[ind] + dq.front().first;
                }
            }
            dp[ind][rem] = min(run,web);
        }
    }
    ll ans = dp[0][m];
    cout<<ans<<endl;
}  

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
