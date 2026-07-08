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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    set<int> st;
    vector<ll> dist(n+1,-1);
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    if(st.count(1)>0){
        dist[1] = 1;
    }
    else dist[1] = -1;
    queue<pair<int,int>> q;
    for(auto it:st){
        if(it==1) continue;
        dist[it] = 1;
        q.push({it,1});
    }
    if(st.count(1)) st.erase(1);
    while(!q.empty()){
        auto it = q.front(); q.pop();
        int node = it.first;
        int steps = it.second;
        for(auto it:st){
            ll adjnode = 1LL*node*it;
            if(adjnode>n) break;
            if(dist[adjnode]==-1){
                dist[adjnode] = steps+1;
                q.push({adjnode,dist[adjnode]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}