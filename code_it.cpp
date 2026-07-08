#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int mod = 1e9+7;
long long dfs(int i,int j,vector<vector<int>> &grid,vector<vector<ll>> &dp){
    int n = grid.size();
    int m = grid[0].size();
    if(dp[i][j]!=-1) return dp[i][j];
    if(grid[i][j]==-1) return dp[i][j]=0;
    else if(i==n-1 && j==m-1) return dp[i][j]=1;
    else if(grid[i][j]==0){
        ll right = 0, down = 0;
        if(j+1<m) right = dfs(i,j+1,grid,dp)%mod;
        if(i+1<n) down = dfs(i+1,j,grid,dp)%mod;
        return dp[i][j]=(right+down)%mod;
    }
    else{
        ll right = 0, down = 0,exright=0,exdown=0;
        int k = grid[i][j];
        if(j+1<m) right = dfs(i,j+1,grid,dp)%mod;
        if(i+1<n) down = dfs(i+1,j,grid,dp)%mod;
        if(j+k<m) exright = dfs(i,j+k,grid,dp)%mod;
        if(i+k<n) exdown = dfs(i+k,j,grid,dp)%mod;
        return dp[i][j]=(right+down+exright+exdown)%mod;
    }
}
void solve() {
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int k=0;k<t;k++){
        int i,j,c;
        cin>>i>>j>>c;
        grid[i][j] = c;
    }
    vector<vector<ll>> dp(n,vector<ll>(m,-1));
    ll ans = dfs(0,0,grid,dp);
    cout<<ans%mod<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
