#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
int n,m;
ll func(int ind,int prev,vector<int> &a,vector<vector<ll>> &dp){
    if(ind==n) return 1;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    if(ind==0){
        if(a[ind]!=0) return dp[ind][prev]=func(ind+1,a[ind],a,dp);
        ll ans = 0;
        for(int i=1;i<=m;i++){
            ans= (ans+func(ind+1,i,a,dp))%mod;
        }
        return dp[ind][prev]=ans;
    }
    if(a[ind]!=0 && abs(a[ind]-prev)>1) return dp[ind][prev]=0;
    if(a[ind]!=0) return dp[ind][prev]=func(ind+1,a[ind],a,dp);
    ll minus=0,eq=0,plus=0;
    if(prev>1) minus = func(ind+1,prev-1,a,dp)%mod;
    eq = func(ind+1,prev,a,dp)%mod;
    if(prev<m) plus = func(ind+1,prev+1,a,dp)%mod;
    return dp[ind][prev]=(minus+eq+plus)%mod;
}
void solve() {
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    ll ans = func(0,0,a,dp)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
