#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int mod = 1e9 + 7;
vector<int> r_child;
vector<int> l_child;
vector<int> cost;
vector<int> ans;
void cal(int node){
    if(l_child[node]==0 && r_child[node]==0){
        cost[node] = 1;
        return;
    } 
    cal(l_child[node]);
    cal(r_child[node]);
    cost[node] = (3LL + cost[l_child[node]] + cost[r_child[node]])%mod;
}
void dfs(int node,int total){
    if(l_child[node]==0 && r_child[node]==0){
        ans[node] = (total + cost[node])%mod;
        return;
    }
    ans[node] = (total+cost[node])%mod;
    dfs(l_child[node],ans[node]);
    dfs(r_child[node],ans[node]);
}
void solve() {
    int n;
    cin>>n;
    l_child.resize(n+1);
    r_child.resize(n+1);
    cost.resize(n+1);
    ans.resize(n+1);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        l_child[i] = l;
        r_child[i] = r;
    }
    cal(1);
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}  

int main() {
    fastio();
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
