#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int func(int ind,int prev,vector<int> &a,vector<vector<int>> &dp){
    int n = a.size();
    if(ind==n) return 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int cant = 7;
    if(prev!=7) cant = 7-prev;
    int mini = INT_MAX;
    for(int i=1;i<=6;i++){
        if(i==cant) continue;
        if(i==prev) continue;
        int x;
        if(i==a[ind]) x = func(ind+1,i,a,dp);
        else x = 1 + func(ind+1,i,a,dp);
        mini = min(mini,x);
    }
    return dp[ind][prev]=mini;
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(8,-1));
    int ans = func(0,7,a,dp);
    cout<<ans<<endl;
}  

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
