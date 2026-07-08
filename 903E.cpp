#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int func(int ind,vector<int> &a,vector<int> &dp){
    int n = a.size();
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int mini = 1e9,notdel=1e9;
    int del = 1+func(ind+1,a,dp);
    if((ind+a[ind]+1)<=n) notdel = func(ind+a[ind]+1,a,dp);
    return dp[ind]=min(del,notdel);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> dp(n+1,-1);
    int ans = func(0,a,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
