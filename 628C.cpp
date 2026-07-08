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
    vector<int> degree(n+1,0);
    vector<pair<int,int>> edges;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        degree[u]++;
        degree[v]++;
        edges.push_back({u,v});
    }
    bool fl = true;
    int node = -1;
    for(int i=1;i<=n;i++){
        if(degree[i]>=3){
            fl = false;
            node = i;
            break;
        }
    }
    if(fl){
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            cout<<cnt<<endl;
            cnt++;
        }
    }
    else{
        int cnt1 = 0;
        int cnt2 = 3;
        for(int i=0;i<n-1;i++){
            if(edges[i].first==node || edges[i].second==node){
                if(cnt1<3){
                    cout<<cnt1<<endl;
                    cnt1++;
                }
                else{
                    cout<<cnt2<<endl;
                    cnt2++;
                } 
            }
            else{
                cout<<cnt2<<endl;
                cnt2++;
            }
        }
    }
    cout<<endl;
}
 
int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}