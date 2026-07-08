#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<char> vec = {'R','G','B'};
vector<vector<int>> path;
int func(int ind,int prev,string &s,vector<vector<int>> &dp){
    int n = s.size();
    if(ind == n){
        return 0;
    }
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int op1 = 1e9,op2 = 1e9,op3 = 1e9;
    if(ind==0){
        if(s[0]=='R') op1 = func(ind+1,0,s,dp);
        else op1 = 1+func(ind+1,0,s,dp);
        if(s[0]=='G') op2 = func(ind+1,1,s,dp);
        else op2 = 1+func(ind+1,1,s,dp);
        if(s[0]=='B') op3 = func(ind+1,2,s,dp);
        else op3 = 1+func(ind+1,2,s,dp);
    }
    else{
        if(prev!=0){
            if(s[ind]=='R') op1 = func(ind+1,0,s,dp);
            else op1 = 1+func(ind+1,0,s,dp);
        }
        if(prev!=1){
            if(s[ind]=='G') op2 = func(ind+1,1,s,dp);
            else op2 = 1+func(ind+1,1,s,dp);
        }
        if(prev!=2){
            if(s[ind]=='B') op3 = func(ind+1,2,s,dp);
            else op3 = 1+func(ind+1,2,s,dp);
        }
    }
    dp[ind][prev]=min(op1,min(op2,op3));
    if(dp[ind][prev]==op1) path[ind][prev] = 0;
    else if(dp[ind][prev]==op2) path[ind][prev] = 1;
    else path[ind][prev] = 2;
    return dp[ind][prev];
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    path.resize(n+1,vector<int>(3));
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    int ans = func(0,0,s,dp);
    cout<<ans<<endl;
    int x = path[0][0];
    int ind = 1;
    cout<<vec[x];
    while(ind<n){
        cout<<vec[path[ind][x]];
        x = path[ind][x];
        ind++;
    }
    cout<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
