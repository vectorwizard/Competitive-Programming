#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
void dfs(int node,vector<int> &vis,vector<vector<int>> &adj1){
    vis[node] = 1;
    for(auto it:adj1[node]){
        if(vis[it]==0){
            dfs(it,vis,adj1);
        }
    }
}
void dfs_check(int node,vector<vector<int>> &adj,vector<int> &vis){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it]==0) dfs_check(it,adj,vis);
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            int x = s[j]-'0';
            if(x==1) adj[i][j] = 1;
        }
    }   
    set<pair<int,int>> edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            bool fl = true;
            if(adj[i][j]==1){
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    if(adj[i][k]==1 && adj[k][j]==1){
                        fl = false;
                        break;
                    }
                }
                if(fl==true && edges.count({j,i})>0){
                    cout<<"NO"<<endl;
                    return;
                }
                if(fl==true){
                    edges.insert({i,j});
                }
            }
        }
    }
    if(edges.size()!=n-1){
        cout<<"No"<<endl;
        return;
    }
    vector<vector<int>> adj1(n),adj2(n);
    for(auto it:edges){
        adj1[it.first].push_back(it.second);
        adj2[it.first].push_back(it.second);
        adj1[it.second].push_back(it.first);
    }
    vector<int> vis(n,0);
    dfs(0,vis,adj1);
    bool fl= true;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            fl = false;
            break;
        }
    }
    if(fl==false){
        cout<<"NO"<<endl;
        return;
    }
    vector<vector<int>> sample(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        sample[i][i] = 1;
    }
    for(int i=0;i<n;i++){
        vector<int> vis(n,0);
        dfs_check(i,adj2,vis);
        for(int j=0;j<n;j++){
            if(vis[j]==1) sample[i][j] = 1;
        }
    }
    if(sample!=adj){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(auto it:edges){
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }
} 
 
int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}