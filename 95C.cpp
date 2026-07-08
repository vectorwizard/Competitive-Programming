#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int func(int ind,int turn,vector<int> &a,vector<vector<int>> &dp){
    int n = a.size();
    if(ind>=n){
        return 0;
    }
    if(dp[ind][turn]!=-1) return dp[ind][turn];
    int op1 = 1e9,op2 = 1e9;
    if(turn==0){
        op1 = a[ind] + func(ind+1,1,a,dp);
        if(ind<n-1) op2 = a[ind] + a[ind+1] + func(ind+2,1,a,dp);
    }
    else{
        op1 = func(ind+1,0,a,dp);
        if(ind<n-1) op2 = func(ind+2,0,a,dp);
    }
    return dp[ind][turn]=min(op1,op2);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+2,vector<int>(2,-1));
    int ans = func(0,0,a,dp);
    cout<<ans<<endl;
}
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}