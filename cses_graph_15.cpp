#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<vector<int>> adj;
void solve() {
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vector<int> indegree(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    if(ans.size()<n){
        cout<<"IMPOSSIBLE"<<endl;
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
