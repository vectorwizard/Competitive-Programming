#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<int> dr = {-1,0,1,0};
vector<int> dc = {0,1,0,-1};
string ds = "URDL";

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> p(n,vector<int>(m,-1));
    pair<int,int> start;
    pair<int,int> end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='.') grid[i][j] = 0;
            else if(ch=='#') grid[i][j] = 1;
            else if(ch=='A') start = {i,j};
            else end = {i,j};
        }
    }
    queue<pair<int,int>> q;
    bool found = false;
    vis[start.first][start.second] = 1;
    q.push({start.first,start.second});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int r = it.first;
        int c = it.second;
        if(r==end.first && c==end.second) found = true;
        for(int i=0;i<4;i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0 && grid[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
                p[nrow][ncol] = i;
            }
        }
    }
    if(found==false){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    string ans = "";
    pair<int,int> curr = end;
    while(curr!=start){
        ans+=ds[p[curr.first][curr.second]];
        curr = {curr.first-dr[p[curr.first][curr.second]],curr.second-dc[p[curr.first][curr.second]]};
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
