#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
ll func(int n,vector<ll> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    string s = to_string(n);
    ll ans = INT_MAX, ans1 = INT_MAX;
    for(int i=0;i<s.size();i++){
        int number = s[i]-'0';
        if(number!=0)  ans1 = 1+func(n-number,dp);
        ans = min(ans,ans1);
    }
    return dp[n]=ans;
}
void solve() {
    int n,x;
    cin>>n;
    vector<ll> dp(n+1,-1);
    ll ans = func(n,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
