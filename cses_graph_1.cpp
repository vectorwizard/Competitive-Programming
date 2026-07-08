#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis){
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    vector<int> dr = {-1,0,1,0};
    vector<int> dc = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow = r + dr[i];
        int ncol = c + dc[i];
        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==0 && vis[nrow][ncol]==0){
            dfs(nrow,ncol,grid,vis);
        }
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0 && vis[i][j]==0){
                dfs(i,j,grid,vis);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
