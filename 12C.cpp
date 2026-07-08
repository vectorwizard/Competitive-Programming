#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<vector<int>> best;
int func(int ind,int prev,string &s,vector<vector<int>> &dp){
    int n = s.size();
    if(ind==n) return 0;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int x = s[ind]-'a';
    int ans = 1e9;
    if(x!=prev) {
        ans = func(ind+1,x,s,dp);
        best[ind][prev] = x;
    }
    for(int i=0;i<26;i++){
        if(i==x) continue;
        int y = func(ind+1,i,s,dp);
        if((1+y)<ans){
            ans = 1+y;
            best[ind][prev] = i;
        }
    }
    return dp[ind][prev]=ans;
}
void solve() {
    string s;
    cin>>s;
    int n = s.size();
    best.assign(n+1,vector<int>(27,-1));
    vector<vector<int>> dp(n+1,vector<int>(27,-1));
    int ans = func(0,26,s,dp);
    int prev=26;
    string st = "";
    for(int i=0;i<n;i++){
        char ch = 'a' + best[i][prev];
        st+=ch;
        prev = best[i][prev];
    }
    cout<<st<<endl;
}

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
