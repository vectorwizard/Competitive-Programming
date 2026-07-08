#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<int> ans;
void dfs(int node,vector<vector<int>> &adj,vector<int> &c){
    int x = 0;
    for(auto it:adj[node]){
        x+=c[it];
        dfs(it,adj,c);
    }
    if(c[node]==1 && x==adj[node].size()) ans.push_back(node);
}
void solve() {
    int n;
    cin>>n;
    ans.clear();
    int root = 0;
    vector<vector<int>> adj(n+1);
    vector<int> c(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a!=-1) adj[a].push_back(i);
        if(a==-1) root = i;
        c[i] = b;
    }
    dfs(root,adj,c);
    sort(ans.begin(),ans.end());
    if(ans.size()==0){
        cout<<-1<<endl;
        return;
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}   

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
