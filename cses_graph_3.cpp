#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class DisjointSet{
public:
    vector<int> size,parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findupar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int upar_u = findupar(u);
        int upar_v = findupar(v);
        if(upar_u==upar_v) return;
        if(size[upar_u]<size[upar_v]){
            parent[upar_u] = upar_v;
            size[upar_v]+=size[upar_u];
        }
        else{
            parent[upar_v] = upar_u;
            size[upar_u]+=size[upar_v];
        }
    }
};

void solve() {
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    int comp = n;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(ds.findupar(u)!=ds.findupar(v)){
            ds.unionbysize(u,v);
            comp--;
        }
    }
    if(comp==1){
        cout<<0<<endl;
        return;
    }
    cout<<comp-1<<endl;
    for(int i=1;i<=n;i++){
        if(ds.findupar(i)!=ds.findupar(1)){
            ds.unionbysize(1,i);
            cout<<1<<" "<<i<<endl;
        }
    }
}

int main() {
    fastio();
    int t=1;
    while (t--) solve();
    return 0;
}
