#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u; cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n+1,0);
    q.push(1);
    vis[1] = 1; 
    int maxi = 0;
    int maxchildren=0;
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            int node = q.front(); q.pop();
            level.push_back(node);
            int children =0;
            for(auto it:adj[node]){
                if(vis[it]!=1){
                    q.push(it);
                    vis[it]=1;
                    children++;
                }
            }
            maxchildren = max(maxchildren,children);
        }
        maxi = max(maxi,size);
    }
    if(maxi==maxchildren){
        cout<<maxi+1<<endl;
    }
    else cout<<maxi<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
