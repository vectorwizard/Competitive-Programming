#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
ll func(int i,int j,int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(i==n-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    ll right =0,down = 0;
    if(j<n-1 && grid[i][j+1]!=1) right = func(i,j+1,n,grid,dp)%mod;
    if(i<n-1 && grid[i+1][j]!=1) down = func(i+1,j,n,grid,dp)%mod;
    return dp[i][j] = (right+down)%mod;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            if(ch=='.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    if(grid[0][0]==1 || grid[n-1][n-1]==1){
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    ll ans = func(0,0,n,grid,dp)%mod;
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
