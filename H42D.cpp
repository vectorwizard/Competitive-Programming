#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,m,t,q;
    cin>>n>>m>>t>>q;
    map<pair<ll,ll>,ll> parent;
    vector<vector<ll>> fruits(t+1);
    for(ll i=1;i<=t;i++){
        ll r,c,v;
        cin>>r>>c>>v;
        fruits[i] = {r,c,v};
    }
    unordered_map<ll,ll> threshold;
    for(ll p=1;p<=q;p++){
        ll r1,r2,c1,c2,x;
        cin>>r1>>r2>>c1>>c2>>x;
        threshold[p] = x;
        for(ll i = r1;i<=r2;i++){
            for(ll j=c1;j<=c2;j++){
                parent[{i,j}] = p;
            }
        }
    }
    vector<ll> ans(q+1,-1);
    for(int i=1;i<=t;i++){
        ll r,c,v;
        r = fruits[i][0];
        c = fruits[i][1];
        v = fruits[i][2];
        ll par = parent[{r,c}];
        if(threshold.find(par)==threshold.end()) continue;
        threshold[par]-=v;
        if(threshold[par]<=0){
            ans[par] = i;
            threshold.erase(par);
        }
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}  

int main() {
    fastio();
    ll t=1;
    while (t--) solve();
    return 0;
}
