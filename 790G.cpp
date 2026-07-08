#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
string s;
int ans;
int dfs(int node,vector<vector<int>> &adj){
    int temp = 0;
    if(s[node-1]=='B') temp = 1;
    else temp= -1;
    for(auto it:adj[node]){
        temp+=dfs(it,adj);
    }
    if(temp==0) ans++;
    return temp;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++){
        int par;
        cin>>par;
        adj[par].push_back(i);
    }
    ans = 0;
    cin>>s;
    dfs(1,adj);
    cout<<ans<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
