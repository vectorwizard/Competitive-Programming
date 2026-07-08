#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
int total_sum,n;
int func(int i,int sum,vector<vector<int>> &dp){
    if(sum==(total_sum-sum)) return 1;
    if(i==n) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int take = func(i+1,sum+i,dp)%mod;
    int nottake = func(i+1,sum,dp)%mod;
    return dp[i][sum]=(take+nottake)%mod;
}
void solve() {
    cin>>n;
    total_sum = n*(n+1)/2;
    vector<vector<int>> dp(n+1,vector<int>(total_sum+1,-1));
    int ways = func(1,0,dp)%mod;
    cout<<ways<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
