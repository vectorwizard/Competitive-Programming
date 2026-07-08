#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int func(int ind,int ch,string &s,vector<vector<int>> &dp){
    int n = s.size();
    if(ind==n){
        return 0;
    }
    if(dp[ind][ch]!=-1) return dp[ind][ch]; 
    int ans = 1e9;
    if(s[ind]=='4'){
        ans = 1+func(ind+1,ch,s,dp);
    }
    else if(s[ind]=='2'){
        if(ch == 0){
            ans = func(ind+1,0,s,dp);
        }
        else ans = 1+func(ind+1,1,s,dp);
    }
    else{
        if(ch==1) ans = func(ind+1,ch,s,dp);
        else{
            int x = 1+func(ind+1,0,s,dp);
            int y = func(ind+1,1,s,dp);
            ans = min(x,y);
        }
    }
    return dp[ind][ch]=ans;
}

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    int ans = func(0,0,s,dp);
    cout<<ans<<endl;
}   

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
