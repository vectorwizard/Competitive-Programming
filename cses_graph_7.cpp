#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> dr = {-1,0,1,0};
vector<int> dc = {0,1,0,-1};
string dd = "URDL";
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> my_vis(n,vector<int>(m,0));
    vector<vector<int>> dir(n,vector<int>(m,-1));
    pair<int,int> start;
    int end_r = -1;
    int end_c = -1;
    queue<pair<int,pair<int,int>>> mons;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='.') grid[i][j] = 0;
            else if(ch=='#') grid[i][j] = 1;
            else if(ch=='A') start = {i,j};
            else {
                mons.push({0,{i,j}});
                vis[i][j] = 1;
            }
        }
    }
    vector<vector<int>> min_time(n,vector<int>(m,INT_MAX));
    while(!mons.empty()){
        auto it = mons.front();
        mons.pop();
        int time = it.first;
        int r = it.second.first;
        int c = it.second.second;
        min_time[r][c] = min(min_time[r][c],time);
        for(int i=0;i<4;i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                vis[nrow][ncol] = 1;
                mons.push({time+1,{nrow,ncol}});
            }
        }
    }
    my_vis[start.first][start.second] = 1;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{start.first,start.second}});
    bool found = false;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int time = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if(r==n-1 || c==m-1 || r==0 || c==0){
            found = true;
            end_r = r;
            end_c = c;
            break;
        }
        for(int i=0;i<4;i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && my_vis[nrow][ncol]==0 && grid[nrow][ncol]==0 && (time+1)<min_time[nrow][ncol]){
                dir[nrow][ncol] = i;
                my_vis[nrow][ncol] = 1;
                q.push({time+1,{nrow,ncol}});
            }
        }
    }
    if(found==false){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    string path = "";
    int curr_r = end_r;
    int curr_c = end_c;
    while(curr_r!=start.first || curr_c!=start.second){
        int x = dir[curr_r][curr_c];
        path += dd[x];
        curr_r = curr_r - dr[x];
        curr_c = curr_c - dc[x];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    cout<<path<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
