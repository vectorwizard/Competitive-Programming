#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {  
    ll n;
    cin>>n;
    vector<ll> r(n+1);
    for(ll i=1;i<=n;i++) cin>>r[i];
    vector<ll> indegree(n+1,0);
    for(ll i=1;i<=n;i++){
        indegree[r[i]]++;
    }
    queue<pair<ll,ll>> q;
    for(ll i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push({i,1});
        }
    }
    ll maxi = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        ll node = it.first;
        ll steps = it.second;
        maxi = max(steps,maxi);
        indegree[r[node]]--;
        if(indegree[r[node]]==0) q.push({r[node],steps+1});
    }
    cout<<maxi+2<<endl;
} 

int main() {
    fastio();
    ll t;
    cin>>t;
    while (t--) solve();
    return 0;
}
