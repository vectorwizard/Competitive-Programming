#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int func(int ind1,int ind2,string &s1,string &s2,int n,int m,vector<vector<int>> &dp){
    if(ind1==n && ind2==m) return 0;
    if(ind1==n) return m-ind2;
    if(ind2==m) return n-ind1;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    if(s1[ind1]==s2[ind2]) return func(ind1+1,ind2+1,s1,s2,n,m,dp);
    int ch1 = 1+func(ind1+1,ind2+1,s1,s2,n,m,dp);
    int ch2 = 1+func(ind1,ind2+1,s1,s2,n,m,dp);
    int ch3 = 1+func(ind1+1,ind2,s1,s2,n,m,dp);
    return dp[ind1][ind2]=min(ch1,min(ch2,ch3));
}
void solve() {
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans = func(0,0,s1,s2,n,m,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
