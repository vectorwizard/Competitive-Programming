#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int func(int ind,int open,string &s1,string &s2, vector<vector<int>> &dp){
    int n = s1.size();
    if(ind==n){
        if(open==0) return 0;
        return 1e9;
    }
    if(dp[ind][open]!=-1) return dp[ind][open];
    int match = 1e9;
    int notmatch = 1e9;
    if(open==0){
        if(s1[ind]==s2[ind]){
            match = func(ind+1,0,s1,s2,dp);
        }
        else match = 1+func(ind+1,0,s1,s2,dp);
        notmatch = func(ind+1,1,s1,s2,dp);
    }
    else{
        if(s1[ind]==s1[ind-1] && s2[ind]==s2[ind-1]) notmatch = func(ind+1,0,s1,s2,dp);
        else if(s1[ind]==s1[ind-1] || s2[ind]==s2[ind-1]) notmatch = 1+func(ind+1,0,s1,s2,dp);
        else notmatch = 2+func(ind+1,0,s1,s2,dp);
    }
    return dp[ind][open]=min(match,notmatch);
}
void solve() {
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    int ans = func(0,0,s1,s2,dp);
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
