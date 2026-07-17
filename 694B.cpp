#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    ll sum = 0;
    queue<pair<ll,ll>> q;
    for(ll i=0;i<n;i++){
        q.push({a[i],1});
        sum+=a[i];
    }
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        ll nu = it.first;
        ll cnt = it.second;
        if((nu%x)!=0) break;
        q.push({nu/x,(cnt*x)});
        sum+=(nu*cnt);
    }
    cout<<sum<<endl;
} 

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
