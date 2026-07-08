#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n;
ll func(int ind,vector<vector<int>> &projects,vector<ll> &dp){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    vector<int> dummy = {projects[ind][1],INT_MAX,INT_MAX};
    int idx = upper_bound(projects.begin(),projects.end(),dummy) - projects.begin();
    ll take = projects[ind][2] + func(idx,projects,dp);
    ll nottake = func(ind+1,projects,dp);
    return dp[ind]=max(take,nottake);
}
void solve() {
    cin>>n;
    vector<vector<int>> projects(n,vector<int>(3));
    for(int i=0;i<n;i++){
        int a,b,p;
        cin>>a>>b>>p;
        projects[i]={a,b,p};
    }
    sort(projects.begin(),projects.end());
    vector<ll> dp(n+1,-1);
    ll ans = func(0,projects,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
